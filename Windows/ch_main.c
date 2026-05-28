// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// my own includes
#include "ch_def.h"

void startgame(void);

int main() {
    char starterchoice[100];
    printf("Choices\n");
    printf("A stupid little excuse for a beginner C game by awes145\n");
    printf("Type 'play', 'help', or 'quit': ");
    while (1) {
        fgets(starterchoice, sizeof(starterchoice), stdin);
        starterchoice[strcspn(starterchoice, "\n")] = 0; // get rid of the dumbass newline
        if (strcmp(starterchoice, "play") == 0) {
            // start the game
            startgame();
        } else if (strcmp(starterchoice, "help") == 0) {
            printf("Choices is a game about picking the correct choices.\n");
            printf("If you make the wrong choice, you will be sent back to the beginning.\n");
            printf("You will be presented with 3 choices, 20 times.\n");
            printf("Each choice is completely randomized each time the game starts.\n");
            // go back to the start of main
        } else if (strcmp(starterchoice, "quit") == 0) {
            // quit the game
            exit(0);
        } else {
            printf("That wasn't valid. Quitting...\n");
            exit(0); // this is what you get for not reading my shit man
        }
    }
}