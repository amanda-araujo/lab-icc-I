#include <stdio.h>

int main(){

printf("%d \n", (int)sizeof(unsigned char));
printf("%d \n", (int)sizeof(char));
printf("%d \n", (int)sizeof(unsigned int));
printf("%d \n", (int)sizeof(short int));
printf("%d \n", (int)sizeof(int));
printf("%d \n", (int)sizeof(long int));
printf("%d \n", (int)sizeof(unsigned long int));
printf("%d \n", (int)sizeof(long long int));
printf("%d \n", (int)sizeof(float));
printf("%d \n", (int)sizeof(double));
printf("%d \n", (int)sizeof(long double));
return 0;
}

/*
#include <stdio.h>
int main(void)
{
  float vteste;
  printf(" --- TIPO ---|--- BYTES ---\n");
  printf(" char .......: %d bytes\n", sizeof(char));
  printf(" short.......: %d bytes\n", sizeof(short));
  printf(" int.........: %d bytes\n", sizeof(int));
  printf(" long........: %d bytes\n", sizeof(long));
  printf(" float ......: %d bytes\n", sizeof(float));
  printf(" double......: %d bytes\n", sizeof(double));
  printf(" long double.: %d bytes\n\n", sizeof(long double));
  printf("\nO tamanho de vteste e...: %d \n\n",sizeof vteste);
  
  return 0;
}
*/