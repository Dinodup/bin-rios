/*
Eduardo Pereira Xavier

Pedro Berger Carbone

Pedro Henrique Alves da Silva
*/

#include <stdio.h>

/* Função para somar os dois binarios */
int somabin(int bin1, int bin2, int bin12[]){
    int dig1, dig2;
    int extra = 0, bin = 0;
    int x = 1;
    
    for(int i = 0; i<8; i++){
        dig1 = bin1 % 10;
        if(dig1 == 1){
            bin1--;
        }
        bin1 = bin1 / 10;
        
        dig2 = bin2 % 10;
        if(dig2 == 1){
            bin2--;
        }
        bin2 = bin2 / 10;
        
        
        if(dig1 == 0 && dig2 == 0){
            bin12[i] = 0 + extra;
            extra = 0;
        }
                
        if((dig1 == 1 && dig2 == 0) || (dig1 == 0 && dig2 == 1)){
            if(extra == 1){
                bin12[i] = 0;
                extra = 1;
            }
            else
                bin12[i] = 1;
        }
                
        if(dig1 == 1 && dig2 == 1){
            bin12[i] = 0 + extra;
            extra = 1;
        }
    }
    
    for(int i=0; i<8; i++){
        bin = bin + bin12[i] * x;
        x = x * 10;
    }
    
    return bin;
}

/* Função para subtrair os dois binarios */
int subtbin(int bin1, int bin2, int bin12[]){
    int dig1, dig2;
    int emprestimo = 0, bin = 0;
    int x = 1;
    
    for(int i=0; i<8; i++){
        dig1 = bin1 % 10;
        if(dig1 == 1){
            bin1--;
        }
        bin1 = bin1 / 10;
        
        dig2 = bin2 % 10;
        if(dig2 == 1){
            bin2--;
        }
        bin2 = bin2 / 10;
        
        int sub = dig1 - dig2 - emprestimo;
        
        if(sub == -1){
            bin12[i] = 1;
            emprestimo = 1;
        }
        else{
            if(sub == -2){
                bin12[i] = 0;
                emprestimo = 1;
            }
            else{
                bin12[i] = sub;
                emprestimo = 0;
            }
        }
    }
    
    for(int i = 0; i < 8; i++){
        bin = bin + bin12[i] * x;
        x = x * 10;
    }
    
    return bin;
}

/* Função que soma os 3 binários com uso das operações */
int operacao(int bin1, int bin2, int bin3, int mm1, int mm2){
    int soma, dig3, bin22;
    int bin12[8];
        
    if(mm1 == '+'){
        bin22 = somabin(bin1, bin2, bin12);
    }
    else{
        bin22 = subtbin(bin1, bin2, bin12);
    }
    
    printf("\n1º resultado: %d\n", bin22);
    /* Zera vetor */
    for(int i = 0; i < 8; i++){
        bin12[i] = 0;
    }
    
    if(mm2 == '+'){
        soma = somabin(bin22, bin3, bin12);
    }
    else{
        soma = subtbin(bin22, bin3, bin12);
    }
    printf("\n2º resultado: %d\n", soma);
    
    /* Não pode simplesmente converter os 
    binários para inteiros correspondentes,
    realizar a soma ou subtração entre eles e depois 
    converter o resultado para binário */
    
    return soma;
}

/* Função que transforma um binario em decimal */
int bin_inte(int bin){
    int decimal = 0;
    int base = 1;

    while(bin != 0){
        decimal = decimal + (bin % 10) * base;
        base = base * 2;
        bin = bin / 10;
    }
    
    if(decimal >= 128){
        decimal = decimal - 256;
    }

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
        
        inteF = bin_inte(binF);
        hexaF = bin_hex(binF);
        
        /* No caso de ocorrência de OVERFLOW o resultado 
        da operação deve conter apenas os 8 bits menos 
        significativos com sua devida conversão para inteiro 
        com sinal correspondente, em complemento a 2, 
        assim como também para hexadecimal. */
        
        contazero(bin1);
        printf("%db (%di %dh)\n", bin1, inte1, hexa1);
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
