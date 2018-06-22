/* Define the states and events. If your state machine program has multiple
source files, you would probably want to put these definitions in an "include"
file and #include it in each source file. This is because the action
procedures need to update current_state, and so need access to the state
definitions. */
enum states { STATE_1, STATE_2, STATE_3, MAX_STATES } current_state;
enum events { EVENT_1, EVENT_2, MAX_EVENTS } new_event;
/* Provide the fuction prototypes for each action procedure. In a real
program, you might have a separate source file for the action procedures of
each state. Then you could create a .h file for each of the source files,
and put the function prototypes for the source file in the .h file. Instead
of listing the prototypes here, you would just #include the .h files. */
void action_s1_e1 (void);
void action_s1_e2 (void);
void action_s2_e1 (void);
void action_s2_e2 (void);
void action_s3_e1 (void);
void action_s3_e2 (void);
enum events get_new_event (void);
/* Define the state/event lookup table. The state/event order must be the
same as the enum definitions. Also, the arrays must be completely filled -
don't leave out any events/states. If a particular event should be ignored in
a particular state, just call a "do-nothing" function. */
void (*const state_table [MAX_STATES][MAX_EVENTS]) (void) = {
    { action_s1_e1, action_s1_e2 }, /* procedures for state 1 */
    { action_s2_e1, action_s2_e2 }, /* procedures for state 2 */
    { action_s3_e1, action_s3_e2 }  /* procedures for state 3 */
};
/* This is the heart of the state machine - where you execute the proper
action procedure based on the new event you have to process and your current
state. It's important to make sure the new event and current state are
valid, because unlike "switch" statements, the lookup table method has no
"default" case to catch out-of-range values. With a lookup table,
out-of-range values cause the program to crash! */
void main (void)
{
    new_event = get_new_event (); /* get the next event to process */
    for(;;)
    {
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
    /* do some processing here */
    printf("Current State is %d\n, Trigger Event is %d", current_state, new_event);
    current_state = STATE_2; /* set new state, if necessary */
}
void action_s1_e2 (void) {
	printf("Current State is %d\n, Trigger Event is %d", current_state, new_event);
    current_state = STATE_1; /* set new state, if necessary */
}  /* other action procedures */
void action_s2_e1 (void) {
	printf("Current State is %d\n, Trigger Event is %d", current_state, new_event);
    current_state = STATE_3; /* set new state, if necessary */
}
void action_s2_e2 (void) {
	printf("Current State is %d\n, Trigger Event is %d", current_state, new_event);
    current_state = STATE_2; /* set new state, if necessary */
}
void action_s3_e1 (void) {
	printf("Current State is %d\n, Trigger Event is %d", current_state, new_event);
    current_state = STATE_1; /* set new state, if necessary */
}
void action_s3_e2 (void) {
	printf("Current State is %d\n, Trigger Event is %d", current_state, new_event);
    current_state = STATE_3; /* set new state, if necessary */
}
/* Return the next event to process - how this works depends on your
application. */
enum events get_new_event (void)
{
    return EVENT_1;
}

// #include <stdio.h>

// enum States { IDLE=0, PRINT_NUMBERS, PRINT_ALPHABET, MAX_STATES} CURRENT_STATE;
// enum Events { PRESSED_A = 0, PRESSED_N, MAX_EVENTS} TRIGGER_EVENT;

// void ACTION_IDLE_PRESSED_A ( void);
// void ACTION_IDLE_PRESSED_N ( void);
// void ACTION_PRINT_NUMBERS_PRESSED_A ( void);
// void ACTION_PRINT_NUMBERS_PRESSED_N ( void);
// void ACTION_PRINT_ALPHABET_PRESSED_A ( void);
// void ACTION_PRINT_ALPHABET_PRESSED_N ( void);

// enum Events get_trigger_event (void);

// void (*const state_table [MAX_STATES][MAX_EVENTS])(void)
// {
// 	{ACTION_IDLE_PRESSED_A, ACTION_IDLE_PRESSED_N},
// 	{ACTION_PRINT_NUMBERS_PRESSED_A, ACTION_PRINT_NUMERS_PRESSED_N},
// 	{ACTION_PRINT_ALPHABET_PRESSED_A, ACTION_PRINT_ALPHABET_PRESSED_N}
// };

// void main(int argc, char const *argv[])
// {
// 	/* code */
// 	new_event = get_trigger_event();


// }
