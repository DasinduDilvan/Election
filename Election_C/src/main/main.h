#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern const char *COLORYLO;
extern const char *MAINCLRRM;

extern int choice;
extern int linecounts[3];
extern char electionStartTime[12];
extern char electionEndTime[12];

void showMainHeader(void);

void showContent(void);

int userCount(int location);

int main_menu();

void terms_conditions();

#endif 
