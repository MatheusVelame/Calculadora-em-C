/*
* Autor: Matheus Velame Pessoa
* Período: 3º A
* Disciplina: Infraestrutura de Hardware
* Atividade: Calculadora didática de conversão entre bases e ponto flutuante de precisão simpes e dupla
* Data: 30/08/2024
* Link do Repositório: https://github.com/MatheusVelame/Calculadora-em-C.git
*
* Revisões e atualizações:
* Thu Aug 29 10:23:59
* Fri Aug 30 19:13:54
* Fri Aug 30 18:18:59
* Fri Aug 30 18:09:28
* Fri Aug 30 17:53:51
* Fri Aug 30 19:37:10
*/

#include <stdio.h>

void decimal_float(double numero_decimal);
void decimal_double(double numero_decimal);

int main(){

    double numero_decimal;

    printf("\nObs.: Nesse passo a passo não sera demonstrado a conversao do numero real para binario devido ao tempo de execucao do programa!\n");
    printf("\nObs.: Nesse passo a passo, a mantissa sera a juncao do binario inteiro com real\n\n");
    printf("\nDigite o numero real decimal: ");
    scanf("%lf", &numero_decimal);
    decimal_float(numero_decimal);
    printf("\n");
    decimal_double(numero_decimal);
    printf("\n\n");


    

    return 0;
}

void decimal_float(double numero_decimal){

    int aux_numero_inteiro = 0, expoente = 0, ponto_fixo = 0, bit_sinal = 0, guardar_inteiro = numero_decimal, guardar_expoente = 0;
    int cont_int = 0, cont_ponto_fixo = 0, cont_exp = 0, cont_printar = 0;
    int convertor_inteiro[100], convertor_real[100], convertor_expoente[100];
    double aux_numero_real = 0, p_numero_decimal = 0;

    printf("__________________________\n");
    printf("\nPasso a passo para tranformar o numero %lf em float:\n\n", numero_decimal);

    if (numero_decimal>0){
        bit_sinal = 0;
        printf("Como o numero %lf eh maior que 0, o bit de sinal sera %d\n\n", numero_decimal, bit_sinal);
    } else{
        bit_sinal = 1;
        numero_decimal *= -1;
        guardar_inteiro *= -1;
        printf("Como o numero %lf eh menor que 0, o bit de sinal sera %d\n\n", numero_decimal, bit_sinal);
    }

    p_numero_decimal = numero_decimal;
    aux_numero_inteiro = (int) p_numero_decimal;
    aux_numero_real = numero_decimal - aux_numero_inteiro;

    printf("Convertendo o numero inteiro para base dois:\n");

    while(1){
        convertor_inteiro[cont_int] = aux_numero_inteiro%2;
        aux_numero_inteiro = aux_numero_inteiro/2;
        printf("%d Dividido por 2: %d\n", guardar_inteiro, aux_numero_inteiro);
        printf("Resto: %d\n\n", convertor_inteiro[cont_int]);
        if (aux_numero_inteiro == 0){
            break;
        }
        cont_int++;
        guardar_inteiro = guardar_inteiro/2;
    }

    printf("Convertendo o numero real para base dois: ");

    for (int t=0;t<23;t++){
        aux_numero_real = aux_numero_real * 2;
        if (aux_numero_real>=1.0){
            aux_numero_real -= 1;
            convertor_real[t] = 1;
        } else if(aux_numero_real>=0.0){
            convertor_real[t] = 0;
        }
    }

    for (int t = 0; t <23- cont_int-1; t++){
            printf("%d", convertor_real[t]);
        }

    printf("\n\n");
    
    for (int t=cont_int;t>=0;t--){
        if(convertor_inteiro[t] == 1){
            ponto_fixo = 0;
            expoente = (cont_int - cont_ponto_fixo) + 127;
            printf("O expoente tera como valor %d, pois o ponto fixo foi passado para o 1 da posicao %d do inteiro, somando as quantidade de casas passadas com 127.\n\n", expoente, cont_int);
            break;
        } else{
            ponto_fixo = -1;
        }
        cont_ponto_fixo++;
    }

    if (ponto_fixo == -1){
        for (int t=0;t<23;t++){
        if(convertor_real[t] == 1){
            ponto_fixo = 0;
            expoente = -(t + 1) + 127;
            printf("O expoente tera como valor %d, pois o ponto fixo foi passado para o 1 da posicao %d do real, somando as quantidade de casas passadas com 127.\n\n", expoente, t);
            break;
        } else{
            ponto_fixo = -1;
        }
    }
    }

    guardar_expoente = expoente;
    printf("Convertendo o numero do expoente para base dois com 8 bits: ");

    while(cont_exp < 8){
        convertor_expoente[cont_exp] = expoente%2;
        expoente = expoente/2;
        printf("%d Dividido por 2: %d\n", guardar_expoente, expoente);
        printf("Resto: %d\n\n", convertor_expoente[cont_exp]);
        cont_exp++;
        guardar_expoente = guardar_expoente/2;
    }

    printf("Resultado para Float: %d ", bit_sinal);

    for (int t=cont_exp-1;t>=0;t--){
            printf("%d", convertor_expoente[t]);
            convertor_expoente[t] = 0;
    }

    printf(" ");

    if (numero_decimal>=1.0){
        for (int t=cont_int;t>=0;t--){
        if(t!=cont_int){
            printf("%d", convertor_inteiro[t]);
        }
        convertor_inteiro[t] = 0;
        }
        
        for (int t = 0; t <23- cont_int-1; t++){
            printf("%d", convertor_real[t]);
            convertor_real[t] = 0;
        }
    } else if(numero_decimal<1.0){    
        for (int t = 0; t < 23; t++){
            if (cont_printar >= 1){
                printf("%d", convertor_real[t]);
            }
            if (convertor_real[t]==1){
                cont_printar++;
            }
            convertor_real[t] = 0;
        }
    }
}

