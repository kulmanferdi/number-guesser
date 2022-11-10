#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#define LEGENDARY 1
#define GREAT MAX*0.3
#define GOOD MAX*0.5
#define POOR MAX*0.7
enum GUESSRANGE {MIN = 1, MAX = 10};
enum GAMEVERSION {MAJOR = 1, MINOR = 1, PATCH = 1};
typedef float real;
int main(void)
{
    int8_t playAgain, title [] = {"Number Guesser Game"};
    int16_t guess, tries, number, round=0;
    real sumGuess=0;
    do {
        ++round;
        system("clear");
        printf("%s\n%d. round\n\n", title, round);
        printf("Guess a number between %d and %d\n", MIN, MAX);
        srand(time(NULL));
        number = rand() % MAX + 1;
        tries = 0;
        do {
            do {
                printf("%d. guess: ", tries+1);
                scanf("%hd", &guess);
            } while (guess < MIN | guess > MAX);
            ++tries;
            ++sumGuess;       
            number > guess ? printf("Bigger.\n") : number < guess ? printf("Smaller.\n") : 
            printf("Correct! It is %d!\nNumber of tries: %d\nAverage number of guesses: %.1f\n", number, tries, sumGuess / round);
        } while (guess != number);       
        do{            
            printf("Do you want to play again? [y/n]: ");
            getchar();
            scanf("%c", &playAgain);
        } while (toupper(playAgain) != 'N' && toupper(playAgain) != 'Y');
    } while (toupper(playAgain) == 'Y');
    system("clear");
    printf("%s\n\nRounds played: %d\nYour average: %.1f\nPerformance rating: ", title, round, sumGuess / round);
    if(sumGuess/round == LEGENDARY) printf("YOU. ARE. GODLIKE.\n");
    else if(sumGuess/round <= GREAT) printf("Decent game.\n"); 
    else if(sumGuess/round <= GOOD) printf("This was good.\n");
    else if(sumGuess/round <= POOR) printf("It was not good at all, not gonna lie.\n");
    else printf("You better take a very long break.\n");
    printf("\nThanks for playing!\nGame version: %d.%d.%d\n", MAJOR, MINOR, PATCH);
    return 0;
}
