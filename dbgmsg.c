#include "dbgmsg.h"

struct debugMessenger debugMessenger(char names[][50], int numRows){
    struct debugMessenger dbgMsger;
    char (*gpNames)[50] = malloc((numRows + 1) * sizeof(char[50]));
    int *groupStats = malloc((numRows + 1) * sizeof(int));

    strcpy(gpNames[0], "OVERRIDE");

    for(int i = 0; i < numRows; i++){
        strcpy(gpNames[i + 1], names[i]);
        groupStats[i + 1] = 0;
    }

    dbgMsger.numGroups = numRows;
    dbgMsger.groupStatus = groupStats;
    dbgMsger.groupNames = gpNames;
    dbgMsger.output = stdout;

    return dbgMsger;
}

void dbgSetOutput(struct debugMessenger* dbgMsger, FILE* out){
    dbgMsger->output = out;
}

void prtDbgMsg(char *msg, struct debugMessenger* dbgMsger){
    fprintf(dbgMsger->output, "DEBUG MESSAGE: %s", msg);
    fflush(dbgMsger->output);
}

void prtDbgMsgGp(char *msg, int group, struct debugMessenger* dbgMsger){
    if (group < 1 || group > dbgMsger->numGroups){
        fprintf(stderr, "DEBUG MESSAGE: ERROR - Invalid debug group: %d\n", group);
        fflush(stderr);
    } else {
        if(dbgMsger->groupStatus[0]){
            fprintf(dbgMsger->output, "DEBUG MESSAGE (%s - Override): %s", dbgMsger->groupNames[group], msg);
        } else if(dbgMsger->groupStatus[group]){
            fprintf(dbgMsger->output, "DEBUG MESSAGE (%s): %s", dbgMsger->groupNames[group], msg);
        }
    }

    fflush(dbgMsger->output);
}

void enblDbgGp(int group, struct debugMessenger* dbgMsger){
    if (group > dbgMsger->numGroups - 1){
        fprintf(stderr, "DEBUG MESSAGE: ERROR - Invalid debug group: %d\n", group);
        fflush(stderr);
    } else {
        dbgMsger->groupStatus[group] = 1;
    }
}

void dsblDbgGp(int group, struct debugMessenger* dbgMsger){
    if (group > dbgMsger->numGroups - 1){
        fprintf(stderr, "DEBUG MESSAGE: ERROR - Invalid debug group: %d\n", group);
        fflush(stderr);
    } else {
        dbgMsger->groupStatus[group] = 0;
    }
}

void enblDbgOride(struct debugMessenger* dbgMsger){
    dbgMsger->groupStatus[0] = 1;
}

void dsblDbgOride(struct debugMessenger* dbgMsger){
    dbgMsger->groupStatus[1] = 0;
}