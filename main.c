#include "header.h"

int DEBUG_GROUPS[] = {0, 0};
char DEBUG_NAMES[sizeof(DEBUG_GROUPS)][50] = {"OVERRIDE", "Group 1"};


int main(int argc, char *argv[]){
    printf("printf: Hello, World!\n");
    prtDbgMsg("stdout: Hello, World!\n", stdout);
    prtDbgMsg("stderr: Hello, World!\n", stderr);

    enblDbgGp(1, DEBUG_GROUPS);
    
    prtDbgMsgGp("I am in group 1\n", stdout, DEBUG_GROUPS, DEBUG_NAMES, 1);

    dsblDbgGp(1, DEBUG_GROUPS);

    enblDbgOride(DEBUG_GROUPS);

    prtDbgMsgGp("I am in group 1\n", stdout, DEBUG_GROUPS, DEBUG_NAMES, 1);

    return EXIT_SUCCESS;
}
