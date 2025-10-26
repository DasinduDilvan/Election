#ifndef VOTER_LOGIN_H
#define VOTER_LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

extern const char *COLORVL;
extern const char *CLRRMVL;

typedef struct {
    char firstName[50];
    char lastName[50];
    char username[20];
} VoterInfo;
typedef struct {
    char id[20];
    char name[100];
    char partyID[20];
} Candidate_VL;
typedef struct {
    char id[20];
    char name[100];
} Party_VL;

void voter_login();
void showVoterLogHeader();
void showContentofVL(VoterInfo *voter);
char *username();
char *password();
VoterInfo *voterauthenticate(char *username, char *password);
void viewPartiesAndCandidates();
void castVote(VoterInfo *voter);
void showElectionTime();
void displayMenu(VoterInfo *voter);

#endif
