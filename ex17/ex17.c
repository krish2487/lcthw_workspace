#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

//Standard C library functions return a error code on exit.
//die uses these to print the error with a custom error message
void die(const char *message)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR: %s\n", message);
	}
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
	{
		die("Failed to load database");
	}
}

struct Connection *Database_open(const char *filename, char mode)
{
	//Create a structure pointer conn of type Connection and 
	//and allocate memory of sizeof(struct Connection)
	struct  Connection *conn = malloc(sizeof(struct Connection));

	//If malloc is unable to allocate memory !conn will be non zero
	if(!conn)
	{
		die("Memory error");
	}

	//allocates memory of sizeof(struct Database) to conn structure
	//member db
	conn->db = malloc(sizeof(struct Database));
	//Again if malloc is unable to allocate memory, exits with an error code
	if(!conn->db)
	{
		die("Memory Error");
	}

	if(mode == 'c')
	{
		conn->file = fopen(filename, "w");
	}
	else
	{
		conn->file = fopen(filename,"r+");
	}
		if(!conn->file)
		{
			die("Failed to open file");
		}

	return conn;
}

void Database_close(struct Connection *conn)
{
	//Closes the connection to file,
	//frees the memory allocated to 
	//the structure conn and structure db
	if(conn)
	{
		if(conn->file)
		{
			fclose(conn->file);
		}
		if(conn->db)
		{
			free(conn->db);
		}

		free(conn);
	}
}

//Called after every database access operation
//Writes the previous operation to the file
//and flushes the changes to the file.
void Database_write(struct Connection *conn)
{

	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die("Failed to write Database");

	rc = fflush(conn->file);
	if(rc == -1)
		die("Cannot flush Database");
}


void Database_create(struct Connection *conn)
{
	int i=0;
	//Creates an array of size MAX_ROWS 
	//of structure Address, initializes the
	//id and set members to i and 0 respectively
	//then assigns each respective addr structure to 
	//the conn-db-rows[i] parameter passed in
	for(i=0; i < MAX_ROWS; i++)
	{
		struct Address addr = { .id = i, .set = 0};

		conn->db->rows[i]= addr;
	}
}

void Database_set( struct Connection *conn, int id, const char *name, const char *email)
{
	//Creates a structure addr of type Address and points it to 
	//conn->db->rows[id]
	//if the specified member is set then aborts the program
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
	{
		die("Already set, delete it first");
	}
	//If the member is not set then the following step sets it.
	addr->set = 1;

	//WARNING: bug, read "How to break it" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	//demonstarte the strncopy bug
	if(!res)
		die("Name copy failed!");

	res = strncpy(addr->email, email, MAX_DATA);
	if(!res)
		die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set)
	{
		Address_print(addr);
	}
	else
	{
		die("ID is not set");
	}
}

void Database_delete( struct Connection *conn, int id)
{
	//Creates a structure of Address and sets id and set fields.
	struct Address addr = {.id = id, .set = 0};
	//copies the structures addr to the passed in parameter conn
	conn->db->rows[id] = addr;
}

void Database_list ( struct Connection *conn)
{
	int i=0;
	struct Database *db = conn->db;
	for(i=0;i < MAX_ROWS; i++)
	{
		struct Address *cur = &db->rows[i];

		if(cur->set)
		{
			Address_print(cur);
		} 
	}
}


int main(int argc, char const *argv[])
{

	if( argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id =0;

	if(argc> 3) 
		id = atoi(argv[3]);
	if(id >= MAX_ROWS)
		die("There is not that many records");

	switch(action)
	{
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc != 4)
				die("Need an id to get.");

			Database_get(conn, id);
			break;
		case 's':
			if(argc != 6)
				die("Need id, name, email to set");

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if(argc != 4 )
				die("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return 0;

}