#include <stdio.h>
#define MAX_WORDS 100
#define MAX_WORDS_LENGTH 100

int areWordsSame(char *str1, char *str2)
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

int splitWords(char words[MAX_WORDS][MAX_WORDS_LENGTH], char *sentence)
{
    int i = 0, j = 0, wordCount = 0;
    while (sentence[i] != '\0')
    {
        while (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.' ||
               sentence[i] == '?' || sentence[i] == '!')
        {
            i++;
        }

        j = 0;
        while (sentence[i] != '\0' && sentence[i] != ',' && sentence[i] != '.' &&
               sentence[i] != '?' && sentence[i] != '!' && sentence[i] != ' ')
        {
            words[wordCount][j] = sentence[i];
            j++;
            i++;
        }
        words[wordCount][j] = '\0';

        if (j > 0)
        {
            wordCount++;
        }
    }
    return wordCount;
}

int main()
{
    char sentence[500];
    char word[50];
    char words[MAX_WORDS][MAX_WORDS_LENGTH];
    int wordCount = 0, occurrences = 0;

    printf("Enter a sentence here: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("\nNow enter the word to count occurrences of: ");
    fgets(word, sizeof(word), stdin);

    // Remove newline character from the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == '\n')
        {
            word[i] = '\0';
        }
    }

    wordCount = splitWords(words, sentence);

    for (int i = 0; i < wordCount; i++)
    {
        if (areWordsSame(words[i], word))
        {
            occurrences++;
        }
    }

    printf("\n'%s' appears %d times in the sentence.\n", word, occurrences);

    return 0;
}
