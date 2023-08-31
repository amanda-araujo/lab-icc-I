#include <stdio.h>

#define tam_max 10
#define n_destinos 4
#define dia_terra (60*60*24)

/*um programa que receberá um inteiro contendo o total de segundos
 gasto na viagem e uma string contendo o nome do planeta de destino.*/

/* O dia terrestre para 24 horas = 60(s) * 60(min) * 24(h) = 86400
O dia em Vênus equivale a 243 dias terrestres.
O dia em Mercúrio equivale a 58 dias e 16 horas terrestes.
O dia em Júpiter equivale a 9 horas e 56 minutos terrestres*/

void horario_interplanetar(char destino, unsigned long long int t_seg, unsigned long long int *dias, unsigned long long int *horas, unsigned long long int *minutos, unsigned long long int *segundos){
    //1 dia : 24 horas : 60 minutos : 60 segundos
    //Decobre duração do dia no planeta / 24 (horas) / 60 (minutos) + resto (segundos)

    //int dia_venus_seg = 20995200;
    //pensar com índices! 
    //d, h, m, s

    switch (destino) //Switch case não funciona para strings! (para char OK) :: planeta_destino direto dá ruim
    {
    case 'T':
        //Terra:
        *dias = t_seg / dia_terra; //86400 : 1 dia  Terra;
        *horas = (t_seg % dia_terra) / (60*60);//3600: 1 hora Terra;
        *minutos = ((t_seg % dia_terra) % 3600) / 60;
        *segundos = ((t_seg % dia_terra) % 3600) % 60;
        break;

    case 'V':
        //Vênus:
        *dias = t_seg / (243 * dia_terra); //ok
        *horas = (t_seg % (243 * dia_terra)) / 3600;
        *minutos = ((t_seg % (243 * dia_terra)) % 3600) / 60;
        *segundos = ((t_seg % (243 * dia_terra)) % 3600) % 60;
        break;
    
    case 'M':
        //Mercúrio: 
        *dias = t_seg / (58 * dia_terra + 16 * 60*60); //1 dia Mercúrio: 58 dias 16h = (58 * dia_terra + 16 * 60*60)s 
        *horas = (t_seg % (58 * dia_terra + 16 * 60*60)) / 3600;
        *minutos =  ((t_seg % (58 * dia_terra + 16 * 60*60)) % 3600) / 60;
        *segundos = ((t_seg % (58 * dia_terra + 16 * 60*60)) % 3600) % 60;
        break;

    case 'J':
        //Júpiter:
        *dias = t_seg / (9 * 60*60 + 56 * 60); //9h56'
        *horas = (t_seg % (9 * 60*60 + 56 * 60)) / 3600;
        *minutos = ((t_seg % (9 * 60*60 + 56 * 60)) % 3600) / 60;
        *segundos = ((t_seg % (9 * 60*60 + 56 * 60)) % 3600) % 60;
        break;
    
    default:
        break;
    }
}


int main(void){

    //Leitura:
    unsigned long long int t_seg;
    char planeta_destino[tam_max]; 
    scanf("%llu %s", &t_seg, planeta_destino);

    //Horário interplanetar:
    unsigned long long int dias = 0, horas = 0, minutos = 0, segundos = 0;
    char destino = planeta_destino[0];
    horario_interplanetar(destino, t_seg, &dias, &horas, &minutos, &segundos);
    
    //Print:
    printf("%llu segundos no planeta %s equivalem a:\n", t_seg, planeta_destino);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", dias, horas, minutos, segundos);

    return 0;
}