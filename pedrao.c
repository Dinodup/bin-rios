/*
Eduardo Pereira Xavier
Pedro Berger Carbone
Pedro Henrique Alves da Silva
*/

#include <stdio.h>

/* Função para somar os dois binários */
int somabin(int bin1, int bin2, int bin12[]) {
    int dig1, dig2;
    int extra = 0, bin = 0;
    int x = 1;

    for (int i = 0; i < 8; i++) {
        dig1 = bin1 % 10;
        bin1 = bin1 / 10;

        dig2 = bin2 % 10;
        bin2 = bin2 / 10;

        int soma = dig1 + dig2 + extra;

        if (soma == 0) {
            bin12[i] = 0;
            extra = 0;
        } else if (soma == 1) {
            bin12[i] = 1;
            extra = 0;
        } else if (soma == 2) {
            bin12[i] = 0;
            extra = 1;
        } else if (soma == 3) {
            bin12[i] = 1;
            extra = 1;
        }
    }

    for (int i = 0; i < 8; i++) {
        bin = bin + bin12[i] * x;
        x = x * 10;
    }

    return bin;
}

/* Função para subtrair os dois binários */
int subtbin(int bin1, int bin2, int bin12[]) {
    int dig1, dig2;
    int emprestimo = 0, bin = 0;
    int x = 1;

    for (int i = 0; i < 8; i++) {
        dig1 = bin1 % 10;
        bin1 = bin1 / 10;

        dig2 = bin2 % 10;
        bin2 = bin2 / 10;

        int sub = dig1 - dig2 - emprestimo;

        if (sub == -1) {
            bin12[i] = 1;
            emprestimo = 1;
        } else if (sub == -2) {
            bin12[i] = 0;
            emprestimo = 1;
        } else {
            bin12[i] = sub;
            emprestimo = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        bin = bin + bin12[i] * x;
        x = x * 10;
    }

    return bin;
}

/* Função que soma os 3 binários com uso das operações */
int operacao(int bin1, int bin2, int bin3, int mm1, int mm2) {
    int bin22, binF;
    int bin12[8];

    if (mm1 == '+') {
        bin22 = somabin(bin1, bin2, bin12);
    } else {
        bin22 = subtbin(bin1, bin2, bin12);
    }

    // Limpa o vetor para a próxima operação
    for (int i = 0; i < 8; i++) bin12[i] = 0;

    if (mm2 == '+') {
        binF = somabin(bin22, bin3, bin12);
    } else {
        binF = subtbin(bin22, bin3, bin12);
    }

    return binF;
}

/* Função que transforma um binario em decimal (Complemento a 2) */
int bin_inte(int bin) {
    int decimal = 0;
    int base = 1;
    int temp_bin = bin;

    for (int i = 0; i < 8; i++) {
        decimal = decimal + (temp_bin % 10) * base;
        base = base * 2;
        temp_bin = temp_bin / 10;
    }

    if (decimal >= 128) {
        decimal = decimal - 256;
    }

    return decimal;
}

/* Função que imprime o binário em hexadecimal usando array de mapeamento */
void imprime_hex(int bin) {
    char hex_map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int decimal_real = 0;
    int base = 1;

    // Converte o formato 10101010 para o valor decimal real (0-255)
    for (int i = 0; i < 8; i++) {
        decimal_real = decimal_real + (bin % 10) * base;
        base = base * 2;
        bin = bin / 10;
    }
    
    // Ajuste para garantir que tratamos apenas 8 bits (caso o int bin seja maior)
    if (decimal_real < 0) decimal_real += 256;
    decimal_real %= 256;

    int d1 = decimal_real / 16; // Primeiro dígito hexa
    int d2 = decimal_real % 16; // Segundo dígito hexa

    printf("%c%ch", hex_map[d1], hex_map[d2]);
}

/* Função que coloca os zeros à esquerda no printf */
void contazero(int bin) {
    if (bin < 10000000 && bin >= 0) printf("0");
    if (bin < 1000000 && bin >= 0) printf("0");
    if (bin < 100000 && bin >= 0) printf("0");
    if (bin < 10000 && bin >= 0) printf("0");
    if (bin < 1000 && bin >= 0) printf("0");
    if (bin < 100 && bin >= 0) printf("0");
    if (bin < 10 && bin >= 0) printf("0");
}

int main() {
    int bin1, bin2, bin3, binF;
    int inte1, inte2, inte3, inteF;
    char mm1, mm2;

    while (scanf("%d", &bin1) && bin1 != -1) {
        scanf(" %c %d %c %d", &mm1, &bin2, &mm2, &bin3);

        binF = operacao(bin1, bin2, bin3, mm1, mm2);

        inte1 = bin_inte(bin1);
        inte2 = bin_inte(bin2);
        inte3 = bin_inte(bin3);
        inteF = bin_inte(binF);

        // Saída Binário 1
        contazero(bin1);
        printf("%db (%di ", bin1, inte1);
        imprime_hex(bin1);
        printf(")\n%c\n", mm1);

        // Saída Binário 2
        contazero(bin2);
        printf("%db (%di ", bin2, inte2);
        imprime_hex(bin2);
        printf(")\n%c\n", mm2);

        // Saída Binário 3
        contazero(bin3);
        printf("%db (%di ", bin3, inte3);
        imprime_hex(bin3);
        printf(")\n=\n");

        // Saída Resultado Final
        contazero(binF);
        printf("%db (%di ", binF, inteF);
        imprime_hex(binF);
        printf(")\n\n");
    }

    return 0;
}