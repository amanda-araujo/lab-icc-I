#include <stdio.h>
#include <string.h>

#define max_char 76
#define n_palavras_spam 12
#define max_tam_palavra 20

int main(void){

    char palavras_spam[n_palavras_spam][max_tam_palavra] = {{"gratuito"},
                                                {"atencao"},
                                                {"urgente"},
                                                {"imediato"},
                                                {"zoombie"},
                                                {"oferta"},
                                                {"dinheiro"},
                                                {"renda"},
                                                {"fundo"},
                                                {"limitado"},
                                                {"ajuda"},
                                                {"SOS"}};
  
    int spam = 0;
    char linha[max_char];
    
    //Leitura: 
    //Seu programa deverá analisar as palavras linha a linha. 
    //Atenção: Seu programa deverá ler até o final da entrada, isso é, até o EOF.
    while(scanf(" %[^\n]", linha) != EOF){ //ler tudo}

        /*emails com linhas de mais de 76 caracteres não são confortáveis de
        serem lidos e, por conta disso, também devem ser descartados como spam.*/
        if(strlen(linha) > max_char){
            spam++;
        }
        
        // checando ocorrência das palavras proibidas:
        for(int i = 0; i < n_palavras_spam; i++){

            //strstr: busca string em string, retorna posição do começo da palavra
            if(strstr(linha, palavras_spam[i]) != NULL){
                //palavra proibida presente 
                spam++;
            }    
        }
    }

    //Ao final da leitura completa:
    /* se um email possui duas ou mais dessas palavras, ele é automaticamente descartado como spam. */
    if(spam >= 2){
        printf("Spam");
    }   
    else{
        printf("Inbox");
    }

    return 0;
}