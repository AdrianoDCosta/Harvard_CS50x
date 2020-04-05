#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int row = 0; row < height; row++) // Variable row is a row in the pyramid
    {
        // LEFT PYRAMID
        // Printing spaces
        for (int count = 0; count < height - row - 1; count++)
        {
            printf(" "); 
        }
        // Printing hashes
        for (int count = 0; count < row + 1; count++)
        {
            printf("#");
        }
        // New line
        printf("\n");
    }   
}
