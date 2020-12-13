#include "dawg.h"
#include "stack.h"
#include "hashmap.h"
#include "utils.h"

int iterate_label(void * context, void * const value)
{
    if (same_label(context, value)) {
        context = value;
        return 0;
    }
    return 1;
}

Dawg *dawg_init() {
    Dawg *dawg = (Dawg *)malloc(sizeof(Dawg));
    if (dawg == NULL)
        exit(EXIT_FAILURE);
    for (int i = 0; i < 26; i++)
        dawg->fils[i] = NULL;
    dawg->est_mot = false;
    return dawg;
}

/**
 * ----Algorithme d'insertion----
 * -- Si le mot precedent est null on ajoute le mot à la racine
 * //et en ajoute tous ces sommets au hashmap
 * -- Si un mot existe on trouve le prefix commun le plus long
 * -- Le suffix non commun on l'ajoute 
*/

//start by inserting and then we see the other phases
void dawg_insert(Dawg *dawg, char *mot, char *dernier_mot, Stack st, struct hashmap_s *h_map) {
    int lgr = strlen(mot);
    int ind;

    Dawg *tmp = dawg;
    int p = max_prefix_commun(mot, dernier_mot);
    dernier_mot = mot;
    minimiser(dawg, st, h_map, p);
    if (stack_size(st) == 0) {
        if (dernier_mot == NULL) {
            for (int i = p; i < lgr; i++)
            {
                ind = ascii_to_index(mot[i]);
                if (tmp->fils[ind] == NULL)
                    tmp->fils[ind] = dawg_init();
                tmp = tmp->fils[ind];
            }
            tmp->est_mot = true;
        }
    }
}



void minimiser(Dawg *dawg, Stack st, const struct hashmap_s* h_map, int p)
{
    Arete *arret;
    char * key;

    while (stack_size(st) > p)
    {
        arret = (Arete *)stack_pop(st);
        if (hashmap_iterate(h_map, iterate_label, arret->droite) != 0) {
            arret->gauche = arret->droite;
        }
    }
}
