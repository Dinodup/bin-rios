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
    
    // funcionamento baseado na tirada do ultimo bit de cada decimal
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
    
    // reconstrói o número binário (em formato inteiro)
    for(int i=0; i<8; i++){
        bin = bin + bin12[i] * x;
        x = x * 10;
    }
    
    return bin;
}

/* Função para subtrair os dois binarios */
int subtbin(int bin1, int bin2, int bin12[]){
    int dig1, dig2, sub;
    int emprestimo = 0, bin = 0;
    int x = 1;
    
    // funcionamento baseado na tirada do ultimo bit de cada decimal
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
        
        sub = dig1 - dig2 - emprestimo;
        
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
    
    // reconstrói o número binário (em formato inteiro)
    for(int i = 0; i < 8; i++){
        bin = bin + bin12[i] * x;
        x = x * 10;
    }
    
    return bin;
}

/* Função para garantir que o binário tenha apenas 8 bits (trata overflow) */
int overflow(int bin) {
    return bin % 100000000;
}

/* Função que soma os 3 binários com uso das operações */
int operacao(int bin1, int bin2, int bin3, int mm1, int mm2){
    int soma, bin22;
    int bin12[8];
    
    // 1ª operação com + ou -
    if(mm1 == '+'){
        bin22 = somabin(bin1, bin2, bin12);
    }
    else{
        bin22 = subtbin(bin1, bin2, bin12);
    }
    
    // verifica se teve overflow
    bin22 = overflow(bin22);

    for(int i = 0; i < 8; i++) 
        bin12[i] = 0;
    
    if(mm2 == '+'){
        soma = somabin(bin22, bin3, bin12);
    }
    else{
        soma = subtbin(bin22, bin3, bin12);
    }
    
    // verifica se teve overflow
    soma = overflow(soma);
    
    return soma;
}

/* Função que transforma um binario em decimal */
int bin_inte(int bin){
    int deci = 0;
    int base = 1;

    while(bin != 0){
        deci = deci + (bin % 10) * base;
        base = base * 2;
        bin = bin / 10;
    }
    
    if(deci >= 128){
        deci = deci - 256;
    }

    return deci;
}

/* Função que transforma um binario em hexadecimal */
void bin_hex(int bin, char hexa[]) {
    int dir = 0, esq = 0;
    int base = 1;

    // posicao dos primeiros 4 bits (direita) 
    for (int i = 0; i < 4; i++) {
        dir = dir + (bin % 10) * base;
        bin = bin / 10;
        base = base * 2;
    }

    base = 1;
    // posicao dos ultimos 4 bits (esquerda) 
    for (int i = 0; i < 4; i++) {
        esq = esq + (bin % 10) * base;
        bin = bin / 10;
        base = base * 2;
    }

    char val_hex[] = "0123456789ABCDEF";
    
    // os 2 digitos + finalização do vetor
    hexa[0] = val_hex[esq];
    hexa[1] = val_hex[dir];
    hexa[2] = '\0';
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
    int bin1, bin2, bin3, binF, inte1, inte2, inte3, inteF;
    char hexa1[3], hexa2[3], hexa3[3], hexaF[3];
    char mm1, mm2;
    
    scanf("%d", &bin1);
    while(bin1 != -1){
        scanf(" %c", &mm1);
        
        scanf("%d", &bin2);
        
        scanf(" %c", &mm2);
        
        scanf("%d", &bin3);
        
        // binF é o resultado das operações envolvendo os 3 binarios
        binF = operacao(bin1, bin2, bin3, mm1, mm2);
        
        // convertendo os 3 binarios em decimais
        inte1 = bin_inte(bin1);
        inte2 = bin_inte(bin2);
        inte3 = bin_inte(bin3);
        
        // convertendo os 3 binarios em hexadecimais
        bin_hex(bin1, hexa1);
        bin_hex(bin2, hexa2);
        bin_hex(bin3, hexa3);

        // convertendo o resultado final em decimal e hexadecimal
        inteF = bin_inte(binF);
        bin_hex(binF, hexaF);
        printf("\n");
        
        contazero(bin1);
        printf("%db (%di %sh)\n", bin1, inte1, hexa1);
        printf("%c\n", mm1);
        contazero(bin2);
        printf("%db (%di %sh)\n", bin2, inte2, hexa2);
        printf("%c\n", mm2);
        contazero(bin3);
        printf("%db (%di %sh)\n", bin3, inte3, hexa3);
        printf("=\n");
        contazero(binF);
        printf("%db (%di %sh)\n\n", binF, inteF, hexaF);
        
        scanf("%d", &bin1);
    }

    return 0;
}
