#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Define color constants
#define COLOR_DEFAULT 7   // White
#define COLOR_RED     12  // Red
#define COLOR_GREEN   10  // Green
#define COLOR_BLUE    9   // Blue

// Function prototypes
void setcolor(int color);
void printMenu();
char getComputerChoice();
char getUserChoice();
void determineWinner(char userChoice, char computerChoice);

int main() {
    char userChoice, computerChoice;
    srand(time(0));  // Seed random number generator

    while (1) {
        printMenu();
        userChoice = getUserChoice();
        if (userChoice == 'Q' || userChoice == 'q') {
            break;
        }

        computerChoice = getComputerChoice();
        printf("Computer chose: %c\n", computerChoice);

        determineWinner(userChoice, computerChoice);

        // Pause briefly before clearing screen to allow user to see result
        printf("\nPress Enter to continue...");
        getchar();  // Consume newline left in buffer by scanf
        getchar();  // Wait for Enter key press
    }

    printf("Thanks for playing!\n");
    return 0;
}

void printMenu() {
    system("cls");
    printf("\nRock-Paper-Scissors Game\n");
    printf("Choose one of the following options:\n");
    printf("R - Rock\n");
    printf("P - Paper\n");
    printf("S - Scissors\n");
    printf("Q - Quit\n");
    setcolor(COLOR_BLUE);
    printf("Enter your choice: ");
    setcolor(COLOR_DEFAULT);
}

char getComputerChoice() {
    int randomChoice = rand() % 3;
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
    // Convert choices to uppercase for case-insensitive comparison
    userChoice = toupper(userChoice);
    computerChoice = toupper(computerChoice);

    if (userChoice == computerChoice) {
        setcolor(COLOR_GREEN);
        printf("It's a tie!\n");
    } else if ((userChoice == 'R' && computerChoice == 'S') ||
               (userChoice == 'P' && computerChoice == 'R') ||
               (userChoice == 'S' && computerChoice == 'P')) {
        setcolor(COLOR_GREEN);
        printf("You win!\n");
    } else {
        setcolor(COLOR_RED);
        printf("You lose!\n");
    }
    setcolor(COLOR_DEFAULT);
}

void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
