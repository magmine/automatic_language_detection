#ifndef DAWG_H
#define DAWG_H

#include "stack.h"
#include "hashmap.h"

typedef struct dawg
{
    int id;
    struct dawg * fils[26];
    bool est_mot;
} * Dawg;

typedef struct arete
{
    int id;
    Dawg gauche;
    Dawg droit;
} * Arete;


Dawg minimiser(Dawg d, Stack s, struct hashmap h, int p);

#endif