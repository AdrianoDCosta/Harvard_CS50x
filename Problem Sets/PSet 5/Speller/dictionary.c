// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Number of buckets (hash table (hash_tb) )
#define ALPHAB 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Hash table (hash_tb)
node *hash_tb[ALPHAB];

unsigned int dictionary_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char temp_word[LENGTH + 1] = {'\0'}; ////////////////////////////////////////////////////

    for (int i = 0; word[i]; i++)
    {
        temp_word[i] = word[i];
    }
    // Convert to LOWER CASE
    for (int i = 0; temp_word[i]; i++)
    {
        temp_word[i] = tolower(temp_word[i]);
    }

    int position = hash(temp_word);
    node *pointer = hash_tb[position];

    while (true)
    {

        for (int i = 0; i <= LENGTH; i++)
        {
            // Compare characters
            if (pointer->word[i] != temp_word[i])
            {
                break;
            }
            if (i == LENGTH)
            {
                return true;
            }
        }
        if (!pointer->next)
        {
            return false;
        }
        pointer = pointer->next;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // start hash table (hash_tb)
    for (int i = 0; i < ALPHAB; i++)
    {
        hash_tb[i] = NULL;
    }

    // Open the DIC
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    char word[LENGTH + 1];

    // in this point, Insert words in hash_tb
    while (fscanf(file, "%s", word) != EOF)
    {
        dictionary_size ++;
        int position = hash(word);

        node *new_word = malloc(sizeof(node));
        memset(new_word->word, '\0', sizeof(word));


        //insert words into hash_tb
        if (hash_tb[position])
        {
            for (int i = 0; word[i]; i++)
            {
                new_word->word[i] = word[i];
            }
            new_word->next = hash_tb[position];
            hash_tb[position] = new_word;

        }
        else
        {
            hash_tb[position] = new_word;
            for (int i = 0; word[i]; i++)
            {
                new_word->word[i] = word[i];
            }

            new_word->next = NULL;
        }

    }


    printf("Loaded %u words\n", dictionary_size);
    // Here, close DIC
    fclose(file);

    return true;
}

unsigned int size(void)
{
    // Here, returns number of words in dic
    return dictionary_size;
    return 0;
}
bool unload(void)
{
    // TODO
    for (int i = 0; i < ALPHAB; i++)
    {
        node *pointer = hash_tb[i];

        while (pointer)
        {
            node *temp = pointer;
            pointer = pointer->next;
            free(temp);
        }
    }
    return true;
}
