#include <stdio.h>
#include <stdlib.h>

int getOption();
int getNumber(int);
void decToBin(int*, int);
void binToDec(int);

int main()
{
    int option;
    int decimalNumber;
    int binaryNumber;

    int *binary;

    option = getOption();

    switch (option)
    {
        case 1: decimalNumber = getNumber(option);
                decToBin(binary, decimalNumber);
                break;
        case 2: binaryNumber = getNumber(option);
                binToDec(binaryNumber);
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

void binToDec(int num)
{
    int decimal;
    int base;
    int lastDigit;

    decimal = 0;
    base = 1;

    while (num)
    {
        lastDigit = num % 10;
        num /= 10;
        decimal += base * lastDigit;

        base *= 2;
    }

    printf("%d\n", decimal);
}