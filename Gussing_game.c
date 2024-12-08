#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int  random, guess, play_again;
  do{
  int no_of_guess = 0;
  srand(time(NULL));

  printf("\n\033[0;33mWelcome..\033[0m\n");
  random = (rand() % 100) + 1;

  printf("\nRandom number is:%d", random);

  do
  {
    printf("\nPlease enter your guess between(1 to 100):");
    scanf("%d", &guess);

    if (guess < 1 || guess > 100)
    {
      printf("Invalid guess! Please enter a number between 1 and 100.\n");
      //continue; // Skip this iteration
    }
    no_of_guess++;

    if (guess < random)
    {
      printf("Try to guess large number");
    }
    else if (guess > random)
    {
      printf("Try  to guess small number");
    }
    else
    {
      printf("\n\033[0;35mcongratulations!!\033[0m your guess is Correct. you take %d attempt", no_of_guess);
    }

  } while (guess != random);

  printf("\nGame complites");
  printf("\nDo you want to play again? Press 1 to restart, 0 to exit: ");
  scanf("%d", &play_again);
}
while (play_again == 1);
  

printf("\nGame completed. Thank you for playing!\n");

return 0;
}