#include <stdio.h>

void decimal_float(double numero_decimal);

int main(){

    double numero_decimal;
    int continuar;

    while(1){
        printf("\nDigite o numero real decimal: ");
        scanf("%lf", &numero_decimal);

        decimal_float(numero_decimal);

        printf("\n");
        scanf("%d", &continuar);

        if(continuar == 0){
            break;
        }else{
            continue;
        }
    }

    return 0;
}

void decimal_float(double numero_decimal){

    int aux_numero_inteiro = 0, expoente = 0, ponto_fixo = 0, bit_sinal = 0;
    int cont_int = 0, cont_ponto_fixo = 0, cont_exp = 0, cont_printar = 0;
    int convertor_inteiro[100], convertor_real[100], convertor_expoente[100];
    double aux_numero_real = 0, p_numero_decimal = 0;

    if (numero_decimal>0){
        bit_sinal = 0;
    } else{
        bit_sinal = 1;
        numero_decimal *= -1;
    }

    p_numero_decimal = numero_decimal;
    aux_numero_inteiro = (int) p_numero_decimal;
    aux_numero_real = numero_decimal - aux_numero_inteiro;

    while(1){
        convertor_inteiro[cont_int] = aux_numero_inteiro%2;
        aux_numero_inteiro = aux_numero_inteiro/2;
        if (aux_numero_inteiro == 0){
            break;
        }
        cont_int++;
    }

    for (int t=0;t<23;t++){
        aux_numero_real = aux_numero_real * 2;
        if (aux_numero_real>=1.0){
            aux_numero_real -= 1;
            convertor_real[t] = 1;
        } else if(aux_numero_real>=0.0){
            convertor_real[t] = 0;
        }
    }

    for (int t=cont_int;t>=0;t--){
        if(convertor_inteiro[t] == 1){
            ponto_fixo = 0;
            expoente = (cont_int - cont_ponto_fixo) + 127;
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
            break;
        } else{
            ponto_fixo = -1;
        }
    }
    }

    printf("%d\n", expoente);

    while(cont_exp < 8){
        convertor_expoente[cont_exp] = expoente%2;
        expoente = expoente/2;
        cont_exp++;
    }

    printf("%d ", bit_sinal);

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