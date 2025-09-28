#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
int random, guess, no_of_guess = 0;
srand(time(NULL));
printf("--------------------------------------");
printf("\nWelcome To The Number Guessing Game\n");
printf("--------------------------------------");
random = rand() % 100 + 1; 
do {
    printf("\nEnter Your Guess between 1 to 100: ");
    scanf("%d",&guess);
    no_of_guess++;

    if (guess < random) {
        printf("Think bigger...\n");
    } else if (guess > random)
    {
        printf("Think smaller....\n");
    } else
    {
        printf("\nCongratulations. You guessed it correct number in %d attempts",no_of_guess);
    }  
} while (guess != random);
{
    printf("\n\nBye, Thanks for playing.See You Next Time.\n");
}

}