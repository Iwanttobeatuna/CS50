// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 150000;

// Hash table
node *table[N];

//initialize word count 
int count = 0;

unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    
    //hash word to obtain hash value
    hash_value = hash(word);
    
    //set cursor to the first item 
    node *cursor = table [hash_value];
    
    // move cursor until NULL, if found, return true, or not move on.
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor ->word) == 0)
        {
            // return true if found
            return true;
        }
        else
        {
            //move the cursor to the next node
            cursor = cursor -> next;
            
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    /* Source :
    https://www.partow.net/programming/hashfunctions/#DJBHashFunction
    https://stackoverflow.com/questions/7700400/whats-a-good-hash-function-for-english-words
    http://www.cse.yorku.ca/~oz/hash.html
     */
    //dJB Hash Function
    //Tried with different hash function, it produces the same result
     
    unsigned int hash = LENGTH;
    unsigned int i    = 0;
    while ((i = tolower(*word++)))
    {
       hash = ((hash << 5) + hash) + (tolower(*word));
    }

    return hash % N;
    
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file for reading
    FILE *file = fopen(dictionary, "r");
    //define base case
    if (file == NULL)
    {
        return false;
    }
    
    // maximum 
    char word [LENGTH + 1];
    
    //Read string from a file 
    while (fscanf(file, "%s", word) != EOF)
    {
        //create new node for each word
        
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //copy word into new node
        strcpy(n -> word, word);
        n -> next = NULL;
        
        //get hash bucket
        int bucket = hash(word);
        //empty bucket
        if (table[bucket] == NULL)
        {
            //insert new node
            table [bucket] = n;
            count ++;
        }
        else
        {
            //as explained in walkthrough : 
            //set the n->next to the word
            //set the word = new node
            // count ++ 
            n -> next = table [bucket];
            table[bucket] = n;
            count ++ ;
        }
    }
    
    //close file
    fclose(file);
  
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //iterate through all buckets
    for (int i = 0; i < N; i++)
    {
        //
        node *cursor = table[i];
        
        //repeat until null
        while (cursor != NULL)
        {
            // get a temp to store temporary 
            node *tmp = cursor;
            // move cursor to the next node
            cursor = cursor -> next;
            //free tmp
            free(tmp);
            
        }
        // when it is NULL, indicates all have been freed
        
    }
    return true;
}
