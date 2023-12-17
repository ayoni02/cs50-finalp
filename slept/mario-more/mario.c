#include <cs50.h>
#include <stdio.h>

int main()
{
    int i;
    int blocks = get_int("Give the blocks height(1-8): ");
    while((blocks <=0) | (blocks >=9)) {
            blocks = get_int("Give the blocks height(1-8): ");
        };
    for (i = 1; i < blocks+1; i++) {
        // printf("%d\n", i);
        for (int j = 0; j < blocks - i; j++) {
        printf(" ");
        }

        for (int j = 0; j < i; j++) {
        printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++) {
        printf("#");
        }
        printf("\n");
    }
}