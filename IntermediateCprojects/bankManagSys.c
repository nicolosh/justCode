#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


//Inserire altre funzionalità come carta number, cvv, expiration date, fondo pensione, ....

// Define structure for Bank Account
struct BankAccount {
    int accountNumber;
    char name[100];
    float balance;
};

// to return the time operation
char* get_time(time_t *currentTime)
{
    time(currentTime);  // storing current time
    return ctime(currentTime); // converting time into a string
}

bool positive(int num)
{
    if(num < 0)
    {
        printf("Account number cannot be NEGATIVE. Retry! \n");
        return false;
    }
    return true;
}

// check account number
bool accountNumberCheck(struct BankAccount* accounts, int numAccounts)
{
    if(numAccounts > 0) // almeno 1
    {
        for (int j = numAccounts; j > 0; j--)
        {    
            if(accounts[numAccounts].accountNumber == accounts[numAccounts - j].accountNumber)
            {
                printf("This account number is NOT VALID: already created by another client. \n");
                return false;
            }
        }
    }
    return true;
}

// Function to create a new account
void createAccount(struct BankAccount *accounts, int *numAccounts, time_t *currentTime) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    if(positive(accounts[*numAccounts].accountNumber))
    {    
        if(accountNumberCheck(accounts, *numAccounts))
        {
            printf("Enter name: ");
            scanf("%s", &accounts[*numAccounts].name);
            accounts[*numAccounts].balance = 0.0;
            printf("Account of %s created successfully on %s", accounts[*numAccounts].name, get_time(currentTime));
            (*numAccounts)++;
        }
    }
}

// Function to deposit money
void deposit(struct BankAccount *accounts, int numAccounts, time_t *currentTime) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    if(positive(accNum))
    {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].accountNumber == accNum) {
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                while(amount < 0)
                {
                    printf("Negative quantity entered. \nPlease retry. \n");
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount);
                }
                accounts[i].balance += amount;
                printf("Deposit successful. Current balance of %s: %.2f €. \nOperation terminated at %s", accounts[i].name, accounts[i].balance, get_time(currentTime));
                return;
            }
        }
        printf("Account not found.\n");
    }
}

// Function to withdraw money
void withdraw(struct BankAccount *accounts, int numAccounts, time_t *currentTime) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    if (positive(accNum))
    {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].accountNumber == accNum) {
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                while(amount < 0)
                {
                    printf("Negative quantity entered. \nPlease retry. \n");
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount);
                }

                if (amount > accounts[i].balance) {
                    printf("Insufficient balance.\n");
                } else {
                    accounts[i].balance -= amount;
                    printf("Withdrawal successful. Current balance of %s: %.2f €. \nOperation terminated at %s", accounts[i].name, accounts[i].balance, get_time(currentTime));
                }
                return;
            }
        }
        printf("Account not found.\n");
    }
}

// Function to check balance
void checkBalance(struct BankAccount *accounts, int numAccounts, time_t *currentTime) {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    if(positive(accNum))
    {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].accountNumber == accNum) {
                printf("Current balance of %s: %.2f €. \nOperation terminated at %s", accounts[i].name, accounts[i].balance, get_time(currentTime));
                return;
            }
        }
        printf("Account not found.\n");
    }
}

void resumeAccount(struct BankAccount* accounts, int numAccounts, time_t *currentTime)
{
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    if(positive(accNum))
    {
        for (int i=0; i < numAccounts; i++)
        {
            if(accounts[i].accountNumber == accNum)
            {
                printf("------------ Account resume ----------- \n", accounts[i].name);
                printf("Account holder's name: %s \n", accounts[i].name);
                printf("Account number: %d \n", accounts[i].accountNumber);
                printf("Current balance: %.5f €. \nOperation terminated at %s", accounts[i].balance, get_time(currentTime));
                printf("------------ End resume ------------- \n");
                return;
            }
        }
        printf("Account not found. \n");
    }
}

int main() {
    struct BankAccount accounts[100];
    int numAccounts = 0;
    int choice;
    time_t currentTime;

    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Resume of account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts, &currentTime);
                break;
            case 2:
                deposit(accounts, numAccounts, &currentTime);
                break;
            case 3:
                withdraw(accounts, numAccounts, &currentTime);
                break;
            case 4:
                checkBalance(accounts, numAccounts, &currentTime);
                break;
            case 5:
                resumeAccount(accounts, numAccounts, &currentTime);
                break;
            case 6:
                printf("Exiting from bank account management system on %s", get_time(&currentTime));
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}