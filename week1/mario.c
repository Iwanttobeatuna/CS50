#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for height
    int height;
    
    do{
          height = get_int("Height = "); 
    }
    while (height > 8 || height < 1);  

    //building the pryramid
    
    for (int x = 0; x < height; x++)                // defining rows (x-axis)
    {

        
        for (int z = 0; z < (height - x - 1); z++)  // building dots/space, relationship found: the spaces needed =  height - x -1
        {
            printf(" ");
        }
      
        for (int y = 0; y < x+1; y++)               //building for #
        {
           printf ("#");  
        }
    
    printf("\n");                                   //print out new lines
       
    }
}
