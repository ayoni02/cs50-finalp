// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_value = hash(word);
    // Iterate over the linked list at the hash value
    node *current = table[hash_value];
    while (current != NULL)
    {
        if (strcasecmp(word, current->word) == 0) //strcmp was what i uysed before
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += toupper(word[i]);
    }return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char next_word[LENGTH + 1];
    while (fscanf(file, "%s", next_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, next_word);
        int hash_value = hash(next_word);
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }
    // Close file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
        for (unsigned int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
        node *next = current->next;
        free(current);
        current = next;
        }

        table[i] = NULL;
    }
    return true;
}
