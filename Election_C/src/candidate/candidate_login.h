#ifndef CANDIDATE_LOGIN_H
#define CANDIDATE_LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

extern const char *CDCOLOR;  
extern const char *CDCLRRM;

extern char *candidateLoginMessage;
extern char candidate_user_name[20];

void candidate_login();
void showCandidateLoginHeader();
void showCandidateDetails();
char *getCandidateUsername();
char *getCandidatePassword();
char *authenticateCandidate(char *username, char *password);

#endif 
