#include "header.h"

int main(int argc, char *argv[]){
    char names[][50] = {{"Group 1"}, {"Group 2"}, {"Group 3"}, {"Group 4"}};
    struct debugMessenger dbgMsger = debugMessenger(names, sizeof(names)/sizeof(names[0]));
    freopen("/dev/tty", "w", stderr);

    printf("Hello from printf!\n");
    prtDbgMsg("Hello from standard prtDbgMsg!\n", &dbgMsger);

    dbgSetOutput(&dbgMsger, stderr);
    prtDbgMsg("Hello from redirected prtDbgMsg!\n", &dbgMsger);

    enblDbgGp(5, &dbgMsger);

    printf("%s status %d\n", dbgMsger.groupNames[0], dbgMsger.groupStatus[0]);
    printf("%s status %d\n", dbgMsger.groupNames[1], dbgMsger.groupStatus[1]);
    printf("%s status %d\n", dbgMsger.groupNames[2], dbgMsger.groupStatus[2]);
    
    prtDbgMsgGp("I am in group 1\n", 1, &dbgMsger);

    // dsblDbgGp(1, &dbgMsger);

    enblDbgOride(&dbgMsger);

    printf("%s status %d\n", dbgMsger.groupNames[0], dbgMsger.groupStatus[0]);
    printf("%s status %d\n", dbgMsger.groupNames[1], dbgMsger.groupStatus[1]);
    printf("%s status %d\n", dbgMsger.groupNames[2], dbgMsger.groupStatus[2]);

    prtDbgMsgGp("I am in group 1\n", 1, &dbgMsger);

    return EXIT_SUCCESS;
}
