#ifndef DAWG_H
#define DAWG_H

#include "stack.h"
#include "hashmap.h"
#include <stdbool.h>

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
    Dawg droite;
} * Arete;


Dawg minimiser(Dawg d, Stack s, const struct hashmap_s *h, int p);

#endif