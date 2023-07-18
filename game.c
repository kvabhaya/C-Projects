#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    // Generate a random number between 1 and 100
    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("Welcome to Guess the Number!\n");

    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);

        attempts++;

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);

    return 0;
}
