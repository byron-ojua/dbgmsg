#include "util.h"

void prtDbgMsg(char *msg, FILE* out){
    fprintf(out, "DEBUG MESSAGE: %s", msg);
    fflush(out);
}

void prtDbgMsgGp(char *msg, FILE* out, int debugGroups[], char groupNames[][50], int group){
    if (group > (sizeof debugGroups / sizeof *debugGroups) - 1){
        fprintf(stderr, "DEBUG MESSAGE: ERROR - Invalid debug group: %d\n", group);
        fflush(stderr);
    } else {
        if(debugGroups[0]){
            fprintf(out, "DEBUG MESSAGE (%s - Override): %s", groupNames[group], msg);
        } else if(debugGroups[group]){
            fprintf(out, "DEBUG MESSAGE (%s): %s", groupNames[group], msg);
        }
    }

    fflush(out);
}

void enblDbgGp(int group, int debugGroups[]){
    if (group > (sizeof debugGroups / sizeof *debugGroups) - 1){
        fprintf(stderr, "DEBUG MESSAGE: ERROR - Invalid debug group: %d\n", group);
        fflush(stderr);
    } else {
        debugGroups[group] = 1;
    }
}

void dsblDbgGp(int group, int debugGroups[]){
    if (group > (sizeof debugGroups / sizeof *debugGroups) - 1){
        fprintf(stderr, "DEBUG MESSAGE: ERROR - Invalid debug group: %d\n", group);
        fflush(stderr);
    } else {
        debugGroups[group] = 0;
    }
}

void enblDbgOride(int debugGroups[]){
    debugGroups[0] = 1;
}

void dsblDbgOride(int debugGroups[]){
    debugGroups[0] = 0;
}