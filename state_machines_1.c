#include <stdio.h>
/* Define the states and events. If your state machine program has multiple
source files, you would probably want to put these definitions in an "include"
file and #include it in each source file. This is because the action
procedures need to update current_state, and so need access to the state
definitions. */
enum states { STATE_IDLE, STATE_PRINT_ALPHA, STATE_PRINT_NUM, MAX_STATES } current_state;
enum events { EVENT_NONE, EVENT_PRESS_A, EVENT_PRESS_N, MAX_EVENTS } new_event;
/* Provide the fuction prototypes for each action procedure. In a real
program, you might have a separate source file for the action procedures of
each state. Then you could create a .h file for each of the source files,
and put the function prototypes for the source file in the .h file. Instead
of listing the prototypes here, you would just #include the .h files. */
void action_s1_e1 (void);
void action_s1_e2 (void);
void action_s1_e3 (void);
void action_s2_e1 (void);
void action_s2_e2 (void);
void action_s2_e3 (void);
void action_s3_e1 (void);
void action_s3_e2 (void);
void action_s3_e3 (void);
enum events get_new_event (void);
/* Define the state/event lookup table. The state/event order must be the
same as the enum definitions. Also, the arrays must be completely filled -
don't leave out any events/states. If a particular event should be ignored in
a particular state, just call a "do-nothing" function. */
void (*const state_table [MAX_STATES][MAX_EVENTS]) (void) = {
    { action_s1_e1, action_s1_e2, action_s1_e3 }, /* procedures for state 1 */
    { action_s2_e1, action_s2_e2, action_s2_e3 }, /* procedures for state 2 */
    { action_s3_e1, action_s3_e2, action_s3_e3 }  /* procedures for state 3 */
};
/* This is the heart of the state machine - where you execute the proper
action procedure based on the new event you have to process and your current
state. It's important to make sure the new event and current state are
valid, because unlike "switch" statements, the lookup table method has no
"default" case to catch out-of-range values. With a lookup table,
out-of-range values cause the program to crash! */
void main (void)
{
    for(;;)
    {
    new_event = get_new_event (); /* get the next event to process */
    if (((new_event >= 0) && (new_event < MAX_EVENTS))
    && ((current_state >= 0) && (current_state < MAX_STATES))) {
        state_table [current_state][new_event] (); /* call the action procedure */
    } else {
        /* invalid event/state - handle appropriately */
    }
	}

}
/* In an action procedure, you do whatever processing is required for the
particular event in the particular state. Among other things, you might have
to set a new state. */
void action_s1_e1 (void)
{
    printf("Present State is %d\n", current_state);
    current_state = STATE_IDLE;
}
void action_s1_e2 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_IDLE;

}  /* other action procedures */
void action_s1_e3 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_IDLE;

}  /* other action procedures */
void action_s2_e1 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_PRINT_ALPHA;

}
void action_s2_e2 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_PRINT_ALPHA;

}
void action_s2_e3 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_PRINT_ALPHA;

}
void action_s3_e1 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_PRINT_NUM;

}
void action_s3_e2 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_PRINT_NUM;

}
void action_s3_e3 (void) {
    printf("Present State is %d\n", current_state);
    current_state = STATE_PRINT_NUM;

}
/* Return the next event to process - how this works depends on your
application. */
enum events get_new_event (void)
{
    char* input;
    printf("Enter A or N\n");
    scanf("%s", &input);
    printf("You entered %c\n",input);
    if (input == 'A' || input == 'a')
    {
        current_state = STATE_PRINT_ALPHA;
        return EVENT_PRESS_A;
    }
    else if (input == 'N' || input == 'n')
    {
        current_state = STATE_PRINT_NUM;
        return EVENT_PRESS_N;
    }
    else if (input == "\r\n")
    {
        current_state = STATE_IDLE;
        return EVENT_NONE;
    }

current_state = STATE_IDLE;
return EVENT_NONE;

}