#ifndef PARTY_LOGIN_H
#define PARTY_LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

extern const char *PLCOLOR;
extern const char *PLCLRRM;

extern char *loginMessage;
extern char user_name[20];

void party_login();
void showPartyLoginHeader();
void showPartyDetails();
char *getUsername();
char *getPassword();
char *authenticate(char *username, char *password);

#endif
