#include <stdio.h>
#include <stdlib.h>


int main(){

    printf("\t TP 2, \"Opérations sur variables\" \n");

    int mon_rectangle_1 = 0;
    int mon_rectangle_2 = 0;

    printf("Quelle est la taille des côtés de votre rectangle ?\n");
    scanf("%d%d", &mon_rectangle_1, &mon_rectangle_2);

    printf("Le périmètre de votre carré est de %d cm\n", mon_rectangle_1 * 2 + mon_rectangle_2 * 2);
    printf("La surface de votre carré est de %d cm²\n", mon_rectangle_1 * mon_rectangle_2);


    return 0;
}