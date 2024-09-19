#include <stdio.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Function to check if two strings are equal
int areStringsEqual(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0; // Strings are not equal
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0'); // Both strings ended
}

// Function to copy one string to another
void stringCopy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to convert a character to lowercase (without ctype.h)
char toLowercase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

// Function to convert a string to lowercase
void toLowercaseString(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = toLowercase(str[i]);
        i++;
    }
}

// Function to split the sentence into words
int splitWords(char *sentence, char words[MAX_WORDS][MAX_WORD_LENGTH])
{
    int i = 0, j = 0, wordCount = 0;

    while (sentence[i] != '\0')
    {
        // Skip delimiters (spaces or punctuation)
        while (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            i++; // skip to the next iteration
        }

        // Extract the word
        j = 0;
        while (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.' && sentence[i] != '!' && sentence[i] != '?' && sentence[i] != '\0')
        {
            words[wordCount][j++] = sentence[i++];
        }
        words[wordCount][j] = '\0'; // Null terminate the word

        if (j > 0)
        {
            wordCount++; // Count the word only if it's not empty
        }
    }

    return wordCount;
}

// Function to remove duplicate words from the list
int removeDuplicates(char words[MAX_WORDS][MAX_WORD_LENGTH], int wordCount)
{
    int i, j, k;

    for (i = 0; i < wordCount; i++)
    {
        for (j = i + 1; j < wordCount; j++)
        {
            // Compare the two words, ignoring case
            char temp1[MAX_WORD_LENGTH], temp2[MAX_WORD_LENGTH];
            stringCopy(temp1, words[i]);
            stringCopy(temp2, words[j]);
            toLowercaseString(temp1);
            toLowercaseString(temp2);

            if (areStringsEqual(temp1, temp2))
            {
                // If duplicate, shift the remaining words left
                for (k = j; k < wordCount - 1; k++)
                {
                    stringCopy(words[k], words[k + 1]);
                }
                wordCount--; // Decrease the word count
                j--;         // Adjust the index to check the shifted word
            }
        }
    }

    return wordCount;
}

// Function to rebuild the sentence from the list of words
void rebuildSentence(char words[MAX_WORDS][MAX_WORD_LENGTH], int wordCount, char *result)
{
    int i, j = 0;

    for (i = 0; i < wordCount; i++)
    {
        int k = 0;
        while (words[i][k] != '\0')
        {
            result[j++] = words[i][k++];
        }
        if (i < wordCount - 1)
        {
            result[j++] = ' '; // Add space between words
        }
    }
    result[j] = '\0'; // Null terminate the result
}

int main()
{
    char sentence[] = "This is a test test sentence with duplicate duplicate words";
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char result[500];
    int wordCount;

    // Step 1: Split the sentence into words
    wordCount = splitWords(sentence, words);

    // Step 2: Remove duplicate words
    wordCount = removeDuplicates(words, wordCount);

    // Step 3: Rebuild the sentence without duplicates
    rebuildSentence(words, wordCount, result);

    // Output the result
    printf("Original sentence: %s\n", sentence);
    printf("After removing duplicates: %s\n", result);

    return 0;
}
