#include "./libs/cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = "One fish. Two fish. Red fish. Blue fish.";
    // string text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";

    int i = count_letters(text);

    printf("%i\n", i);

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, textLength = strlen(text); i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}