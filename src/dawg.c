#include "dawg.h"
#include "stack.h"
#include "hashmap.h"

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

//start by inserting and then we see the other phases
void dawg_insert(Dawg *dawg, char *mot, char *dernier_mot, Stack st, struct hashmap_s *h_map) {
    int lgr = strlen(mot);
    int ind;

    Dawg *tmp = dawg;
    if (dernier_mot == NULL) {
        for (int i = 0; i < lgr; i++)
        {
            ind = ascii_to_index(mot[i]);
            if (tmp->fils[ind] == NULL)
                tmp->fils[ind] = trie_init();
            tmp = tmp->fils[ind];
        }
        tmp->est_mot = true;
    } else {
        //Check if stack is empty ?

        //
    }
}



Dawg *minimiser(Dawg *dawg, Stack st, const struct hashmap_s* h_map, int p)
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
