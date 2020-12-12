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


Dawg minimiser(Dawg d, Stack s, struct hashmap_s h, int p)
{
    Arete a;
    char * key;

    while (stack_size(s) > p)
    {
        a = stack_pop(s);
        if (hashmap_iterate(h, iterate_label, a->droite) != 0)
        {
            a->gauche = a->droite
        }
    }
}
