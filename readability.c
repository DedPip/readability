#include "./libs/cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int count_letters(string text);
int count_words(string text, int start, int end);
int count_sentences(string text);

const int asciiOfDot = 46, asciiOfBlank = 32, asciiOfComma = 44, asciiOfQuestion = 63, asciiOfExclm = 33;

int main(void)
{
    string text = get_string("Text: ");
    
    int textLength = strlen(text);
    int numberOfLetters = count_letters(text);
    int numberOfWords = count_words(text, 0, textLength);
    int numberOfSentences = count_sentences(text);
    
    // l is the average number of letters per 100 words
    float l = ((float) (numberOfLetters * 100)) / numberOfWords;

    //s is the average number of sentences per 100 words
    float s = ((float) (numberOfSentences * 100)) / numberOfWords;

    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    int index_rounded = round(index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index_rounded);
    }
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