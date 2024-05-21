#include <stdio.h>

int main()
{
    // TO DO
    // develop the case of a very high number of operations for all operatos (i.e 3 + 45 + 43+ 5 + ....)
    
    char operation;
    double num1, num2, result;

    //Prompt the user for some inputs
    printf("Scientific calculator \n");
    printf("Enter operator (+, -, *, /, ^): ");
    scanf("%c", &operation);

    // prompt user for numbers
    printf("Insert 2 numbers (if you want to elevate a number to another one choose the 2nd input as integer): ");
    scanf("%lf %lf", &num1, &num2);


    //Perform calculation based on the operation
    switch(operation)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) // division by 0!
                result = num1 / num2;
            else
            {
                printf("Error: Division by 0! \n");
                return 1;
            }          
            break;
        case '^':
            result = 1;
            for(int i=1; i<=(int)num2; i++)
                result *= num1;
            break;
        default:
            printf("Error: invalid operation required! \n");
            return 1;
    }
    // display result
    printf("Result: %.5lf", result);
    
    return 0;
}