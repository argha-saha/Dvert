#include <stdio.h>

int getOption();
int getNumber(int);

int main()
{
    int option;
    int decimalNumber;
    int binaryNumber;

    option = getOption();

    switch (option)
    {
        case 1: decimalNumber = getNumber(option);
                break;
        case 2: binaryNumber = getNumber(option);
                break;
    }

    return 0;
}

int getOption()
{
    int option;

    // Input validation
    do
    {
        printf("Enter 1 for Decimal to Binary\nEnter 2 for Binary to Decimal\n");
        scanf("%d", &option);

        if (option != 1 && option != 2)
        {
            printf("Please enter a valid option value!\n");
        }
    } while (option != 1 && option != 2);
    

    return (option);
}

int getNumber(int option)
{
    int num;

    switch (option)
    {
        case 1:
            printf("Enter a Decimal Number: ");
            scanf("%d", &num);
            break;
        case 2:
            printf("Enter a Binary Number: ");
            scanf("%d", &num);
            break;
    }

    return (num);
}