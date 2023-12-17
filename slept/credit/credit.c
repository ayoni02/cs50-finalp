#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int isLuhnValid(long long int number);
int cardt(long long int number);

int main()
{
    long long number =0 ;
    long long credit = get_long("Number: ");
    if (isLuhnValid(credit)) {
            cardt(credit);
        }
    else
    {
        printf("INVALID\n");
    }
}

int isLuhnValid(long long int number) {
    int sum = 0;
    int doubleDigit = 0;
    int i = 0;

    while (number > 0) {
        if (i % 2 == 0) {
            sum += number % 10;
        } else {
            doubleDigit = 2 * (number % 10);
            if (doubleDigit > 9) {
                sum += (doubleDigit % 10) + 1;
            } else {
                sum += doubleDigit;
            }
        }
        number /= 10;
        i++;
    }

    if (sum % 10 == 0) {
        return 1; // Valid
    } else {
        return 0; // Invalid
    }
}

int cardt(long long int number)
{
    int i = 0;
    int sum = 0;
    while (number > 0){
        if (number < 10)
        {
            i = number;
        }
        sum += 1;
        number /= 10;

    //printf("%d\n", i);
    }
    if ((sum == 15) && (i == 3))
    {
        printf("AMEX\n");
    }
    else if ((sum == 13) && (i == 4))
    {
        printf("VISA\n");
    }
    else if ((sum == 16) && (i == 4))
    {
        printf("VISA\n");
    }
    else if ((sum == 16) && (i == 5))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}