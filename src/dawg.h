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
} Dawg;

typedef struct arete
{
    int id;
    Dawg *gauche;
    Dawg *droite;
} Arete;


void minimiser(Dawg *dawg, Stack st, const struct hashmap_s *h_map, int p);
void dawg_insert(Dawg *dawg, char *mot, char *dernier_mot, Stack st, struct hashmap_s *h_map);
Dawg *dawg_init();

#endif