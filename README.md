# automatic_language_detection
A tool to detect the main language used in a given phrase.

##How to use:

- Clone the project : `git clone https://github.com/magmine/automatic_language_detection.git`
- You need to have **gnu make** installed preferably you are running it in Linux.
- In the root of the project run : `make trie`
- Execute the program using : `./trie`
- Enter your phrases and you will get which languge it is.

##example:

```
~/automatic_language_detection/ (main *) $ make trie
cc -c src/main.c
cc -c src/utils.c
cc -o trie main.o trie.o utils.o
~/automatic_language_detection/ (main *) $ ./trie 
--> Found : abada
--> Found : abarticulation
--> Found : abdominohysterectomy
~/hy everyone this is working
C'est une phrase en anglais
quelle belle journee
C'est une phrase en français
```
