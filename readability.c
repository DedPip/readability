#include "./libs/cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    // string text = "One fish. Two fish. Red fish. Blue fish.";
    string text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";

    int i = count_words(text);
    printf("%i\n", i);

}

int count_words(string text)
{
    int asciiOfBlank = 32;
    int numberOfWords = 0;
    for (int i = 0, textLength = strlen(text); i < textLength; i++)
    {
        if(isalpha(text[i]))
        {
            int j = i;
            while ((int) text[j] != asciiOfBlank)
            {
                j++;
            }
            i = j;
            numberOfWords++;
            continue;
        }
        else
        {
            continue;
        }
    }
    return numberOfWords;
}

int count_letters(string text)
{
    int numberOfLetters = 0;
    for (int i = 0, textLength = strlen(text); i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            numberOfLetters++;
        }
    }
    return numberOfLetters;
}