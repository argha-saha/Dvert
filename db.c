#include <stdio.h>
#include <stdlib.h>

int getOption();
int getNumber(int);
void decToBin(int*, int);
int binToDec(int);
void decToOct(int*, int);
int octToDec(int);

int main()
{
    int option;
    int decimalNumber;
    int binaryNumber;
    int octalNumber;

    int *binary;
    int *octal;

    option = getOption();

    switch (option)
    {
        case 1: decimalNumber = getNumber(option);
                decToBin(binary, decimalNumber);
                break;
        case 2: binaryNumber = getNumber(option);
                decimalNumber = binToDec(binaryNumber);
                break;
        case 3: decimalNumber = getNumber(option);
                decToOct(octal, decimalNumber);
                break;
        case 4: octalNumber = getNumber(option);
                octalNumber = octToDec(octalNumber);
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
        printf("Enter 1 for Decimal to Binary\nEnter 2 for Binary to Decimal\nEnter 3 for Decimal to Octal\nEnter 4 for Octal to Decimal\n");
        scanf("%d", &option);

        if (option != 1 && option != 2 && option != 3 && option != 4)
        {
            printf("Please enter a valid option value!\n");
        }
    } while (option != 1 && option != 2 && option != 3 && option != 4);
    

    return (option);
}

int getNumber(int option)
{
    int num;

    switch (option)
    {
        case 1:
        case 3:
            printf("Enter a Decimal Number: ");
            scanf("%d", &num);
            break;
        case 2:
            printf("Enter a Binary Number: ");
            scanf("%d", &num);
            break;
        case 4:
            printf("Enter an Octal Number: ");
            scanf("%d", &num);
            break;
    }

    return (num);
}

void decToBin(int *binary, int num)
{
    int i;
    int j;
    int length;
    int temp;

    temp = num;

    i = 0;
    while (num)
    {
        num /= 2;
        i++;
    }

    binary = (int*) malloc(i * sizeof(int));

    j = 0;
    while (temp > 0)
    {
        *(binary + j) = temp % 2;
        temp /= 2;
        j++;
    }

    for (i = j - 1; i >= 0; i--)
    {
        printf("%d ", binary[i]);
    }

    printf("\n");
}

int binToDec(int num)
{
    int decimal;
    int base;
    int lastDigit;

    decimal = 0;
    base = 1;
    lastDigit = 0;

    while (num)
    {
        lastDigit = num % 10;
        num /= 10;

        decimal += base * lastDigit;

        base *= 2;
    }

    printf("%d\n", decimal);

    return (decimal);
}

void decToOct(int *octal, int num)
{
    int i;
    int j;
    int temp;
    
    i = 0;
    j = 0;
    temp = num;

    while (num)
    {
        num /= 8;
        i++;
    }

    octal = (int*) malloc(i * sizeof(int));

    while (temp)
    {
        *(octal + j) = temp % 8;
        temp /= 8;
        j++;
    }

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }

    printf("\n");
}

// Works but no implementation of octal validation yet
int octToDec(int num)
{
    int decimal;
    int base;
    int lastDigit;

    decimal = 0;
    base = 1;
    lastDigit = 0;

    while (num)
    {
        lastDigit = num % 10;
        num /= 10;

        decimal += base * lastDigit;

        base *= 8;
    }

    printf("%d\n", decimal);

    return (decimal);
}