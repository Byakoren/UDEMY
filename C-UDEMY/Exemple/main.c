/*
 * MOOC C — Fichier de révision unique
 * Compile:  gcc demo.c -o demo && ./demo      (Linux/Mac)
 *           gcc demo.c -o demo.exe && demo    (Windows)
 */

#include <stdio.h>
#include <string.h>   // pour strlen, strcpy, strcmp, etc.
#include <stdlib.h>   // pour malloc/free

/* =========================
   Section 13 : Préprocesseur
   - #define pour constantes et macros
   - #if/#ifdef pour compilation conditionnelle
   ========================= */
#define PI 3.141592653589793
#define SQR(x) ((x) * (x))      // Macro "fonction" : attention aux parenthèses !
#define DEBUG 1                 // Mets à 0 pour masquer les logs

/* Petite fonction utilitaire pour affichage conditionnel */
static void debug_log(const char* msg) {
#if DEBUG
    printf("[DEBUG] %s\n", msg);
#endif
}

/* =========================
   Prototypes (déclarations) pour que main() puisse appeler les démos
   ========================= */
void demo_conditions(void);     // Section 7
void demo_boucles(void);        // Section 8
void demo_pointeurs(void);      // Section 9
void demo_tableaux(void);       // Section 10
void demo_strings(void);        // Section 11
void demo_fonctions(void);      // Section 12
void demo_preprocesseur(void);  // Section 13
void demo_modulaire(void);      // Section 14 (pseudo-modulaire dans 1 fichier)

/* ============================================================
   Section 12 : Fonctions — exemples déclarés avant leur usage
   - Pass-by-value vs "pass-by-pointer" (simule le pass-by-reference)
   - Retour d'une valeur
   ============================================================ */
int somme(int a, int b) {                // retourne a + b
    return a + b;
}
void increment_valeur(int x) {           // n'affecte PAS l'original (copie)
    x++;
}
void increment_pointeur(int* px) {       // modifie la variable pointée
    if (px) (*px)++;
}

/* ============================================================
   Section 14 : Programmation modulaire — mini démonstration
   Idée: séparer le code en "module" (interface + implémentation).
   Ici, on simule un module compteur avec un état caché via 'static'.

   // --- Ce qu'on mettrait dans "compteur.h" ---
   //  void compteur_reset(void);
   //  void compteur_tick(void);
   //  int  compteur_valeur(void);

   // --- Ce qu'on mettrait dans "compteur.c" ---
   //  #include "compteur.h"
   //  static int etat = 0; // caché au reste du programme
   //  void compteur_reset(void) { etat = 0; }
   //  void compteur_tick(void)  { etat++; }
   //  int  compteur_valeur(void){ return etat; }

   // --- Dans "main.c" ---
   //  #include "compteur.h"
   //  compteur_reset(); compteur_tick(); printf("%d\n", compteur_valeur());
   ============================================================ */

/* "Module" compteur — version monofichier (pour la démo) */
static int COMPTEUR_ETAT = 0;                 // 'static' => invisible depuis d'autres .c
void compteur_reset(void) { COMPTEUR_ETAT = 0; }
void compteur_tick(void)  { COMPTEUR_ETAT++; }
int  compteur_valeur(void){ return COMPTEUR_ETAT; }

/* =========================
   Section 7 : Conditions
   ========================= */
void demo_conditions(void) {
    printf("\n=== Section 7 : Conditions ===\n");
    int x = 10;

    // if / else if / else
    if (x > 10) {
        printf("x > 10\n");
    } else if (x == 10) {
        printf("x == 10\n");
    } else {
        printf("x < 10\n");
    }

    // switch : pratique pour des cas discrets
    int jour = 3;
    switch (jour) {
        case 1: printf("Lundi\n"); break;
        case 2: printf("Mardi\n"); break;
        case 3: printf("Mercredi\n"); break;
        default: printf("Autre jour\n"); break;
    }
}

/* =========================
   Section 8 : Boucles
   ========================= */
