#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void prtdbgmsg(char *msg, FILE* out);
void prtdbgmsgg(char *msg, FILE* out, int debugGroups[], char groupNames[][50], int group);
void enableDbgGp(int group, int debugGroups[]);
void disableDbgGp(int group, int debugGroups[]);
void enableDbgOverride(int debugGroups[]);
void disableDbgOverride(int debugGroups[]);

#endif
