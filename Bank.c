#include <stdio.h>
#include <string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();
void show_all_accounts();
void clear_all_accounts();

const char *ACCOUNT_FILE = "account.dat";

typedef struct {
  char name[50];
  int acc_no;
  float balance;
} account;

int main() {
  while (1) {
    int option;
    printf("\nWelcome..!");
    printf("\n1. Create Account");
    printf("\n2. Deposit Money");
    printf("\n3. Withdraw Money");
    printf("\n4. Check Balance");
    printf("\n5. Exit");

    printf("\nChoose your option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      create_account();
      break;
    case 2:
      deposit_money();
      break;
    case 3:
      withdraw_money();
      break;
    case 4:
      check_balance();
      break;
    
    case 5:
      return 0;
    default:
      printf("\nInvalid option! Please try again.");
    }
  }
}

void create_account() {
  account acc;
  FILE *file = fopen(ACCOUNT_FILE, "ab+"); // Append binary file
  if (file == NULL) {
    printf("\nUnable to open file!");
    return;
  }

  char c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);

  printf("Enter your name: ");
  fgets(acc.name, sizeof(acc.name), stdin);
  int index = strcspn(acc.name, "\n");
  acc.name[index] = '\0';

  printf("\nEnter account number: ");
  scanf("%d", &acc.acc_no);
  acc.balance = 0;

  fwrite(&acc, sizeof(acc), 1, file);
  fclose(file);
  printf("\n\033[0;33mAccount created successfully!\033[0m");
}

void deposit_money() {
  FILE *file = fopen(ACCOUNT_FILE, "rb+");
  if (file == NULL) {
    printf("\nUnable to open account file!");
    return;
  }

  int acc_no;
  float money;
  account acc_r;
  printf("Enter your account number: ");
  scanf("%d", &acc_no);
  printf("Enter amount to deposit: ");
  scanf("%f", &money);

  while (fread(&acc_r, sizeof(acc_r), 1, file)) {
    if (acc_r.acc_no == acc_no) {
      acc_r.balance += money;
      fseek(file, -sizeof(acc_r), SEEK_CUR);
      fwrite(&acc_r, sizeof(acc_r), 1, file);
      fclose(file);
      printf("\nSuccessfully deposited Rs.%.2f. New balance is Rs.%.2f", money, acc_r.balance);
      return;
    }
  }

  fclose(file);
  printf("\nAccount number %d was not found in records.", acc_no);
}

void withdraw_money() {
  FILE *file = fopen(ACCOUNT_FILE, "rb+");
  if (file == NULL) {
    printf("\nUnable to open account file!");
    return;
  }

  int acc_no;
  float money;
  account acc_r;
  printf("Enter your account number: ");
  scanf("%d", &acc_no);
  printf("Enter amount to withdraw: ");
  scanf("%f", &money);

  while (fread(&acc_r, sizeof(acc_r), 1, file)) {
    if (acc_r.acc_no == acc_no) {
      if (acc_r.balance >= money) {
        acc_r.balance -= money;
        fseek(file, -sizeof(acc_r), SEEK_CUR);
        fwrite(&acc_r, sizeof(acc_r), 1, file);
        fclose(file);
        printf("\nSuccessfully withdrew Rs.%.2f. Remaining balance is Rs.%.2f", money, acc_r.balance);
        return;
      } else {
        printf("\nInsufficient balance! Your current balance is Rs.%.2f", acc_r.balance);
        fclose(file);
        return;
      }
    }
  }

  fclose(file);
  printf("\nAccount number %d was not found in records.", acc_no);
}

void check_balance() {
  FILE *file = fopen(ACCOUNT_FILE, "rb");
  if (file == NULL) {
    printf("\nUnable to open file!");
    return;
  }

  int acc_no;
  account acc_read;
  printf("Enter your account number: ");
  scanf("%d", &acc_no);

  while (fread(&acc_read, sizeof(acc_read), 1, file)) {
    if (acc_read.acc_no == acc_no) {
      printf("\nYour current balance is Rs.%.2f", acc_read.balance);
      fclose(file);
      return;
    }
  }

  fclose(file);
  printf("\nAccount number %d is not found.", acc_no);
}



