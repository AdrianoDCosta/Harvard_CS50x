#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int letters = 0, words = 1, sent = 0;
    string text = get_string("Type your text: ");
	
// count
    for (int i = 0; i < strlen(text); i++)
    {   
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) // just letters uppercase or lowercase
        {
            letters++;
        }   
        else if (text[i] == ' ') // se tiver espaço, acrescente +1 na contagem de palavras
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.') // se tiver ! ? ou . acrescente +1 na contagem de frases 
        {
            sent++;
        }
    }
    
// Readability test - Coleman-Liau index | index = 0.0588 * L - 0.296 * S - 15.8
    float grade = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sent / (float) words) - 15.8;
// Printing
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else
    {
        printf("Before Grade 1\n");
    }
}