#include <cs50.h>
#include <stdio.h>
#define isSpace(symbol) (symbol == '.' || symbol == '?' || symbol == '!')
#include <ctype.h>
#include <math.h>

int countNumberOfWordsIn(string text);
int countNumberOfLettersIn(string text);
int countNumberOfSentencesIn(string text);

int main()
{
    char *text;
    text = get_string("Text: ");
    float words = countNumberOfWordsIn(text);
    float letters = countNumberOfLettersIn(text);
    float sentences = countNumberOfSentencesIn(text);
    printf("%d letters\n", (int) letters);
    printf("%d words\n", (int) words);
    printf("%d sentences\n", (int) sentences);
    float L = letters / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(index);
    if (grade < 1)
    {
        grade = 1;
        printf("Before Grade %d\n", grade);
    }
    else if (grade > 16)
    {
        grade = 16;
        printf("Grade %d+\n", grade);
    }
    else
        printf("Grade %d\n", grade);
}

int countNumberOfWordsIn(string text)
{
    int count = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i + 1] != ' ')
            count++;
    }
    return count;
}

int countNumberOfLettersIn(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]) && text[i] != ' ')
            count++;
    }
    return count;
}

int countNumberOfSentencesIn(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isSpace(text[i])) // && text[i] != ' ')
            count++;
    }
    return count;
}