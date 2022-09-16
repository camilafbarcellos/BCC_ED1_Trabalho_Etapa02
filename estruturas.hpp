#ifndef _HPP_ESTRUTURAS_
#define _HPP_ESTRUTURAS_
#include <string>

using namespace std;

/// ESTRUTURAS DA LISTA PADRÃO --> lista de equipamentos do cliente
struct No
{
    int dado;
    struct No *prox;
    No()
    {
        prox = nullptr;
    }

};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista()
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
    ~Lista()
    {
        No *n = inicio;
        while(n)
        {
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
};

/// ESTRUTURAS DA LISTA DE EQUIPAMENTOS
struct Equipamento
{
    int codigo;
    string nome;
    int potencia;
};

struct NoEquip
{
    Equipamento dado;
    struct NoEquip *prox;
    NoEquip()
    {
        prox = nullptr;
    }
};

/// ESTRUTURAS DA LISTA DE MUNICÍPIOS
struct Municipio
{
    int codigo;
    string nome;
};

struct NoMunic
{
    Municipio dado;
    struct NoMunic *prox;

    NoMunic()
    {
        prox = nullptr;
    }
};

/// ESTRUTURAS DA LISTA DE CLIENTES
struct Cliente
{
    int codigo;
    string nome;
    int idade;
    char sexo;
    int codMunicipio;
    Lista* equipClientes;
};

struct NoClien
{
    Cliente dado;
    struct NoClien *prox;

    NoClien()
    {
        prox = nullptr;
    }
};

#endif // _HPP_ESTRUTURAS_
