#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printMenu();
char getComputerChoice();
char getUserChoice();
void determineWinner(char userChoice, char computerChoice);

int main() {
    char userChoice, computerChoice;
    srand(time(0));                                                                             // Seed random number generator

    while (1) {
        printMenu();
        userChoice = getUserChoice();
        if (userChoice == 'Q' || userChoice == 'q') {
            break;
        }

        computerChoice = getComputerChoice();
        printf("Computer chose: %c\n", computerChoice);

        determineWinner(userChoice, computerChoice);
    }

    printf("Thanks for playing!\n");
    return 0;
}

void printMenu() {
    printf("\nRock-Paper-Scissors Game\n");
    printf("Choose one of the following options:\n");
    printf("R - Rock\n");
    printf("P - Paper\n");
    printf("S - Scissors\n");
    printf("Q - Quit\n");
    printf("Enter your choice: ");
}

char getComputerChoice() {
    int randomChoice = rand() % 3;                                                                   // 
    switch (randomChoice) {
        case 0:
            return 'R';
        case 1:
            return 'P';
        case 2:
            return 'S';
        default:
            return 'R';
    }
}

char getUserChoice() {
    char choice;
    scanf(" %c", &choice);
    return choice;
}

void determineWinner(char userChoice, char computerChoice) {
    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 'R' && computerChoice == 'S') ||
               (userChoice == 'P' && computerChoice == 'R') ||
               (userChoice == 'S' && computerChoice == 'P')) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

