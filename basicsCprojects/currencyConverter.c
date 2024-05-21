#include <stdio.h>
#include <stdlib.h>

// Function to convert amount from one currency to another
float convertCurrency(float amount, float exchangeRate)
{
    return amount * exchangeRate;
}

// result of conversion on terminal
void printOUT(int choice, float amount)
{
    float exchangeRate;
    switch (choice)
    {
        // USDtoEuro
        case 1: 
            exchangeRate = 0.83;
            printf("Equivalent amount in Euro: %.2f €\n", convertCurrency(amount, exchangeRate));
            break;
        // USDtoGBP
        case 2:
            exchangeRate = 0.72;
            printf("Equivalent amount in GBP: %.2f £\n", convertCurrency(amount, exchangeRate));
            break;
        // USDtoJPY
        case 3:
            exchangeRate = 109.75;
            printf("Equivalent amount in JPY: %.2f ¥\n", convertCurrency(amount, exchangeRate));
            break;
        case 4:
            printf("Exiting from converter \n");
            break;
        default:
            printf("Invalid choice. Retry! \n");
    }
}

int main()
{
    int choice;
    float USD_amount;

    // non gestisce choice tipo double !!
    
    do
    {
        printf("\nCurrency Converter\n");
        printf("1. USD to Euro \n");
        printf("2. USD to GBP \n");
        printf("3. USD to JPY \n");
        printf("4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        while(choice < 0)
        {
            printf("Choice cannot be a negative number. Retry! \n");
            printf("Insert a POSITIVE number: ");
            scanf("%d", &choice);
        }
        if (choice >= 1 && choice < 4)
        {    
            printf("Enter the amount in USD: $");
            scanf("%f", &USD_amount);
        }
        printOUT(choice, USD_amount);
    } while (choice != 4);

    return 0;
}