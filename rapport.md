# Rapport


## Introduction

Le traitement des chaînes de caractères peuvent  être considérées comme l'un des sujets les plus importants et les plus courants en programmation. Le traitement des chaînes de caractères a également une variété d'applications dans le monde réel, telles que:

- les moteurs de recherche
- Analyse du génome
- Analyse des données

Ce rapport comporte une comparaison théorique et pratique entre deux des plus importants structures des données qui permet de manipuler des chaînes de caractères efficacement.

## Analyse théorique
### Le trie
- La structure de donnée trie se base principalement sur le prefix des chaînes de caratéres. Tout chaîne dans le trie qui partage le même prefix, partage aussi le même zone de stockage ce qui permet de diminuer la zone memoire à allouer.
- Étude de complexité:
    -   temporelle:
        -   **Construire le trie:** `O(n * l)` ou `n` est le nombre des chaînes à inserer et `l` c'est la longueur moyenne des chaînes.
        -   **Recherche d'un mot:** Pour notre implementation la recherche d'un mot dans le trie à une complexité de `O(n)` oú `n` est la longueur du mot.
        -   **Ajouter un mot:** L'ajout d'un mot de longueur `l` à comme comme complexité `O(l)`.
    -   spatiale:
        
        Si on concidére une langue avec un alphabet de longueur `n` (eg. pour l'alphabet latin `n = 26`) et que la moyenne des logueurs des mots est `p` alors la complexité spatiale serait `O(n^p)` car chaque la structure peut être assimilé à un arbre avec `p` fils per noeud.
### Le dawg
- Étude de complexité:
    -   temporelle:
        -   **Construire le dawg:** `O(n * l)` ou `n` est le nombre des chaînes à inserer et `l` c'est la longueur moyenne des chaînes.
        -   **Recherche d'un mot:** Pour notre implementation la recherche d'un mot dans le dawg à une complexité de `O(n)` oú `n` est la longueur du mot.

    -   spatiale:
        Le dawg permet de minimiser le stockage par l'utilisation pas seulement des prefixes mais aussi les suffixes en commun entre les chaînes de charactéres. C'est vrais que dans le pire de cas la complexité est `O(n^p)` comme le cas la structure trie mais
## Analyse pratique

En pratique plusieurs contraintes doivent être prise en consideration selon le hardware visé pour déployement, c'est vrais que la majorité des machines aujourdu'hi ont une mémoire qui peut supporter la majorité des programmes aujourdu'hi mais comme cette resource et limité et qu'il est partagé par d'autres programmes, minimiser sa consommation permettra à l'utilisater d'avoir une experience plus fluide.

