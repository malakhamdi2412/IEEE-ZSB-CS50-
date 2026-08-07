

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 676;
node *table[N];
unsigned int word_count = 0;
bool check(const char *word)
{
    
    unsigned int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}
unsigned int hash(const char *word)
{
    
    if (strlen(word) > 1 && isalpha(word[1]))
    {
        return (toupper(word[0]) - 'A') * 26 + (toupper(word[1]) - 'A');
    }

    return (toupper(word[0]) - 'A') % N;
}


bool load(const char *dictionary)
{
  
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

  
    char word[LENGTH + 1];

    
    while (fscanf(source, "%s", word) != EOF)
    {
    
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }

        
        strcpy(new_node->word, word);

      
        unsigned int index = hash(word);

      
        new_node->next = table[index];
        table[index] = new_node;

        
        word_count++;
    }

  
    fclose(source);
    return true;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
