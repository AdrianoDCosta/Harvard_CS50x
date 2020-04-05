#include <helpers.h>
#include <math.h>
#include <string.h>

// Converte a imagem em escala de cinza (Convert image to grayscale)
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Colunas da imagem (collumns od the image)
    for (int collumn = 0; collumn < width; collumn++)
    {
        // Linhas da imagem (rows of the image)
        for (int row = 0; row < height; row++)
        {
            // Obtem os valores de  Red, Green, Blue
            int colorRed = image[collumn][row].rgbtRed;
            int colorGreen = image[collumn][row].rgbtGreen;
            int colorBlue = image[collumn][row].rgbtBlue;

            // Média calculada (At this point the average is calculated with round)
            int calcAver = round((colorRed + colorGreen + colorBlue) / 3.0);

            // Define os valores médio para rgb (define RGB values to the average)
            image[collumn][row].rgbtRed = calcAver;
            image[collumn][row].rgbtGreen = calcAver;
            image[collumn][row].rgbtBlue = calcAver;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Colunas da imagem (collumns od the image)
    for (int collumn = 0; collumn < width; collumn++)
    {
        // Linhas da imagem (rows of the image)
        for (int row = 0; row < height; row++)
        {
            // Obtem os valores de Red, Green, Blue
            int colorRed = image[collumn][row].rgbtRed;
            int colorGreen = image[collumn][row].rgbtGreen;
            int colorBlue = image[collumn][row].rgbtBlue;

            // formula used to obtain sepia values according to current RGB
            int sepRed = round(0.393 * colorRed + 0.769 * colorGreen + 0.189 * colorBlue);
            int sepGreen = round(0.349 * colorRed + 0.686 * colorGreen + 0.168 * colorBlue);
            int sepBlue = round(0.272 * colorRed + 0.534 * colorGreen + 0.131 * colorBlue);

            // Define os valores RGB para sepia (define RGB values to the Sepia)
            image[collumn][row].rgbtRed = fmin(255, sepRed);
            image[collumn][row].rgbtGreen = fmin(255, sepGreen);
            image[collumn][row].rgbtBlue = fmin(255, sepBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary;

    // Colunas da imagem (collumns od the image)
    for (int collumn = 0; collumn < width / 2; collumn++)
    {
        // Linhas da imagem (rows of the image)
        for (int row = 0; row < height; row++)
        {
            temporary = image[row][collumn];
            image[row][collumn] = image[row][width - collumn - 1];
            image[row][width - collumn - 1] = temporary;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary[height][width];

    memcpy(temporary, image, sizeof(RGBTRIPLE) * height * width);

    // Linhas da imagem (rows of the image)
    for (int row = 0; row < height; row++)
    {
        // Colunas da imagem (collumns of the image)
        for (int collumn = 0; collumn < width; collumn++)
        {
            float calcAver = 0.0;

            // setando valores de RGB para 0 (setting RGB values to the 0)
            int colorRed = 0;
            int colorGreen = 0;
            int colorBlue = 0;

            for (int overrows = -1; overrows <=1; overrows++)
            {
                for (int overcolluns = -1; overcolluns <= 1; overcolluns++)
                {
                    // Coluna e linha atual (current collum and row)
                    if (row + overrows != height &&
                        row + overrows != -1 &&
                        collumn + overcolluns != width &&
                        collumn + overcolluns != -1)
                    {
                        colorRed += temporary[row + overrows][collumn + overcolluns].rgbtRed;
                        colorGreen += temporary[row + overrows][collumn + overcolluns].rgbtGreen;
                        colorBlue += temporary[row + overrows][collumn + overcolluns].rgbtBlue;

                        calcAver++;
                    }
                }
            }
            image[row][collumn].rgbtRed = round(colorRed / calcAver);
            image[row][collumn].rgbtGreen = round(colorGreen / calcAver);
            image[row][collumn].rgbtBlue = round(colorBlue / calcAver);
        }
    }
}