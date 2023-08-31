#include <stdio.h>

int main(void){
    int a = 0;
    while (a < 4){
        if (a < 3){
            printf("a menor q 3\n");
        }
        else{
            printf("a maior q 3\n");
        }
        a++;
    }
}