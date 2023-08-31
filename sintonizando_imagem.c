#include <stdio.h>

/*O formato da entrada será o seguinte:
M N
B D
linha[0]   <N colunas>
linha[...] <N colunas>
linha[M-1] <N colunas>*/

void girar_esq(int m_linhas, int n_colunas, int D, int imagem[m_linhas][n_colunas], int nova_imagem[m_linhas][n_colunas]);
void girar_cima(int m_linhas, int n_colunas, int B, int imagem[m_linhas][n_colunas], int nova_imagem[m_linhas][n_colunas]);

int main(void){

    //Leitura:
    int m_linhas, n_colunas, B, D;
    scanf("%d %d", &m_linhas, &n_colunas); 
    scanf("%d %d", &B, &D);

    //leitura matriz:
    int imagem[m_linhas][n_colunas];
    int nova_imagem[m_linhas][n_colunas];

    int caracteres = 0, i, j;
    int total = m_linhas * n_colunas;
    char caract;

    while(caracteres < total){
        
        scanf("%c", &caract);

        //char conhecidos: 32 (espaço) - 126
        if (caract >= 32 && caract <= 126){
            
            i = caracteres / n_colunas;
            j = caracteres % n_colunas;
            
            imagem[i][j] = caract; 

            caracteres++;
        }
    }

    //Giros:
    if(D != 0){
        girar_esq(m_linhas, n_colunas, D, imagem, nova_imagem);
    }

    if(B != 0){
        girar_cima(m_linhas, n_colunas, B, nova_imagem, imagem);
    }

    //Print:
    for(int i = 0; i < m_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            printf("%c", imagem[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void girar_esq(int m_linhas, int n_colunas, int D, int imagem[m_linhas][n_colunas], int nova_imagem[m_linhas][n_colunas]){
    
    //Giro:
    for(int i = 0; i < m_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            int j_novo = (j + D) % n_colunas;
            nova_imagem[i][j] = imagem[i][j_novo];
        }
    }
}

void girar_cima(int m_linhas, int n_colunas, int B, int imagem[m_linhas][n_colunas], int nova_imagem[m_linhas][n_colunas]){
    
    //Giro:
    for(int i = 0; i < m_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            int i_novo = (i + B) % m_linhas;
            nova_imagem[i][j] = imagem[i_novo][j]; 
        } 
    }
}