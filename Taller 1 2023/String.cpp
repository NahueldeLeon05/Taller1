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
    LiberarString(to);
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
    LiberarString(aux);
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
    LiberarString(aux);
}

void strswp(String &s1, String &s2) {
    String aux;
    strcrear(aux);
    strcop(s1, aux);

    strcop(s2, s1);
    strcop(aux, s2);

    LiberarString(aux);
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

boolean EsFlecha(String flecha) {
    return strlar(flecha) == 2 && flecha[0] == '-' && flecha[1] == '>' ? TRUE : FALSE;
}

void PasarMayus(String &nombre) {
    int i = 0;
    while(nombre[i] != '\0'){
        int c = nombre[i];
        int num = c >= 97 && c <= 122 ? c - 32 : c;
        nombre[i] = (char) num;

        i++;
    }
}

boolean NombreAlfabetico(String nom) {
    boolean alph = TRUE;

    int i = 0;
    while(nom[i] != '\0' && alph == TRUE){
        int c = nom[i];
        alph = (c >= 97 && c <= 122) || (c >= 65 && c <= 90) ? TRUE : FALSE;
        i++;
    }

    return alph;
}
//revisar solo espacios
void PrimerPalabra(String &input, String &palabra) {
    Recortar(input);

    String aux = new char[strlar(input) + 1];
    int i = 0;
    while (input[i] != '\0' && input[i] != ' ') {
        aux[i] = input[i];
        i++;
    }
    aux[i] = '\0';

    strcrear(palabra);
    strcop(aux, palabra);

    Substr(input, i);
    LiberarString(aux);
}

void Recortar(String &input) { //Elimina los espacios que esten delante de la primer palabra.
    String aux = new char[strlar(input) + 1];
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] != ' ' || j > 0) {
            aux[j] = input[i];
            j++;
        }
        i++;
    }
    aux[j] = '\0';
    strcop(aux, input);
    LiberarString(aux);
}

void Substr(String &input, int from) { //Devuelve el string desde donde termina la primer palabra.
    String aux = new char[strlar(input) + 1];
    int j = 0;
    while (input[from] != '\0') {
        aux[j] = input[from];
        from++;
        j++;
    }
    aux[j] = '\0';

    strcop(aux, input);
    LiberarString(aux);
}

boolean StringVacio(String input) {
    return strlar(input) == 0 && input[0] == '\0' ? TRUE : FALSE;
}

void GuardarString(String s, FILE *f) {
    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite(&s[i], sizeof(char), 1, f);

}

void LeerString(String &s, FILE *f) {
    int i = 0;
    String aux;

    aux = new char[MAX];
    fread(&aux[i], sizeof(char), 1, f);

    while (!feof(f) && (aux[i] != '\0')) {
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }

    strcrear(s);
    strcop(aux, s);
    delete[] aux;
}


