/*
Eduardo Pereira Xavier

Pedro Berger Carbone

Pedro Henrique Alves da Silva
*/

#include <stdio.h>

/* Função que soma os 3 binários com uso das operações */
int binf(int bin1, int bin2, int bin3, int mm1, int mm2){
    int somabin;
    
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
        
        printf("\n%db (%di %dh)\n", bin1, inte1, hexa1);
        printf("%c\n", mm1);
        printf("%db (%di %dh)\n", bin2, inte2, hexa2);
        printf("%c\n", mm2);
        printf("%db (%di %dh)\n", bin3, inte3, hexa3);
        printf("=\n");
        printf("%db (%di %dh)\n\n", binF, inteF, hexaF);
        
        scanf("%d", &bin1);
    }

    return 0;
}
