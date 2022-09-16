#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

using namespace std;

#include "estruturas.hpp"

/// FUNÇÕES DA LISTA PADRÃO --> lista de equipamentos do cliente
bool vaziaL(Lista *lista)
{
    if(!(lista->inicio) )
        return true;
    else
        return false;
}

bool insereFimL(Lista *lista, int valor)
{
    No *novo = new No();

    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;

    if(lista->fim)
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    else
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    lista->tamanho++;

    return true;
}

bool insereL(Lista *lista, int valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while (n)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = nullptr;
}

void removeL(Lista *lista)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    while(atual)
    {
        lista->inicio = atual->prox;
        if(!lista->inicio)
            lista->fim = lista->inicio;
        anterior = atual;
        atual = atual->prox;
    }

    delete(atual);
    return;

}

/// FUNÇÕES DA LISTA DE EQUIPAMENTOS
void inicializaEquip(NoEquip **lista)
{
    *lista = nullptr;
}

bool vaziaEquip(NoEquip **lista)
{
    if(! (*lista) )
        return true;
    else
        return false;
}

// insere no início da lista
bool insereEquip(NoEquip **lista, Equipamento valor)
{
    NoEquip *novo = new NoEquip();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

// insere no fim da lista
void insereFimEquip(NoEquip **lista, Equipamento valor)
{
    NoEquip *novo = new NoEquip();
    novo->dado = valor;//50
    novo->prox = nullptr;

    if(vaziaEquip(lista))
    {
        *lista = novo;
    }
    else
    {
        NoEquip* n = *lista;

        while(n->prox != NULL)
        {
            n = n->prox;
        }

        n->prox = novo;
    }
}

int totalEquip(NoEquip **lista)
{
    NoEquip *n = *lista;
    int cont = 0;

    while(n)
    {
        n = n->prox;
        cont++;
    }

    return cont;
}

void destroiEquip(NoEquip **lista)
{
    NoEquip *n = *lista;
    while (n)
    {
        NoEquip *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = nullptr;
}

/// FUNÇÕES DA LISTA DE MUNICÍPIOS
void inicializaMunic(NoMunic **lista)
{
    *lista = nullptr;
}

bool vaziaMunic(NoMunic **lista)
{
    if(! (*lista) )
        return true;
    else
        return false;
}

// insere no início da lista
bool insereMunic(NoMunic **lista, Municipio valor)
{
    NoMunic *novo = new NoMunic();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

// insere no fim da lista
void insereFimMunic(NoMunic **lista, Municipio valor)
{
    NoMunic *novo = new NoMunic();
    novo->dado = valor;
    novo->prox = nullptr;

    if(vaziaMunic(lista))
    {
        *lista = novo;
    }
    else
    {
        NoMunic* n = *lista;

        while(n->prox != NULL)
        {
            n = n->prox;
        }

        n->prox = novo;
    }
}

int totalMunic(NoMunic **lista)
{
    NoMunic *n = *lista;
    int cont = 0;

    while(n)
    {
        n = n->prox;
        cont++;
    }

    return cont;
}

void destroiMunic(NoMunic **lista)
{
    NoMunic *n = *lista;
    while (n)
    {
        NoMunic *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = nullptr;
}

/// FUNÇÕES DA LISTA DE CLIENTES
void inicializaClien(NoClien **lista)
{
    *lista = nullptr;
}

bool vaziaClien(NoClien **lista)
{
    if(! (*lista) )
        return true;
    else
        return false;
}

// insere no início da lista
bool insereClien(NoClien **lista, Cliente valor)
{
    NoClien *novo = new NoClien();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

// insere no fim da lista
void insereFimClien(NoClien **lista, Cliente valor)
{
    NoClien *novo = new NoClien();
    novo->dado = valor;//50
    novo->prox = nullptr;

    if(vaziaClien(lista))
    {
        *lista = novo;
    }
    else
    {
        NoClien* n = *lista;

        while(n->prox != NULL)
        {
            n = n->prox;
        }

        n->prox = novo;
    }
}

int totalClien(NoClien **lista)
{
    NoClien *n = *lista;
    int cont = 0;

    while(n)
    {
        n = n->prox;
        cont++;
    }

    return cont;
}

void destroiClien(NoClien **lista)
{
    NoClien *n = *lista;
    while (n)
    {
        NoClien *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = nullptr;
}

#endif // _HPP_LISTA_DINAMICA
