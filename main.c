#include "header.h"

int DEBUG_GROUPS[] = {0, 0};
char DEBUG_NAMES[sizeof(DEBUG_GROUPS)][50] = {"OVERRIDE", "Group 1"};


int main(int argc, char *argv[]){

    printf("printf: Hello, World!\n");
    prtdbgmsg("stdout: Hello, World!\n", stdout);
    prtdbgmsg("stderr: Hello, World!\n", stderr);

    enableDbgGp(1, DEBUG_GROUPS);
    
    prtdbgmsgg("I am in group 1\n", stdout, DEBUG_GROUPS, DEBUG_NAMES, 1);

    disableDbgGp(1, DEBUG_GROUPS);

    enableDbgOverride(DEBUG_GROUPS);

    prtdbgmsgg("I am in group 1\n", stdout, DEBUG_GROUPS, DEBUG_NAMES, 1);


    // void prtdbgmsgg(char *msg, FILE* out, const int debugGroups[], const char groupNames[], int group);

    return EXIT_SUCCESS;
}
