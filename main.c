/*
Eduardo Pereira Xavier

Pedro Berger Carbone

Pedro Henrique Alves da Silva
*/

#include <stdio.h>

/* Função que soma os 3 binários com uso das operações */
int operacao(int bin1, int bin2, int bin3, int mm1, int mm2){
    int somabin, dig1, dig2, dig3;

    for(int i = 0; i<8; i++){
        dig1 = bin1 % 10;
        if(dig1 == 1){
            bin1--;
        }
        bin1 = bin1 / 10;
        printf("digito 1: %d\n", dig1);
        
        dig2 = bin2 % 10;
        if(dig2 == 1){
            bin2--;
        }
        bin2 = bin2 / 10;
        printf("digito 2: %d\n", dig2);
        
        dig3 = bin3 % 10;
        if(dig3 == 1){
            bin3--;
        }
        bin3 = bin3 / 10;
        printf("digito 3: %d\n\n", dig3);
        
    }
    
    /* Não pode simplesmente converter os 
    binários para inteiros correspondentes,
    realizar a soma ou subtração entre eles e depois 
    converter o resultado para binário */
    
    return somabin;
}

/* Função que transforma um binario em decimal */
int bin_inte(int bin){
    int decimal;
    
    return decimal;
}

/* Função que transforma um binario em hexadecimal */
int bin_hex(int bin){
    int hexa;
    
    /* Utilize letras maiúsculas: A, B, C, D, E, F 
    para símbolos hexadecimais. */
    
    return hexa;
}

/* Função que coloca os zeros no printf evitando que apareçam somente números um */
int contazero(int bin){
    int resto;
    for(int i = 10000000; i>0; i = i / 10){
        resto = bin / i;
        if(resto == 0){
            printf("%d", resto);
        }
    }
}

int main()
{
    int bin1, bin2, bin3, binF;
    int inte1, hexa1, inte2, hexa2, inte3, hexa3, inteF, hexaF;
    char mm1, mm2;
    
    scanf("%d", &bin1);
    while(bin1 != -1){
        scanf(" %c", &mm1);
        
        scanf("%d", &bin2);
        
        scanf(" %c", &mm2);
        
        scanf("%d", &bin3);
        
        binF = operacao(bin1, bin2, bin3, mm1, mm2);
        
        inte1 = bin_inte(bin1);
        inte2 = bin_inte(bin2);
        inte3 = bin_inte(bin3);
        
        hexa1 = bin_hex(bin1);
        hexa2 = bin_hex(bin2);
        hexa3 = bin_hex(bin3);
        
        /* No caso de ocorrência de OVERFLOW o resultado 
        da operação deve conter apenas os 8 bits menos 
        significativos com sua devida conversão para inteiro 
        com sinal correspondente, em complemento a 2, 
        assim como também para hexadecimal. */
        
        contazero(bin1);
        printf("\n%db (%di %dh)\n", bin1, inte1, hexa1);
        printf("%c\n", mm1);
        contazero(bin2);
        printf("%db (%di %dh)\n", bin2, inte2, hexa2);
        printf("%c\n", mm2);
        contazero(bin3);
        printf("%db (%di %dh)\n", bin3, inte3, hexa3);
        printf("=\n");
        contazero(binF);
        printf("%db (%di %dh)\n\n", binF, inteF, hexaF);
        
        scanf("%d", &bin1);
    }

    return 0;
}
