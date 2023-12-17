#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize = get_int("Start size: ");
    // TODO: Prompt for start size
    while (startSize < 9)
    {
        startSize = get_int("Start size: ");
    }
    // TODO: Prompt for end size
    int endSize = get_int("End size: ");
    // TODO: Prompt for start size
    while (endSize < startSize)
    {
        endSize = get_int("End size: ");
    }
    //printf("%d\n", endSize);
    // TODO: Calculate number of years until we reach threshold
    int year =0;
    int frac = startSize;
    while (frac < endSize)
    {
        //printf("End size: %f\n", frac);
        int sum = frac/3;
        int som = frac/4;
        frac = frac + sum - som;
        year += 1;
    }
    // TODO: Print number of years
    printf("Years: %d\n", year);
}