void demo_boucles(void) {
    printf("\n=== Section 8 : Boucles ===\n");

    // for : compteur connu
    printf("for : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // while : tant que condition vraie
    printf("while : ");
    int j = 0;
    while (j < 3) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // do...while : s'exécute AU MOINS une fois
    printf("do...while : ");
    int k = 0;
    do {
        printf("%d ", k);
        k++;
    } while (k < 2);
    printf("\n");
}

/* =========================
   Section 9 : Pointeurs
   - &  : adresse de
   - *  : déréférencement (accéder à la valeur pointée)
   - pointeurs et sécurité (vérifier != NULL)
   ========================= */
void demo_pointeurs(void) {
    printf("\n=== Section 9 : Pointeurs ===\n");

    int a = 42;            // variable normale
    int *pa = &a;          // pa contient l'ADRESSE de a

    printf("a = %d\n", a);
    printf("&a (adresse) = %p\n", (void*)&a);
    printf("pa (adresse de a) = %p\n", (void*)pa);
    printf("*pa (valeur pointee) = %d\n", *pa);

    // Modifier via le pointeur
    *pa = 100;
    printf("Après *pa = 100, a = %d\n", a);

    // Pointeur NULL (ne pointe rien) : TOUJOURS tester avant déréférencement
    int *pn = NULL;
    if (pn == NULL) {
        printf("pn est NULL (ne pas déréférencer!)\n");
    }
}

/* =========================
   Section 10 : Tableaux
   - 1D et 2D
   - relation tableau/pointeur
   ========================= */
void demo_tableaux(void) {
    printf("\n=== Section 10 : Tableaux ===\n");

    int t[5] = {1, 2, 3, 4, 5};     // tableau statique 1D
    // Parcours
    int somme = 0;
    for (int i = 0; i < 5; i++) {
        somme += t[i];
    }
    printf("Somme t = %d\n", somme);

    // Tableau 2D : 3 lignes x 2 colonnes
    int m[3][2] = { {1,2}, {3,4}, {5,6} };
    printf("m[2][1] = %d\n", m[2][1]); // 6

    // Tableau et pointeurs
    int *pt = t;   // décay: le nom 't' se comporte comme &t[0] dans la plupart des expressions
    printf("pt pointe sur t[0] => *pt = %d\n", *pt);
    pt++; // avance d'un int
    printf("après pt++, *pt = %d (t[1])\n", *pt);
}

/* =========================
   Section 11 : Chaînes de caractères (strings)
   - En C, une string = tableau de char terminé par '\0'
   - Fonctions <string.h> : strlen, strcpy, strcmp...
   ========================= */
void demo_strings(void) {
    printf("\n=== Section 11 : Strings ===\n");

    char s1[20] = "Hello";      // 'H' 'e' 'l' 'l' 'o' '\0' ...
    char s2[20];
    strcpy(s2, s1);             // copie s1 -> s2 (assure-toi que s2 est assez grand)

    printf("s1=\"%s\", longueur=%zu\n", s1, strlen(s1));
    printf("s2=\"%s\"\n", s2);

    // Concaténation simple (attention à la taille)
    strcat(s2, " C!");
    printf("concat: s2=\"%s\"\n", s2);

    // Comparaison : 0 si égal
    if (strcmp(s1, "Hello") == 0) {
        printf("s1 == \"Hello\"\n");
    }

    // Allocation dynamique d'une string (ex: pour longueur variable)
    const char* src = "Dyn";
    char* dyn = (char*)malloc(strlen(src) + 1); // +1 pour '\0'
    if (dyn) {
        strcpy(dyn, src);
        printf("dyn=\"%s\"\n", dyn);
        free(dyn);
    }
}

/* =========================
   Section 12 : Fonctions
   ========================= */
int fact(int n); // Prototype de la fonction factorielle

void demo_fonctions(void) {
    printf("\n=== Section 12 : Fonctions ===\n");

    int a = 5, b = 7;
    int s = somme(a, b);
    printf("somme(%d, %d) = %d\n", a, b, s);

    int x = 10;
    increment_valeur(x);          // ne change pas x (copie)
    printf("après increment_valeur(x), x = %d\n", x);

    increment_pointeur(&x);       // passe l'adresse => modifie x
    printf("après increment_pointeur(&x), x = %d\n", x);

    // (bonus) petite récursion: factorielle
    printf("fact(5) = %d\n", fact(5));
}

int fact(int n) { return (n <= 1) ? 1 : n * fact(n - 1); }

/* =========================
   Section 13 : Préprocesseur (suite)
   ========================= */
void demo_preprocesseur(void) {
    printf("\n=== Section 13 : Préprocesseur ===\n");
    printf("PI = %.5f\n", PI);
    printf("SQR(5) = %d\n", SQR(5));          // 25
    printf("SQR(2+3) = %d (grâce aux parenthèses dans la macro)\n", SQR(2+3)); // 25

    debug_log("ce message n'apparait que si DEBUG vaut 1");
}

/* =========================
   Section 14 : Programmation modulaire (démo)
   - On montre l'idée d'un état privé de module avec 'static'
   - En vrai, on séparerait en .h / .c (voir gros commentaire plus haut)
   ========================= */
void demo_modulaire(void) {
    printf("\n=== Section 14 : Programmation modulaire ===\n");
    compteur_reset();
    for (int i = 0; i < 3; i++) compteur_tick();
    printf("compteur_valeur() = %d (etat interne cache)\n", compteur_valeur());
}

/* =========================
   Programme principal : enchaine les démos
   ========================= */
int main(void) {
    printf("== Démos C – récap sections ==\n");

    demo_conditions();    // Section 7
    demo_boucles();       // Section 8
    demo_pointeurs();     // Section 9
    demo_tableaux();      // Section 10
    demo_strings();       // Section 11
    demo_fonctions();     // Section 12
    demo_preprocesseur(); // Section 13
    demo_modulaire();     // Section 14

    printf("\nFin des démos ✅\n");
    return 0; // code de sortie: 0 = succès
}
