#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PatternMatchingExato(char string[], char chave[]){
    int tamstring=strlen(string), tamchave=strlen(chave), ocorrencia=0;
    for (int i = 0; i <= tamstring - tamchave; i++) {
        int count = 0;
        for (int j = 0; j < tamchave; j++) {
            if (chave[j] == string[i + j]) {
                count++;
            }
        }
        if (count == tamchave) {
            ocorrencia++;
        }
    }
    if(ocorrencia!=0){
        printf("Presente!");}
    else{
        printf("Não presente!");
    }
}


int main(){
    char string[10000], chave[10000];
    printf("Digite string: ");
    gets(string);
    printf("Digite chave: ");
    gets(chave);
    PatternMatchingExato(string, chave);
    return 0;
}