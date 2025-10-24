#ifndef VOTER_REGISTRATION_H
#define VOTER_REGISTRATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const char *COLORVR;
extern const char *CLRRMVR;

struct voterReg {
    char firstname[20];
    char lastname[20];
    char username[20];
    char password[20];
    char NIC[20];
    char gender[10];
    char dob[15];
    char area[30];
    int voterID;
};

void registerVoters();
void showVoterRegHeader();
void getVoterDetails(struct voterReg voter);
int make_voter_ID();
void saveVoterToFile(struct voterReg voter);
void messageSuccess();
void messageCanceled();

#endif 
