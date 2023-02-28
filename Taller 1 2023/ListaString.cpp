#include "ListaString.h"

ListaString CmdEnLista(String s) {
    ListaString root = NULL;

    String curr;
    PrimerPalabra(s, curr);

    while (StringVacio(curr) == FALSE) {
        AgregarAListaString(root, curr);
        PrimerPalabra(s, curr);
    }

    LiberarString(curr);

    return root;
}

void AgregarAListaString(ListaString &root, String s) { //Agrega palabra a ListaString
    ListaString node = new snode;
    strcrear(node->info);
    strcop(s, node->info);
    node->sig = NULL;

    if (root == NULL) {
        root = node;
    } else {
        ListaString aux = root;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = node;
    }
}

void GuardarListaString(ListaString L, FILE * f){
    while(L != NULL){
        GuardarString(L->info, f);
        L = L->sig;
    }
}

void LeerListaString(ListaString &root, FILE * f){
    String buffer;
    root = NULL;
    LeerString(buffer, f);

    while (!feof(f)) {
        AgregarAListaString(root, buffer);
        LeerString(buffer, f);
    }
}

void LiberarListaString(ListaString &root) {
    if (root != NULL) {
        if (root->sig != NULL) {
            LiberarListaString(root->sig);
        }
        LiberarString(root->info);
        delete root;
        root = NULL;
    }
}

int IndiceEnLista(ListaString root, String s) {
    int i = 0;
    boolean found = FALSE;
    while (root != NULL && found == FALSE) {
        if (streq(s, root->info, TRUE)) {
            found = TRUE;
        } else {
            root = root->sig;
            i++;
        }
    }

    return found == TRUE ? i : -1;
}

// Guarda en un String el valor de la lista.
// PRECONDICION: pos <= ContarElementosDeLista.
void AgarrarParam(ListaString ls, int pos, String &str) {
    int j = 0;
    while (ls != NULL && j != pos) {
        ls = ls->sig;
        j++;
    }

    if (j == pos) {
        strcrear(str);
        strcop(ls->info, str);
    }
}

void ImprimirLista(ListaString r) {
    int j = 0;
    while (r != NULL) {
        printf("%d> ", j);
        print(r->info);
        printf("\r\n");
        r = r->sig;
        j++;
    }
}

int ContarElementosDeLista(ListaString root) {
    int c = 0;
    while (root != NULL) {
        root = root->sig;
        c++;
    }

    return c;
}
