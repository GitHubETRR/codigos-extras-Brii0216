#include <stdio.h>

union numeritos {
    float f;
    unsigned char bytes[4];
};

int main() {  //no correrme tanto
        union numeritos n;
        
        printf("\nIngrese su número:");
        scanf("%f",&n.f);
    
    
    printf("Los bytes de la variable float: ");
    for (int i = 0; i < 4; i++) {
        printf("%X ", n.bytes[i]); // Utilizamos %X para imprimir en hexadecimal
    }
    printf("\n");

    return 0;
}