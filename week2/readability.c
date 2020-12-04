#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //getting text from user
    string text = get_string("Text:");
    
    //defining initial variable
    float letters = 0;
    float words = 0;
    float sentences = 0;
    int space = 0;
    
    //calculating letters, words, and sentences
for(int i = 0 , n = strlen(text); i<n ; i++)
{
  if (isalpha(text [i]))
    {
         letters++ ;  
    }
  
    if (isspace(text [i]))
    {
        //concept from walkthrough video, where words = number of spaces +1
        space ++;
        words = space + 1;
    }
    
    if (text[i] == '.' || text [i]=='?' || text [i] =='!')
    {
        sentences ++;
    }
      
}
    
//Coleman-Liau index

//converting letters and words into L and S
float L = (100*letters)/words;
float S = (100*sentences)/words;


float index = 0.0588 * L - 0.296 * S - 15.8;
if (index >= 16)
{
    printf("Grade 16+\n");
}

else if (index <= 1)
{
    printf("Before Grade 1\n");
}
   
else
{
    printf("Grade %i\n", (int)round(index));
}
    
    
}
