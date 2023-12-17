#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        // Loop through each pixel in half of the row
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        // Loop through each pixel in half of the row
        for (int j = 0; j < width; j++)
        {
            // Initialize variables
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int count = 0;

            // Loop through each pixel in the 3x3 grid
            for (int k = -1; k < 2; k++)
            {
                // Check if the pixel is out of bounds
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }
                for (int l = -1; l < 2; l++)
                {
                    // Check if the pixel is out of bounds
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }
                    // Add the RGB values to the sum
                    sumBlue += image[i + k][j + l].rgbtBlue;
                    sumGreen += image[i + k][j + l].rgbtGreen;
                    sumRed += image[i + k][j + l].rgbtRed;
                    count++;
                }
            }
            // Calculate the average RGB values
            copy[i][j].rgbtBlue = round(sumBlue / (float) count);
            copy[i][j].rgbtGreen = round(sumGreen / (float) count);
            copy[i][j].rgbtRed = round(sumRed / (float) count);
        }
    }
    // Copy the blurred image to the original image
    for (int i = 0; i < height; i++)
    {
        // Loop through each pixel in half of the row
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
