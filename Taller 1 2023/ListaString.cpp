#include "ListaString.h"

ListaString CmdEnLista(String s) {
    ListaString root = nullptr;

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
    node->sig = nullptr;

    if (root == nullptr) {
        root = node;
    } else {
        ListaString aux = root;
        while (aux->sig != nullptr) {
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
        root = NULL;
    }
}
