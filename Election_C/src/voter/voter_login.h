#ifndef VOTER_LOGIN_H
#define VOTER_LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

extern const char *COLORVL;
extern const char *CLRRMVL;

extern char *loginMessage;

void voter_login();
void showVoterLogHeader();
void showContentofVL();

char *username();
char *password();
char *authenticate(char *username, char *password);

#endif 
