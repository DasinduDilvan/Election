#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
    #define PATH_SEPARATOR "\\"
    #define MAIN_PROGRAM "..\\main\\main.exe"
#else
    #define CLEAR_CMD "clear"
    #define PATH_SEPARATOR "/"
    #define MAIN_PROGRAM "../main/main"
#endif

extern const char *COLORADM;
extern const char *COLORGADM;
extern const char *COLORRADM;
extern const char *CLRRMADM;

extern int counts[6];
extern int choice;

void admin_login();
void showAdminHeader();
int credentials();
void showContentofAdmin();
void controlPanel();

int countOfRequests(int location);
int reWriteCandidateRequestFile(int x);

int candidate_requests();
int party_requests();

void set_election_start_time();
void set_election_end_time();

#endif
