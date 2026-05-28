// standard includes
#include <STDIO.H>
#include <STDLIB.H>
#include <STRING.H>

// my own includes
#include "CH_DEF.H"

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
            printf("Type 'play', 'help', or 'quit': ");
        } else if (strcmp(starterchoice, "quit") == 0) {
            // quit the game
            exit(0);
        } else {
            printf("That wasn't valid. Quitting...\n");
            exit(0); // this is what you get for not reading my shit man
        }
    }
}