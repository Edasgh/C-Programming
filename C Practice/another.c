#include <stdio.h>
#include <string.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

const char vowels[]="aeiou";

//gcc another.c -o a

int isVowel(char c)
{
  int j;
  for(j=0;j<5;j++)
  {
    if(c == vowels[j])
    {
        return 1;
    }
  }
  return 0;
}

int findVowelPairs(char *str , int size)
{
    int i = 0, count = 0;

    while (i < size - 1)
    {
        // Check for a pair of vowels
        if (isVowel(str[i]) && isVowel(str[i + 1]))
        {
            // Remove the pair
            for (int j = i; j < size - 1; j++)
            {
                str[j] = str[j + 2]; // Shift left by 2
            }
            str[size - 2] = '\0'; // Null-terminate the modified string
            size -= 2;            // Reduce the size by 2
            count++;                // Increment the count of vowel pairs
            // Stay at the same index to check for new pairs formed
        }
        else
        {
            i++; // Move to the next character
        }
    }

    return count;
}

int findTotalVowelPairs(char words[MAX_WORDS][MAX_WORD_LENGTH],int wordCount)
{
    int i=0 , vowelPairsCount=0;
    int size;
    for(i=0;i<wordCount;i++)
    {
        size = strlen(words[i]);
        vowelPairsCount+=findVowelPairs(words[i],size);
    }

    return vowelPairsCount;
}

int splitWords(char *sentence , char words[MAX_WORDS][MAX_WORD_LENGTH])
{
    int i=0,j=0,wordCount =0;

    while(sentence[i]!='\0')
    {
        while(sentence[i]==' '||sentence[i]==','||sentence[i]=='.'||sentence[i]=='?'||sentence[i]=='!')
        {
            i++;
        }
        j=0;
        while (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.' && sentence[i] != '?' && sentence[i] != '!' && sentence[i]!='\0')
        {
          words[wordCount][j] = sentence[i];
          j++;
          i++;
        }
         
        words[wordCount][j] = '\0';
        if(j>0)
        {
            wordCount++;
        }

    }

    return wordCount;
}

void rebuildSentence(char words[MAX_WORDS][MAX_WORD_LENGTH],char *sentence , int wordCount)
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


void main()
{

    char sentence[]="Did you cook this delicious meat?";
    int size;
    size = strlen(sentence);
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char result[MAX_WORDS * MAX_WORD_LENGTH];
    int wordCount=0,vowelPairs=0;
    wordCount = splitWords(sentence,words);
    vowelPairs = findTotalVowelPairs(words,wordCount);
    rebuildSentence(words,result,wordCount);

    printf("\nOriginal Sentence : %s\n ",sentence);
    printf("\nProcessed Sentence : %s\n ",result);
    printf("\nTotal vowel pairs count : %d",vowelPairs);

}