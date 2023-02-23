#include "ListaString.h"

ListaString CmdEnLista(String s) {
    ListaString root = nullptr;

    String curr;
    PrimerPalabra(s, curr);

    while (StringVacio(curr) == FALSE) {
        AgregarAListaString(root, curr);
        PrimerPalabra(s, curr);
    }

    return root;
}

void AgregarAListaString(ListaString &root, String s) {
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
