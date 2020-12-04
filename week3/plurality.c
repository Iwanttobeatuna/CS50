
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    
    // repeat for every candidate, and if name = candidate name, add one vote, then return true, and else return false.
    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // INSTRUCTOR's note: use !strcmp instead of checking if it is == 0 in general use !x instead of x == 0
            candidates[i].votes++;
            return true; 
        }
    } 
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // first find max vote: to find max vote, set initial max vote as 0, and update max vote, if candidates[i].votes>maxvotes, check for all the candidates (loop)
    int maxvotes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
    // set initial maximum number of vote = 0
    
        if(candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    
    //printing the winner
    for (int i = 0; i < candidate_count; i++)
    {
        // maxvotes =winner, print the candidates names
        if(candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    
    }
    return;
