#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over each pixel
    //define the current_pixel in the 2D array (from bmp.h - RGBTRIPLE typedef)
    //average the current_pixel(currentpxl) to find the grayscale (stated in the instruction)
    //set the value of average calculated to the currentpxl of the 2D array

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE currentpxl = image [i][j];
            int avg = round((currentpxl.rgbtBlue + currentpxl.rgbtRed + currentpxl.rgbtGreen) / 3.0);
            image [i][j].rgbtBlue = image [i][j].rgbtRed = image [i][j].rgbtGreen = avg;
            }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over each pixel
    // define the current pixel
    // apply formula
    //set the pixel to the formula
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE currentpxl = image [i][j];
            int sepiaRed = round(.393 * currentpxl.rgbtRed  + .769 * currentpxl.rgbtGreen + .189 * currentpxl.rgbtBlue);
            int sepiaGreen = round(.349 * currentpxl.rgbtRed  + .686 * currentpxl.rgbtGreen + .168 * currentpxl.rgbtBlue);
            int sepiaBlue = round(.272 * currentpxl.rgbtRed  + .534 * currentpxl.rgbtGreen + .131 * currentpxl.rgbtBlue );

            if (sepiaBlue >= 255)
            {
                image [i][j].rgbtBlue = 255;
            }
            else
            {
                  image [i][j].rgbtBlue = sepiaBlue;
            }
            
            if (sepiaRed >= 255)
            {
                image [i][j].rgbtRed = 255;
            }
            else
            {
                image [i][j].rgbtRed = sepiaRed;
            }
            
            if (sepiaGreen >= 255)
            {
                image [i][j].rgbtGreen = 255;
            }
            else
            {
                image [i][j].rgbtGreen = sepiaGreen;
            }


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image [i][j];
            image [i][j] = image [i][width - j - 1];
            image [i][width - j - 1] = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
//Thanks to Lucy from tutorial for shorter code suggestions!
    
    //create a temporary value
    RGBTRIPLE temp[height][width];
    
    //iterate through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //setting initial constants
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            int count = 0;
            int x_coord[] = {i - 1, i, i + 1};
            int y_coord[] = {j - 1, j, j + 1};
            
            //examine around the pixel 
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    //define current x & y coordinate (ie: current pixel)
                    int curX = x_coord[x];
                    int curY = y_coord[y];
                    
                    //examine around the pixel
                    if (curX >= 0 && curY >= 0 && curX < height  && curY < width)
                    {
                        RGBTRIPLE pixel = image[curX][curY];
                        
                        //calculate total of all the adjacent pixels
                        totalRed += pixel.rgbtRed;
                        totalGreen += pixel.rgbtGreen;
                        totalBlue += pixel.rgbtBlue;
                      
                        count ++;
                      
                    }
                }
            }       
            //apply formula
            temp[i][j].rgbtRed = round(totalRed / count);
            temp[i][j].rgbtGreen =  round(totalGreen / count);
            temp[i][j].rgbtBlue = round(totalBlue / count);
            
        }
    }
    
    //copy back the temp value to image value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //assiging temp value to original image
            image [i][j] = temp [i][j];
            
        }
    }
       
    return;
}
