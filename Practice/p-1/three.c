#include <stdio.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int main()
{
    char sentence[] = "This is a sample sentence sample.";
    char words[MAX_WORDS][MAX_LENGTH];
    int wordIndex = 0, letterIndex = 0;

    // Step 1: Split the sentence into words manually
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] != ' ')
        {
            words[wordIndex][letterIndex++] = sentence[i];
        }
        else
        {
            words[wordIndex][letterIndex] = '\0'; // Null-terminate the word
            wordIndex++;
            letterIndex = 0;
        }
    }
    words[wordIndex][letterIndex] = '\0'; // Null-terminate the last word
    int totalWords = wordIndex + 1;

    // Step 2: Remove duplicates
    for (int i = 0; i < totalWords; i++)
    {
        for (int j = i + 1; j < totalWords; j++)
        {
            // Compare words[i] and words[j]
            int k = 0;
            while (words[i][k] == words[j][k] && words[i][k] != '\0' && words[j][k] != '\0')
            {
                k++;
            }
            // If the two words are identical
            if (words[i][k] == '\0' && words[j][k] == '\0')
            {
                // Shift all subsequent words left by one
                for (int l = j; l < totalWords - 1; l++)
                {
                    int m = 0;
                    while ((words[l][m] = words[l + 1][m]) != '\0')
                    {
                        m++;
                    }
                }
                totalWords--; // Reduce the total word count
                j--;          // Recheck the current index after shifting
            }
        }
    }

    // Step 3: Output the unique words
    printf("The unique words in the sentence are:\n");
    for (int i = 0; i < totalWords; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}
