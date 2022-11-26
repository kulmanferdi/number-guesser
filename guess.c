//import header files
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//pre-compiler definitions
#define LEGENDARY 1
#define GREAT MAX * 0.3
#define GOOD MAX * 0.5
#define POOR MAX * 0.7

//unique enums and new type name for floating point numbers
enum GUESS {MIN = 1, MAX = 10};
enum VERSION {MAJOR = 1, MINOR = 2, PATCH = 0};
typedef float real;
typedef bool bit;

//function headers
void printResult(real avg);

int main(void)
{
    //variable declarations
    uint8_t playAgain, title [] = {"Number Guesser Game"};
    uint16_t guess, tries, number, round=1;
    real sumGuess = 0, previousSum;
    bit notNumber;

    do {
        notNumber = 0;
        start:
            system("clear");
            printf("%s\n%d. round\n\n", title, round);
            printf("Guess a number between %d and %d\n", MIN, MAX);
            srand(time(NULL));
            number = rand() % MAX + 1;
            tries = 1;
            do {
                do {
                    printf("%d. guess: ", tries);
                    scanf("%hd", &guess);
                    if (isdigit(guess))
                    {
                        notNumber = 1;                
                        printf("Entered input is not a number. Invalid round.\n");
                        sumGuess = previousSum;
                        int8_t errorChar;
                        do{            
                            printf("Do you want to start again or end the game [s/e]: ");
                            getchar();
                            scanf("%c", &errorChar);
                        } while (toupper(errorChar) != 'S' && toupper(errorChar) != 'E');
                        if(errorChar == 'S') goto start;                    
                        if(errorChar == 'E') goto end;
                    }                
                    if(notNumber == 1) break;
                } while (guess < MIN | guess > MAX);
                if(notNumber == 1) break;
                ++tries;
                ++sumGuess;       
                number > guess ? printf("Bigger.\n") : number < guess ? printf("Smaller.\n") : 
                printf("Correct! It is %d!\nNumber of tries: %d\nAverage number of guesses: %.1f\n", number, tries, sumGuess / round);
            } while (guess != number | notNumber == 1);
            do{            
                printf("Do you want to play again? [y/n]: ");
                getchar();
                scanf("%c", &playAgain);
            } while (toupper(playAgain) != 'N' && toupper(playAgain) != 'Y');
            ++round;
            previousSum = sumGuess;
    } while (toupper(playAgain) == 'Y');    
    end:
    //endscreen and result
        system("clear");
        printf("%s\n\nRounds played: %d\nYour average: %.1f\nPerformance rating: ", title, round, sumGuess / round);
        printResult(sumGuess / round);
        printf("\nThanks for playing!\nVersion: %d.%d.%d\n", MAJOR, MINOR, PATCH);
         
    return 0;
}

void printResult(real avg)
{
    if(avg == LEGENDARY) printf("YOU. ARE. GODLIKE.\n");
    else if(avg <= GREAT) printf("Decent game.\n"); 
    else if(avg <= GOOD) printf("This was good.\n");
    else if(avg <= POOR) printf("It was not good at all, not gonna lie.\n");
    else printf("You better take a very long break.\n");
}
