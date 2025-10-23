#ifndef CANDIDATE_REGISTRATION_H
#define CANDIDATE_REGISTRATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const char *COLOR;
extern const char *CLRRM;

typedef struct {
    int Candidate_ID;
    char First_Name[50];
    char Last_Name[50];
    char Username[50];
    char Password[20];
    char NIC[20];
    char Gender[10];
    char Party_Number[10];
} Candidate;

extern Candidate candidatedetails;

// 🛠 Function prototypes
void showCandidateHeader();
int getCandidateData();

#endif
