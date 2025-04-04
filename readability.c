#include "./libs/cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int count_letters(string text);
int count_words(string text, int start, int end);
int count_sentences(string text);

const int asciiOfDot = 46, asciiOfBlank = 32, asciiOfComma = 44, asciiOfQuestion = 63, asciiOfExclm = 33;

int main(void)
{
    // string text = "One fish. Two fish. Red fish. Blue fish.";
    string text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";
    
    int textLength = strlen(text);
    int numberOfWords = count_words(text, 0, textLength);
    printf("%i\n", numberOfWords);

    int numberOfSentencesss = count_sentences(text);
    printf("%i\n", numberOfSentencesss);
}

int count_sentences(string text)
{
    int textLength = strlen(text);
    int numberOfSentences = 0;
    int j = 0;
    for (int i = 0; i < textLength; i++)
    {   
        if ((int) text[i] == asciiOfDot || (int) text[i] == asciiOfQuestion || (int) text[i] == asciiOfExclm)
        {
            int numberOfWordsInThisSentence = count_words(text, j, i);
            if (numberOfWordsInThisSentence > 0)
            {
                j = i + 1;
                numberOfSentences++;            
            }
            j = i;
        }
    }
    return numberOfSentences;
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