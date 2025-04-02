#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Variavel global
char binarioResul[30] = "";

int somaBin()
{
    //Variaveis utilizadas
    
    int nb1;
    int nb2; 

    //Pega valor do usuario
    printf("Insira o valor: ");
    scanf("%d", &nb1);

    printf("Insira o outro valor: ");
    scanf("%d", &nb2);

    int soma = nb1 + nb2;
    int carry = 0;

    while (soma > 0)
    {
        int ultimoDG = soma % 10; //Extrai o ultimo digito
        soma = soma / 10; //Remove o ultimo digito                                                                        

        //Faz a conversão de binario somente para os numeros 1 ,2, 3
        int co, res;
        co = ultimoDG / 2;
        res = ultimoDG % 2;
        
        //Extrai e elimina o ultimo digito
        carry = (co * 10) + res;
        ultimoDG = carry % 10;
        carry = carry / 10; 
        
        //Converte o ultimo digito para o char
        char temp[4];
        sprintf(temp, "%d", ultimoDG);

        // Move os caracteres existentes para a direita
        memmove(binarioResul + 1, binarioResul, strlen(binarioResul) + 1);
        // Adiciona o novo dígito no início
        binarioResul[0] = temp[0];

        soma = soma + carry;
    }
    printf("Soma: %s\n", binarioResul);
    return 0;
}

int converBinario()
{
    
}

int main()
{
    somaBin();
    return 0;
}