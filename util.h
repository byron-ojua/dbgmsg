#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void prtDbgMsg(char *msg, FILE* out);
void prtDbgMsgGp(char *msg, FILE* out, int debugGroups[], char groupNames[][50], int group);
void enblDbgGp(int group, int debugGroups[]);
void dsblDbgGp(int group, int debugGroups[]);
void enblDbgOride(int debugGroups[]);
void dsblDbgOride(int debugGroups[]);

#endif
