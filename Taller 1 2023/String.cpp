#include "String.h"
#include <stdio.h>

void strcrear(String &s) {
    s = new char [1];
    s[0] = '\0';
}

void LiberarString(String &s) {
    delete[] s;
    s = NULL;
}

int strlar(String s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void strcop(String from, String &to) {
    int i = 0;
    strdestruir(to);
    to = new char [strlar(from) + 1];
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

void scan(String &s) {
    fflush(stdin);

    String aux = new char [MAX];

    char c;
    scanf("%c", &c);

    int i = 0;
    while (i < MAX - 1 && c != '\n') {
        aux[i] = c;
        scanf("%c", &c);
        i++;
    }
    aux[i] = '\0';

    strcrear(s);
    strcop(aux, s);
    strdestruir(aux);
}

void strcon(String &s1, String s2) {
    String aux = new char[strlar(s1) + strlar(s2) + 1];

    int i = 0;
    while (s1[i] != '\0') {
        aux[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0') {
        aux[i + j] = s2[j];
        j++;
    }
    aux[i + j] = '\0';

    strcop(aux, s1);
    strdestruir(aux);
}

void strswp(String &s1, String &s2) {
    String aux;
    strcrear(aux);
    strcop(s1, aux);

    strcop(s2, s1);
    strcop(aux, s2);

    strdestruir(aux);
}

void print(String s1) {
    int i = 0;
    while (s1[i] != '\0') {
        printf("%c", s1[i]);
        i++;
    }
}

boolean strmen(String s1, String s2) {
    boolean existe=FALSE;
    int i=0;
    while(i<MAX-1 && !existe){
        if(s1[i]==s2[i])
            i++;
        else
            existe=TRUE;
    }
    if(existe){
        if(s1[i]<s2[i]){
            existe=TRUE;
        }else
            existe=FALSE;
    }else
            existe=FALSE;

    return existe;
}

boolean streq(String s1, String s2, boolean ignoreCase){
    boolean iguales = TRUE;
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0' && iguales == TRUE){
        if(ignoreCase == FALSE) {
            if (s1[i] != s2[i]) {
                iguales = FALSE;
            }
        } else {
            int c1 = s1[i] >= 65 && s1[i] <= 90 ? s1[i] + 32 : s1[i];
            int c2 = s2[i] >= 65 && s2[i] <= 90 ? s2[i] + 32 : s2[i];
            if (c1 != c2) {
                iguales = FALSE;
            }
        }
        i++;
    }
    if(s1[i]!='\0' || s2[i]!='\0')
                iguales=FALSE;
    return iguales;
}

// Precondición: El archivo viene abierto para escritura.
void GuardarString (String s, FILE * f){
    int i=0;
    while(s[i] != '\0'){
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}

// Precondición: El archivo viene abierto para lectura, y el string debe venir creado.
void LeerString (String &s, FILE * f){
    strcrear(s);

    String aux = new char[MAX];
    int i=0;
    fread(&aux[i], sizeof(char), 1, f);
    while(aux[i]!='\0'){
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }
    strcop(aux, s);
    strdestruir(aux);
}

boolean EsFlecha(String flecha) {
    return streq(flecha, "->", FALSE);
}
