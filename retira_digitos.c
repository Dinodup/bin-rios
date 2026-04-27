#include <stdio.h>

int main()
{
    int bin, digito, bin1;
    scanf("%d", &bin);
    bin1 = bin;
    for(int i = 0; i<8; i++){
        digito = bin1 % 10;
        if(digito == 1){
            bin1--;
        }
        bin1 = bin1 / 10;
        printf("bin: %d\n", bin1);
        printf("digito: %d\n\n", digito);
    }
    
    
    printf("Hello World");

    return 0;
}