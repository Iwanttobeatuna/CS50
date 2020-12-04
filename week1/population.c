#include <cs50.h>
#include <stdio.h>

//prompt user to input a number >9

int main(void)
{
    //get start size
    int s;
    do
    {
       s = get_int("Start size = "); 
    }
    while (s<9);
    
    //get end size
    int e;
    do
    {
      e = get_int("End size = ") ;
      
    }
    while (e<s);
    
    //keep track of years
    int years = 0;
    
    do
    {
     s = s + (s/3)-(s/4);
     years ++ ;
     
    }
    while (s<e);
    
    
   printf("Years: %i\n", years);
   
}
