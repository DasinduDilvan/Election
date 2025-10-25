#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern const char *COLORYLO;
extern const char *MAINCLRRM;
#define MAX_LINE_RESULT = 256;
#define MAX_NAME_RESULT = 100;

extern int choice;
extern int linecounts[3];
extern char electionStartTime[12];
extern char electionEndTime[12];
int check_true;

int firstFunction();
void showMainHeader(void);
void showContent(void);
int userCount(int location);
int main_menu();
void terms_conditions();
int view_results();
int showResultContent();

#endif 