void decimal_double(double numero_decimal){

    int aux_numero_inteiro = 0, expoente = 0, ponto_fixo = 0, bit_sinal = 0, guardar_inteiro = numero_decimal, guardar_expoente = 0;
    int cont_int = 0, cont_ponto_fixo = 0, cont_exp = 0, cont_printar = 0;
    int convertor_inteiro[100], convertor_real[100], convertor_expoente[100];
    double aux_numero_real = 0, p_numero_decimal = 0;

    printf("__________________________\n");
    printf("\nPasso a passo para tranformar o numero %lf em double:\n\n", numero_decimal);

    if (numero_decimal>0){
        bit_sinal = 0;
        printf("Como o numero %lf eh maior que 0, o bit de sinal sera %d\n\n", numero_decimal, bit_sinal);
    } else{
        bit_sinal = 1;
        numero_decimal *= -1;
        guardar_inteiro *= -1;
        printf("Como o numero %lf eh menor que 0, o bit de sinal sera %d\n\n", numero_decimal, bit_sinal);
    }

    p_numero_decimal = numero_decimal;
    aux_numero_inteiro = (int) p_numero_decimal;
    aux_numero_real = numero_decimal - aux_numero_inteiro;

    printf("Convertendo o numero inteiro para base dois:\n");

    while(1){
        convertor_inteiro[cont_int] = aux_numero_inteiro%2;
        aux_numero_inteiro = aux_numero_inteiro/2;
        printf("%d Dividido por 2: %d\n", guardar_inteiro, aux_numero_inteiro);
        printf("Resto: %d\n\n", convertor_inteiro[cont_int]);
        if (aux_numero_inteiro == 0){
            break;
        }
        cont_int++;
        guardar_inteiro = guardar_inteiro/2;
    }

    printf("Convertendo o numero real para base dois: ");

    for (int t=0;t<52;t++){
        aux_numero_real = aux_numero_real * 2;
        if (aux_numero_real>=1.0){
            aux_numero_real -= 1;
            convertor_real[t] = 1;
        } else if(aux_numero_real>=0.0){
            convertor_real[t] = 0;
        }
    }

    for (int t = 0; t <52- cont_int-1; t++){
            printf("%d", convertor_real[t]);
        }

    printf("\n\n");
    
    for (int t=cont_int;t>=0;t--){
        if(convertor_inteiro[t] == 1){
            ponto_fixo = 0;
            expoente = (cont_int - cont_ponto_fixo) + 1023;
            printf("O expoente tera como valor %d, pois o ponto fixo foi passado para o 1 da posicao %d do inteiro, somando as quantidade de casas passadas com 1023.\n\n", expoente, cont_int);
            break;
        } else{
            ponto_fixo = -1;
        }
        cont_ponto_fixo++;
    }

    if (ponto_fixo == -1){
        for (int t=0;t<52;t++){
        if(convertor_real[t] == 1){
            ponto_fixo = 0;
            expoente = -(t + 1) + 1023;
            printf("O expoente tera como valor %d, pois o ponto fixo foi passado para o 1 da posicao %d do real, somando as quantidade de casas passadas com 1023.\n\n", expoente, t);
            break;
        } else{
            ponto_fixo = -1;
        }
    }
    }

    guardar_expoente = expoente;
    printf("Convertendo o numero do expoente para base dois com 11 bits: ");

    while(cont_exp < 11){
        convertor_expoente[cont_exp] = expoente%2;
        expoente = expoente/2;
        printf("%d Dividido por 2: %d\n", guardar_expoente, expoente);
        printf("Resto: %d\n\n", convertor_expoente[cont_exp]);
        cont_exp++;
        guardar_expoente = guardar_expoente/2;
    }

    printf("Resultado para Double: %d ", bit_sinal);

    for (int t=cont_exp-1;t>=0;t--){
            printf("%d", convertor_expoente[t]);
            convertor_expoente[t] = 0;
    }

    printf(" ");

    if (numero_decimal>=1.0){
        for (int t=cont_int;t>=0;t--){
        if(t!=cont_int){
            printf("%d", convertor_inteiro[t]);
        }
        convertor_inteiro[t] = 0;
        }
        
        for (int t = 0; t <52- cont_int-1; t++){
            printf("%d", convertor_real[t]);
            convertor_real[t] = 0;
        }
    } else if(numero_decimal<1.0){    
        for (int t = 0; t < 52; t++){
            if (cont_printar >= 1){
                printf("%d", convertor_real[t]);
            }
            if (convertor_real[t]==1){
                cont_printar++;
            }
            convertor_real[t] = 0;
        }
    }
}