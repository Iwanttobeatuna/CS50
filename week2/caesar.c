#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
 if (argc == 2 && isdigit(*argv[1]))
 {
 // converting string into integer, k = secret key as defined in equation
  int k = atoi (argv [1]);
  
  //get plaintext from user
  string text = get_string ("plaintext: ");
  
  //Encipher text
  //Details for ASCII-compatible equation : https://docs.google.com/document/d/16_o3UtcEAfKSJXHyVpsiYDsfv4nYiL0emVO2d85V4ao/edit?usp=sharing
  printf ("ciphertext: ");
  for (int i=0, n=strlen (text); i<n ; i++)
  {
    // converting'a' to enciphed text with ascii a = 97
    if ((int)(text[i]) >= 97 && (int)(text[i]) <= 122)
    {
    text[i] = (((int)(text[i]) - 97 + k ) % 26) + 97;
    
    
   // converting'A' to enciphed text with ascii A = 65
    }
    else if((int)(text[i]) >= 65 && (int)(text[i]) <= 90)
    {
     text[i] = (((int)(text[i]) - 65 + k ) % 26) + 65;
    }
    
    // reamin others as it is
    else
    {
     text [i] = text [i];
    }
    
    //print encipher text
    printf ("%c", (char)text[i]);
    
  }
   printf ("\n");
   return 0;
  
 }

 else 
 {
     printf ("Usage: ./caesar key \n");
     return 1;
 }
 
}
