#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = get_int("Number of scores: ");
    int scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }
    printf("Acerage: Teste\n");
}