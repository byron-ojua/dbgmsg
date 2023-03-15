#include "header.h"

int main(int argc, char *argv[]){
    // Init dbgMsger to a new debugMessenger using names from names array
    char names[][50] = {{"Group 1"}, {"Group 2"}, {"Group 3"}, {"Group 4"}};
    struct debugMessenger dbgMsger = debugMessenger(names, sizeof(names)/sizeof(names[0]));
    
    // Redirect strerr back to terminal
    freopen("/dev/tty", "w", stderr);

    // Print messages to stdout
    printf("Hello from printf!\n");
    prtDbgMsg("Hello from standard prtDbgMsg!\n", stdout);

    // Redirect debug messages to stderr
    dbgSetOutput(&dbgMsger, stderr);

    // Enable first debug group
    enblDbgGp(1, &dbgMsger);
    
    // Print message if group 1 is enabled
    prtDbgMsgGp("I am in group 1\n", 1, &dbgMsger);

    // Disable group 1
    dsblDbgGp(1, &dbgMsger);

    // Enable override. All debug messages should print regardless if group status
    enblDbgOride(&dbgMsger);

    // Print message with override
    prtDbgMsgGp("I am in group 1\n", 1, &dbgMsger);

    // Free memory used by debugMessenger
    freeDbg(&dbgMsger);
    return EXIT_SUCCESS;
}
