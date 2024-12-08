#include <stdio.h>
#include <math.h>
void print_menu();

int main()
{
  int choice;
  double x, y, z;
  while (1)
  {

    print_menu();
    scanf("%d", &choice);
    if (choice == 8)
    {
      break;
    }

    while (choice < 1 || choice > 8)
    {
      printf("Invalid choice. Please enter a valid choice (1-8): ");
      scanf("%d", &choice);
    }
    while (1)
    {
      switch (choice)
      {
      case 1:
        printf("\033[0;32Addition\033[0m\n");
        printf("Enter your first number:");
        scanf("%lf", &x);
        printf("Enter your second number:");
        scanf("%lf", &y);
        z = x + y;
        printf("Result is:%.0lf\n", z);
        break;
      case 2:
        printf("\033[0;32mSubtraction\033[0m\n");
        printf("Enter your first number:");
        scanf("%lf", &x);
        printf("Enter your second number:");
        scanf("%lf", &y);
        z = x - y;
        printf("Result is:%.0lf\n", z);
        break;
      case 3:
        printf("\033[0;32mMultification\033[0m\n");
        printf("Enter your first number:");
        scanf("%lf", &x);
        printf("Enter your second number:");
        scanf("%lf", &y);
        z = x * y;
        printf("Result is:%.0lf\n", z);
        break;
      case 4:
        printf("\033[0;32Division\033[0m\n");
        printf("Enter your first number:");
        scanf("%lf", &x);
        printf("Enter your second number:");
        scanf("%lf", &y);
        if (y == 0)
        {
          printf("Error: Division by zero is not allowed.\n");
        }

        else
        {
          z = x / y;
          printf("Result is:%.0lf\n", z);
        }
        break;
      case 5:
        printf("\033[0;32mmodules\033[0m\n");
        printf("Enter your first number:");
        scanf("%lf", &x);
        printf("Enter your second number:");
        scanf("%lf", &y);
        if (y == 0)
        {
          printf("Error: Division by zero is not allowed.\n");
        }

        else
        {
          z = fmod(x, y);
          printf("Result is:%.0lf\n", z);
        }

        break;
      case 6:
        printf("\033[0;32mPower\033[0m\n");

        printf("Enter the base:");
        scanf("%lf", &x);
        printf("Enter the exponent:");
        scanf("%lf", &y);
        z = pow(x, y);
        printf("Result is:%.0lf\n", z);
        break;
      case 7:

        printf("\033[0;32mSimple intrest\033[0m\n");
        double time;

        printf("Enter the principal amount:");
        scanf("%lf", &x);
        printf("Enter the annual interest rate (in %%):");
        scanf("%lf", &y);
        printf("Enter the time (in years): ");
        scanf("%lf", &time);
        z = (x * y * time) / 100;
        printf("Result is:%.0lf\n", z);
        break;

      default:
        printf("Invalid choice");
        break;
      }

      printf("\nDo you want to continue with this operation? (1 for Yes, 0 for No): ");
      int cont;
      scanf("%d", &cont);

      if (cont == 0)
      {
        break;
      }
    }
  }
  return 0;
}
void print_menu()
{
  printf("\033[0;32mWelcome...\033[0m\n");
  printf("1.Addistion\n");
  printf("2.Subtract\n");
  printf("3.Multification\n");
  printf("4.division\n");
  printf("5.modules\n");
  printf("6.Power\n");
  printf("7.Simple intrest\n");
  printf("8.Exit\n");
  printf("Now enter your choice(1-8):");
}