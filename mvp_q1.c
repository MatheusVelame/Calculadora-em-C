#include <stdio.h>
void decimal_base2(int numero_decimal, int bit_sinal);
void decimal_base8(int numero_decimal);
void decimal_base16(int numero_decimal);
void decimal_bcd(int numero_decimal);
void decimal_complementoa2(int numero_decimal, int bit_sinal);

int main(){

    int numero_decimal, operacao, bit_sinal = 0;

    while (1){
        printf("\n\nCALCULADORA\n\n");
        printf("(1) Decimal para base 2\n");
        printf("(2) Decimal para base 8\n");
        printf("(3) Decimal para base 16\n");
        printf("(4) Decimal para BCD\n");
        printf("(5) Complemento A2\n");
        printf("(6) Sair\n\n");
        printf("Digite a operacao desejada: ");
        scanf("%d", &operacao);

        if (operacao == 1){
            printf("Digite o numero de base 10: ");
            scanf("%d", &numero_decimal);
            decimal_base2(numero_decimal, bit_sinal);
        } else if(operacao == 2){
            printf("Digite o numero de base 10: ");
            scanf("%d", &numero_decimal);
            decimal_base8(numero_decimal);
        } else if(operacao == 3){
            printf("Digite o numero de base 10: ");
            scanf("%d", &numero_decimal);
            decimal_base16(numero_decimal);
        } else if(operacao == 4){
            printf("Digite o numero de base 10: ");
            scanf("%d", &numero_decimal);
            decimal_bcd(numero_decimal);
        } else if (operacao == 5){
            printf("Digite o numero de base 10: ");
            scanf("%d", &numero_decimal);
            decimal_complementoa2(numero_decimal, bit_sinal);
        } else if(operacao == 6){
            break;
        } else{
            printf("Operacao invalida!\n");
        }
    }

    return 0;
}


void decimal_base2(int numero_decimal, int bit_sinal){
    int cont=0, converter_numero[100];
    printf("\n\nNumero binario: ");
    if (numero_decimal >= 0){
        bit_sinal = 0;
    } else{
        bit_sinal = 1;
        numero_decimal*=-1;
    }
    while(1){
        converter_numero[cont] = numero_decimal%2;
        numero_decimal = numero_decimal/2;
        if (numero_decimal == 0){
            break;
        }
        cont++;
    }
    printf("%d ", bit_sinal);
    for (int t=cont;t>=0;t--){
        printf("%d", converter_numero[t]);
        converter_numero[t] = 0;
    }
}


void decimal_base8(int numero_decimal){
    int converter_numero[100], cont=0;
    printf("\n\nNumero octal: ");
    if (numero_decimal < 0){
        printf("-");
        numero_decimal*=-1;
    }
    while(1){
        converter_numero[cont] = numero_decimal%8;
        numero_decimal = numero_decimal/8;
        if (numero_decimal == 0){
            break;
        }
        cont++;
    }
    for (int t=cont;t>=0;t--){
        printf("%d", converter_numero[t]);
        converter_numero[t] = 0;
    }
}


void decimal_base16(int numero_decimal){
    int converter_numero[100], cont = 0;
    printf("\n\nNumero hexadecimal: 0x");
    if (numero_decimal < 0){
        printf("-");
        numero_decimal*=-1;
    }
    while(1){
        converter_numero[cont] = numero_decimal%16;
        numero_decimal = numero_decimal/16;
        if (numero_decimal == 0){
            break;
        }
        cont++;
    }
    for (int t=cont;t>=0;t--){
        if (converter_numero[t] == 10){
            printf("A");
        }else if (converter_numero[t] == 11){
            printf("B");
        }else if (converter_numero[t] == 12){
            printf("C");
        }else if (converter_numero[t] == 13){
            printf("D");
        }else if (converter_numero[t] == 14){
            printf("E");
        }else if (converter_numero[t] == 15){
            printf("F");
        }else{
            printf("%d", converter_numero[t]);
        }
        converter_numero[t] = 0;
    }
}


void decimal_bcd(int numero_decimal){
    char converter_bcd[1000];
     printf("\n\nNumero BCD: ");
    sprintf(converter_bcd, "%d", numero_decimal);
    for (int t=0;converter_bcd[t];t++){
        if (converter_bcd[t] == '0'){
            printf("0000 ");
        } else if (converter_bcd[t] == '1'){
            printf("0001 ");
        } else if (converter_bcd[t] == '2'){
            printf("0010 ");
        } else if (converter_bcd[t] == '3'){
            printf("0011 ");
        } else if (converter_bcd[t] == '4'){
            printf("0100 ");
        } else if (converter_bcd[t] == '5'){
            printf("0101 ");
        } else if (converter_bcd[t] == '6'){
            printf("0110 ");
        } else if (converter_bcd[t] == '7'){
            printf("0111 ");
        } else if (converter_bcd[t] == '8'){
            printf("1000 ");
        } else if (converter_bcd[t] == '9'){
            printf("1001 ");
        }
    }
}


void decimal_complementoa2(int numero_decimal, int bit_sinal){
    int decimal_auxiliar, converter_numero[100], cont = 0, cont_aux = 0, converter_numero_aux[100];;
    decimal_auxiliar = numero_decimal;
    printf("\n\nComplemento A2: ");
    if (numero_decimal >= 0){
        bit_sinal = 0;
    } else{
        bit_sinal = 1;
        numero_decimal*=-1;
        decimal_auxiliar*=-1;
    }
    while(cont<=14){
        converter_numero[cont] = numero_decimal%2;
        numero_decimal = numero_decimal/2;
        cont++;
        }
    if (decimal_auxiliar>0){
        while(1){
        converter_numero_aux[cont_aux] = decimal_auxiliar%2;
        decimal_auxiliar = decimal_auxiliar/2;
        if (converter_numero_aux[cont_aux] == 1){
            break;
        }
        cont_aux++;
    }
    }
    if (bit_sinal==1){
        printf("%d ", bit_sinal);
        for (int t=14;t>=0;t--){
            if (converter_numero[t]==0 && cont_aux+1<=t){
                converter_numero[t]=1;
            } else if (converter_numero[t]==1 && cont_aux+1<=t){
                converter_numero[t]=0;
            }
            printf("%d", converter_numero[t]);
            converter_numero[t] = 0;
        }
    } else{
        printf("%d ", bit_sinal);
        for (int t=14;t>=0;t--){
            printf("%d", converter_numero[t]);
            converter_numero[t] = 0;
        }
    }
}