#include <iostream>
#include <stdio.h>

struct nodo{
    int numero;
    struct  nodo *siguiente;
};

typedef struct nodo NODO;
typedef NODO *PNODO;

PNODO buscarFinal(PNODO &p){
    if (p == nullptr)
        return p;
    if (p->siguiente != nullptr)
        return buscarFinal(p->siguiente);
    else
        return p;
}

void insertarElemento(PNODO &p, int num){
    NODO *aux = new NODO;
    aux->numero = num;
    aux->siguiente = nullptr;
    if (p == nullptr) {
        p = aux;
    }else{
        PNODO final = buscarFinal(p);
        final->siguiente = aux;
    }
}

void imprimirLista(PNODO &p){
    PNODO aux = p;
    if (p == nullptr){
        printf("Lista vacia\n");
    } else{
        while (aux != nullptr){
            printf("Numero: %d\n", aux->numero);
            aux = aux->siguiente;
        }
    }
}

void eliminarElemento(PNODO &p){
    if (p == nullptr){
        printf("Lista vacia\n");
    } else {
        PNODO actual = p->siguiente;
        if (actual == nullptr)
            return;
        PNODO sig = actual->siguiente;
        while (sig->siguiente != nullptr) {
            actual = actual->siguiente;
            sig = sig->siguiente;
        }
        actual->siguiente = nullptr;
        delete (sig);
    }
}

int menu(){
    int opcion;
    printf("1) Ingresar elemento\n");
    printf("2) Borrar elemento\n");
    printf("3) Imprimir lista\n");
    printf("0) Salir\n");
    scanf("%d", &opcion);
    return opcion;
}

int elemento(){
    int elemento;
    printf("Ingresa un numero\n");
    scanf("%d", &elemento);
    return elemento;
}

int main() {
    int opcion;
    PNODO raiz = nullptr;
    do {
        switch (opcion = menu()) {
            case 0:
                printf("Hasta luego\n");
                break;
            case 1:
                insertarElemento(raiz, elemento());
                break;
            case 2:
                eliminarElemento(raiz);
                break;
            case 3:
                imprimirLista(raiz);
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 0);
    return 0;
}
