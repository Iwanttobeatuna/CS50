#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int get_positive_int (void);

int main (void)
{
    //total number of positive number
    int n = get_positive_int ("Total number of positive intergers: ");
    
    // get the individual positive number'
    int number [n];
    for (int i =0; i<n; i++) 
    {
        number[i] = get_positive_int ("Number:%i", i+1);
        
    }
    
    int biggest = number [0]
    
    for (int j = 0  ; j <n ; j++)
    {
        if (biggest < number [n])
        {
            biggest = number [n] ;
        }
    }
    
    printf ("Number of highest number : %i", biggest);
}
