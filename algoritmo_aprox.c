#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int min(int a, int b, int c)
{
	if(a <= b && a <= c)
	{
		return a;
	}
	else if(b <= a && b <= c)
	{
		return b;
	}
	else if(c <= a && c <= b)
	{
		return c;
	}
}

int levenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = min(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));

    return(matrix[s2len][s1len]);
}
void patternMatchingAprox(char *string, char *chave){
    int tamString=strlen(string), qtdPalavras=0, j, palavra, cont, menor;
    char substring[100];
    for(int i=0;i<tamString;i++){
        j=i;
        while(*(string+j) != ' ' && j<tamString){
            j++;
        }
        if(j>i){
            qtdPalavras++;
        }
        i=j;
    }
    int matriz[qtdPalavras][3];
    for(int i=0;i<tamString;i++){
        j=i;
        while(*(string+j) != ' ' && j<tamString){
            j++;
        }
        if(j>i){
            matriz[palavra][0] = i;
            matriz[palavra][1] = j;
            palavra++;
        i=j;
        }
    }
    for(int i=0;i<qtdPalavras;i++){
        cont=0;
        for(int k=matriz[i][0];k<matriz[i][1];k++){
            substring[cont]=*(string+k);
            cont++;
        }
        substring[cont] = '\0';
        matriz[i][2] = levenshtein(substring, chave);
        if(i==0){
            menor=matriz[i][2];
        }else{
            if(matriz[i][2] < menor){
                menor=matriz[i][2];
            }
        }
    }

    printf("As palavras mais parecidas sao: ");
    for(int i=0;i<qtdPalavras;i++){
        if(matriz[i][2] == menor){
            for(int k=matriz[i][0];k<matriz[i][1];k++){
                printf("%c", *(string+k));
            }
            printf(", ");
        }
    }
}

int main(){
    char string[100]="Bnn Beaneanea Binini Banana", chave[100]="Banana";
    patternMatchingAprox(string, chave);
    return 0;
}
