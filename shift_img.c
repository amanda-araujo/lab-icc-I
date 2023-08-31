#include <stdio.h>

void gira_esq(int m, int n, int d, int img[m][n]);
void gira_cima(int m, int n, int b, int img[m][n]);

int main()
{
    int m, n, d, b;
    char charac;
    
    scanf("%d %d", &m, &n);
    scanf("%d %d", &b, &d);
    
    int img[m][n];

    int count=0;
    while(count < m*n){
        scanf("%c", &charac);
        
        if(32 <= charac && charac <= 126){
            int i = count/n;
            int j = count%n;

            img[i][j] = charac;
            count++;
        }
    }

    if(d != 0){
        gira_esq(m, n, d, img);
    }
    
    if(b != 0){
        gira_cima(m, n, b, img);
    }
    
    
    for(int i=0; i < m; i++){
        for(int j=0; j<n; j++){
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void gira_esq(int m, int n, int d, int img[m][n]){
    int swap_img[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            swap_img[i][j] = img[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            img[i][j] = swap_img[i][(j+d)%n];
        }
    }
}

void gira_cima(int m, int n, int b, int img[m][n]){
    int swap_img[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          swap_img[i][j] = img[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            img[i][j] = swap_img[(i+b)%m][j];
        }
    }
}
