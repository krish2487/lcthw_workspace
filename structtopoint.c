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

// A structure, Database, containing an array of structures (rows) of type Address
struct Database {
	struct Address rows[MAX_ROWS];
};

// A structure, connection, containing a pointer to a file, and a pointer to a structure of type database.
struct Connection {
	FILE *file;
	struct Database *db;
};

int main(int argc, char const *argv[])
{
	struct Connection *p_conn, conn;
	struct Database db;
	struct Address *p_arradd;
	//To access the address and database within a member of struct Connection
	// create pointers or members of the respective structures connection, database and address
	// and point them to the structures. 
	p_conn = &conn;
	p_conn->db = &db;
	// p_add = (p_conn->db->rows);
	p_conn->db->rows[0].id = 123;
	// p_arradd = &(p_conn->db->rows);
	printf("ID : %d\n", p_conn->db->rows[0].id);

}