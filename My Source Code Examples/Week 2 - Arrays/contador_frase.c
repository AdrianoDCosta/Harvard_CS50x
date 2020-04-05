/* 
Reference
    https://www.clubedohardware.com.br/forums/topic/802455-resolvido-contador-de-palavrasletras/
*/

#include <stdio.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	int count, letters = 0, words = 0, in_words = 0;
    char phrase[999];
    printf ("Digite uma frase: \n");
    fgets(phrase, 999, stdin);
    
    for(count=0;phrase[count];count++)
    {
        if((!in_words)&&(phrase[count]-' '))
        {
            in_words = 1;
            words++;
        }
        if((phrase[count]-' ')&&(phrase[count]-'.')&&(phrase[count]-','))
        {
            letters++;
        }
        else
        {
            in_words = 0;
        }
    }
	printf("Quantidade de Letras Contidas na Frase:  %d\n Quantidade de Palavras: %d\n você digitou: %s DENTRO: %i", letters, words, phrase, in_words);
    //system("pause"); //aguardar o usuário pressionar alguma tecla
}