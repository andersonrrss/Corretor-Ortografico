// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define N 26
unsigned int SIZE = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if(strlen(word) <= LENGTH)
    {
        for(node *tmp = table[toupper(word[0]) - 'A']; tmp != NULL; tmp = tmp->next)
        {
            if (strcasecmp(tmp->word, word) == 0)
            {
                return true;
            }

        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        return false;
    }
    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    char word[LENGTH +1];

    while (fscanf(file, "%s", word) != EOF)
    {
        // Calcula o valor de hash para a palavra
        unsigned int index = hash(word);

        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(tmp->word, word);
        tmp->next = table[index];
        table[index] = tmp;
        SIZE++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return SIZE;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *tmp;
    for(int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }

    free(tmp);
    for(int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            return false;
        }
    }

    return true;
}