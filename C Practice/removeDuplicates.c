#include <stdio.h>
#define MAX_WORDS 100
#define MAX_WORDS_LENGTH 100
//gcc removeDuplicates.c -o a

void StringCpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int splitWords(char *sentence, char words[MAX_WORDS][MAX_WORDS_LENGTH])
{
    int i = 0, j = 0, wordCount = 0;

    while (sentence[i] != '\0')
    {
        // Skip delimiters
        while (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '?' || sentence[i] == '.' || sentence[i] == '!')
        {
            i++;
        }

        // Collect a word
        j = 0;
        while (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '?' && sentence[i] != '.' && sentence[i] != '!' && sentence[i] != '\0')
        {
            words[wordCount][j] = sentence[i];
            j++;
            i++;
        }
        words[wordCount][j] = '\0'; // Null terminate the word

        if (j > 0) // Only increment wordCount if we collected a word
        {
            wordCount++;
        }
    }

    return wordCount;
}

int compareWords(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void toLowerCase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
}

int removeDuplicates(char words[MAX_WORDS][MAX_WORDS_LENGTH], int wordCount)
{
    int i, j, k;
    char temp1[MAX_WORDS_LENGTH], temp2[MAX_WORDS_LENGTH];

    for (i = 0; i < wordCount; i++)
    {
        for (j = i + 1; j < wordCount; j++)
        {
            StringCpy(temp1, words[i]);
            StringCpy(temp2, words[j]);
            toLowerCase(temp1);
            toLowerCase(temp2);
            if (compareWords(temp1, temp2))
            {
                for (k = j; k < wordCount - 1; k++)
                {
                    StringCpy(words[k], words[k + 1]);
                }
                wordCount--;
                j--; // After removing, check the new word at this position
            }
        }
    }

    return wordCount;
}

void rebuildSentence(char words[MAX_WORDS][MAX_WORDS_LENGTH], int wordCount, char *sentence)
{
    int i = 0, j = 0, k;
    for (i = 0; i < wordCount; i++)
    {
        k = 0;
        // Copy each word into the sentence
        while (words[i][k] != '\0')
        {
            sentence[j] = words[i][k];
            j++;
            k++;
        }
        // Add a space after the word (except after the last word)
        if (i < wordCount - 1)
        {
            sentence[j] = ' ';
            j++;
        }
    }
    sentence[j] = '\0'; // Null terminate the sentence
}

int main()
{
    char sentence[] = "This is a test sentence test test with with duplicate duplicate words with.";
    char result[MAX_WORDS * MAX_WORDS_LENGTH];
    char words[MAX_WORDS][MAX_WORDS_LENGTH];
    int totalWords = 0;

    totalWords = splitWords(sentence, words);
    totalWords = removeDuplicates(words, totalWords);
    rebuildSentence(words, totalWords, result);

    printf("Original sentence: %s\n", sentence);
    printf("Processed sentence: %s\n", result);

    return 0;
}
