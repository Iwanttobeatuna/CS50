#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //check the command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //open the card file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open \n");
        return 1;
    }
    
    //create buffer
    //initialize
    //boolean for first jpag
    typedef uint8_t BYTE;
    int block_size = 512;
    BYTE bytes[block_size];
 
    FILE *image;
    char filename [100];
    int image_count = 0;
    
    // boolean expression to false
    bool first_jpeg = false;
    bool found_jpeg = false;
    
    while (true)
    {
        //repeat until 512 bytes into buffer
        if (fread(bytes, sizeof(BYTE), block_size, file) == 0)
           {
            break; 
            }
        
        //if the start of a new jpag
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff  && (bytes[3] & 0xf0) == 0xe0)
        {
            found_jpeg = true ;
            //if it is the first jpag
            if (first_jpeg == false)
            {
                //write new jpeg
                first_jpeg = true;
            }
            else
            {
                //close the current file
                fclose(image);
                
            }
            //open new file
            sprintf(filename, "%03i.jpg", image_count);
            image = fopen(filename, "w");
            fwrite(bytes, sizeof(BYTE), block_size, image);  
            image_count ++;
        
        }   
            
        else
        {
            //if already found jpag
            if (found_jpeg)
            {
                //keep writing to jpag
                fwrite(bytes, sizeof(BYTE), block_size, image);  
            }
        
            
        }


    }
    
    fclose(file);
    fclose(image);
    
    return 0;
   
  
}
    
