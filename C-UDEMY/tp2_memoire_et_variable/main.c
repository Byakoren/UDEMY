#include <stdio.h>
#include <stdlib.h>

// Short et int: %d, long: %ld, float et double: %f et char: %c

int main(){

    printf("\t TP 2, \"Mémoire et variable\" \n");

    int mon_int = 15;
    short mon_short = 10;
    long mon_long = 345;
    float mon_float = 3.14;
    double mon_double = 12.6876362;
    char mon_char = 'a';
    
    printf(" Mon int = %d et prend la taille de %d octets \n", mon_int, sizeof(int));
    printf(" Mon short = %d et prend la taille de %d octets \n", mon_short, sizeof(short));
    printf(" Mon long = %ld et prend la taille de %ld octets \n", mon_long, sizeof(long));
    printf(" Mon float = %.2f et prend la taille de %d octets \n", mon_float, sizeof(float));
    printf(" Mon double = %f et prend la taille de %d octets \n", mon_double, sizeof(double));
    printf(" Mon char = %c et prend la taille de %d octets \n", mon_char, sizeof(char));
    
    return 0;
}