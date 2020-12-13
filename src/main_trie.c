#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "utils.h"
#include "trie.h"
#include "dawg.h"

#define STACK_CAPACITY 100
#define H_MAP_INIT_SIZE 1024
#define MAX_LINE_LENGTH 10000

/*
 * Copy this function template to construct either a DAWG or a trie
 * based on the dictionary filename given
 *
 * Don't forget to change the void return type of this function
 */
Trie* construct(char *dict) {
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
    Trie *trie_english = construct("dict/english-wordlist.txt");
    Trie *trie_french = construct("dict/french-wordlist.txt");
    Trie *trie_german = construct("dict/german-wordlist.txt");
    // construct("dict/german-wordlist.txt", true);

    // Here listen for user input, parse it and detect the language of the given text
    // To complete ...
    assert(trie_rech(trie_english, "abada"));
    printf("--> Found : abada\n");

    assert(trie_rech(trie_english, "abarticulation"));
    printf("--> Found : abarticulation\n");


    assert(trie_rech(trie_english, "abdominohysterectomy"));
    printf("--> Found : abdominohysterectomy\n");

    char    *line;
    size_t  n = MAX_LINE_LENGTH;
    size_t read;
    line = (char *)malloc(n * sizeof(char));
    while((read = getline(&line, &n, stdin)) != -1) {
        int freq_english = 0;
        int freq_french = 0;
        int freq_german = 0;
        char *ptr = strtok(line," ,-:][{}().;\"");
        while (ptr != NULL)
        {
            //printf(":::: ptr = %s\n", ptr);
            parse_word(ptr);
            if (trie_rech(trie_english, ptr)) {
                freq_english++;
            }
            if (trie_rech(trie_french, ptr)) {
                freq_french++;
            }
            if (trie_rech(trie_german, ptr)) {
                freq_german++;
            }
            ptr = strtok(NULL, " ,-:][{}().;\"");
        }
        if (freq_english > freq_french) {
            if (freq_english > freq_german) {
                printf("C'est une phrase en anglais\n");
            } else {
                printf("C'est une phrase en allemand\n");
            }
        } else {
            if (freq_french > freq_german) {
                printf("C'est une phrase en français\n");
            } else {
                printf("C'est une phrase en allemand\n");
            }
        }
    }

    return 0;
}
