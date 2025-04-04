#include "./libs/cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text, int start, int end);

const int asciiOfDot = 46, asciiOfBlank = 32, asciiOfComma = 44, asciiOfQuestion = 63, asciiOfExclm = 33;

int main(void)
{
    // string text = "One fish. Two fish. Red fish. Blue fish.";
    string text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";
    
    
    int textLength = strlen(text);
    int numberOfWords = count_words(text, 44, textLength);
    printf("%i\n", numberOfWords);

}

int count_words(string text, int start, int end)
{
    int numberOfWords = 0;
    while (start < end)
    {
        if(isalpha(text[start]))
        {
            while ((int) text[start] != asciiOfBlank && (int) text[start] != asciiOfComma && (int) text[start] != asciiOfDot && (int) text[start] != asciiOfExclm && (int) text[start] != asciiOfQuestion)
            {
                start++;
            }
            numberOfWords++;
        }
        start++;
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