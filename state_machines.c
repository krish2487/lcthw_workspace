#include <stdio.h>
#include <stdlib.h>

int entry_state(void);
int foo_state(void);
int bar_state(void);
int exit_state(void);


/* array and enum below must be in sync! */
// They must be in sync because the state_code enum is used as the index to lookup the actual state in the state[] array.
// So, entry -> entry_state, foo -> foo_state, bar -> bar_state, end -> exit_state 
int (* state[])(void) = { entry_state, foo_state, bar_state, exit_state};
enum state_codes { entry, foo, bar, end};

enum ret_codes { ok, fail, repeat};
struct transition {
    enum state_codes src_state;
    enum ret_codes   ret_code;
    enum state_codes dst_state;
};
/* transitions from end state aren't needed */
struct transition state_transitions[] = {
    {entry, ok,     foo},
    {entry, fail,   end},
    {foo,   ok,     bar},
    {foo,   fail,   end},
    {foo,   repeat, foo},
    {bar,   ok,     end},
    {bar,   fail,   end},
    {bar,   repeat, foo}};
    
enum state_codes lookup_transitions(enum state_codes, enum ret_codes);


int main(int argc, char *argv[]) {
    enum state_codes cur_state = entry;
    enum ret_codes rc;
    int (* state_fun)(void);

    for (;;) {
        state_fun = state[cur_state];
        rc = state_fun();
        if (end == cur_state)
            break;
        cur_state = lookup_transitions(cur_state, rc);
    }

    return EXIT_SUCCESS;
}

/*
 * lookup_transition() function has time complexity of class O(n).
 * We can optimize it.
 * */
enum state_codes
lookup_transitions(enum state_codes cur_state, enum ret_codes rc)
{
#if 0
    switch (cur_state) {
        case entry:
            cur_state = ((rc == ok) ? (foo) : (end));
            break;
        case foo:
            cur_state = ((rc == ok) ? (bar) : ((rc == fail) ? (end) : (foo)));
            break;
        default:
            cur_state = ((rc == ok) ? (end) : ((rc == fail) ? (end) : (foo)));
            break;
    }

    return cur_state;
#else
    char arr_size = (sizeof(state_transitions) / sizeof(state_transitions[0])); /* This can be shifted to main function to avoid redundant job. */
    char count;

    for (count = 0; count < arr_size; count++) {
        if ((state_transitions[count].src_state == cur_state) && (state_transitions[count].ret_code == rc)) {
            return (state_transitions[count].dst_state);
        }
    }
#endif
}

int entry_state(void)
{
    int st;
    enum ret_codes rc;

    printf("YOU ARE IN ENTRY STATE.\nEnter 0/1: ");

    scanf("%d", &st);

    rc = ((st == 1) ? (fail) : (ok));
    return rc;
}

int foo_state(void)
{
    int st;
    enum ret_codes rc;

    printf("YOU ARE IN FOO STATE.\nEnter 0/1/2: ");

    scanf("%d", &st);

    rc = ((st == 0) ? (ok) : ((st == 2) ? (repeat) : (fail)));
    return rc;
}

int bar_state(void)
{
    int st;
    enum ret_codes rc;

    printf("YOU ARE IN BAR STATE.\nEnter 0/1/2: ");

    scanf("%d", &st);

    rc = ((st == 0) ? (ok) : ((st == 2) ? (repeat) : (fail)));
    return rc;
}

int exit_state(void)
{
    printf("YOU ARE IN EXIT STATE.\n");

    exit(EXIT_SUCCESS);
}