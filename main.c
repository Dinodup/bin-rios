/*
Eduardo Pereira Xavier

Pedro Berger Carbone

Pedro Henrique Alves da Silva
*/

#include <stdio.h>

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
