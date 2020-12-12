#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "utils.h"
#include "trie.h"

/*
 * Copy this function template to construct either a DAWG or a trie
 * based on the dictionary filename given
 *
 * Don't forget to change the void return type of this function
 */
Trie* construct_trie(char *dict) {
    // Instantiate either a Trie or a DAWG here
    // ...

    char *line = NULL;
    size_t len = 0;
    size_t read;
    FILE *fp;
    // open file
    fp = fopen(dict, "r"); // read mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    Trie *trie = trie_init();
    // read file
    while ((read = getline(&line, &len, fp)) != -1) {
        // remove newline
        size_t length = strlen(line);
        if((length > 0) && (line[length-1] == '\n'))
        {
            line[length-1] ='\0';
        }

        trie_insert(trie, line);
    }

    fclose(fp);
    free(line);

    return trie;
    // return ...;
}



int main(int argc, char* argv[]) {
    // construct("dict/french-wordlist.txt", true);
    Trie *trie = construct_trie("dict/english-wordlist.txt");
    // construct("dict/german-wordlist.txt", true);

    // Here listen for user input, parse it and detect the language of the given text
    // To complete ...
    assert(trie_rech(trie, "abada"));
    printf("--> Found : abada\n");

    assert(trie_rech(trie, "abarticulation"));
    printf("--> Found : abarticulation\n");


    assert(trie_rech(trie, "abdominohysterectomy"));
    printf("--> Found : abdominohysterectomy\n");

    return 0;
}
