#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int N = 8;

void print_bulb(int bit);

int main(void)
{
    int a;
    int b[32];
    int k = 0;
    string name = get_string("Message: ");
    for (int i = 0; name[i] != '\0'; i++)
    {
        a = name[i];

        // Printing array in reverse order.
        for (int j = N - 1; j >= 0; j--)
        {
            int bit = (a >> j) & 1;
            print_bulb(bit);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
