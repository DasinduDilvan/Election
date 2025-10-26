#ifndef PARTY_REGISTRATION_H
#define PARTY_REGISTRATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🎨 Terminal color constants (extern prevents multiple definition errors)
extern const char *PRCOLOR;
extern const char *PRCLRRM;

typedef struct {
    int Party_ID;
    char Party_Name[50];
    char Username[50];
    char Password[20];
    char Party_Color[20];
    char Party_Leader[20];
    char Symbol[50];
} Party;

extern Party partydetails;

int party_register();
void showPartyHeader();
int getPartyData();

#endif // PARTY_REGISTRATION_H
