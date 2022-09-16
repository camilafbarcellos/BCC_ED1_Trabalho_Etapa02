#include <iostream>
#include <cstring>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>

// Trabalho Final - Etapa 02 de ED1 - março de 2022
// Camila Florao Barcellos
// 20202PF.CC0003

using namespace std;

#include "estruturas.hpp" // inclusão do hpp de estruturas
#include "lista.hpp" // inclusão do hpp de lista simples

/// OPERAÇÃO 'A'
void mostraEquip(NoEquip **lista) // lista de equipamentos
{
    NoEquip *n = *lista;

    cout << "Equipamentos: {\n";
    while(n)
    {
        cout << "[" << n->dado.codigo << " | " << n->dado.nome << " | " << n->dado.potencia << "]";
        n = n->prox;

        if(n)
            cout << ",\n";
    }
    cout << " }\n";
}

void mostraMunic(NoMunic **lista) // lista de municípios
{
    NoMunic *n = *lista;

    cout << "Municípios: {\n";
    while(n)
    {
        cout << "[" << n->dado.codigo << " | " << n->dado.nome << "]";
        n = n->prox;

        if(n)
            cout << ",\n";
    }
    cout << " }\n";
}

void mostraL(Lista *lista) // lista de equipamentos do cliente
{
    No *n = lista->inicio;

    while(n)
    {
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << " | ";
    }
}

void mostraClien(NoClien **lista) // lista de clientes
{
    NoClien *n = *lista;

    cout << "Clientes: {\n";
    while(n)
    {
        cout << "[" << n->dado.codigo << " | " << n->dado.nome << " | " << n->dado.idade << " | " << n->dado.sexo << " | " << n->dado.codMunicipio << " | ";
        mostraL(n->dado.equipClientes);
        n = n->prox;

        if(n)
            cout << "],\n";
    }
    cout << "] }\n";
}

/// OPERAÇÃO 'B'
bool ordenaAlfabetica(NoEquip **lista)
{
    bool trocou;
    Equipamento aux;
    NoEquip *anterior, *atual;

    if(!vaziaEquip(lista))
    {
        do
        {
            trocou = false;
            NoEquip *anterior = nullptr;
            NoEquip *atual = *lista;
            while(atual)
            {
                // verifica se é o último dado ou primeiro dado (relação direta com NULL)
                if(anterior)
                {
                    if((anterior->dado.nome) > (atual->dado.nome)) // verifica ordem
                    {
                        Equipamento aux = anterior->dado; // utiliza auxiliar para armanezenar nó anterior
                        anterior->dado = atual->dado; // anterior recebe atual
                        atual->dado = aux; // atual recebe aux
                        trocou = true; // sinaliza troca
                    }
                }

                // prossegue na lista
                anterior = atual;
                atual = atual->prox;
            }

        }
        while(trocou);

        return true;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return false;
    }
}

bool ordenaPotencia(NoEquip **lista)
{
    bool trocou;
    Equipamento aux;
    NoEquip *anterior, *atual;

    if(!vaziaEquip(lista))
    {
        do
        {
            trocou = false;
            NoEquip *anterior = nullptr;
            NoEquip *atual = *lista;
            while(atual)
            {
                // verifica se é o último dado ou primeiro dado (relação direta com NULL)
                if(anterior)
                {
                    if((anterior->dado.potencia) > (atual->dado.potencia)) // verifica ordem
                    {
                        Equipamento aux = anterior->dado; // utiliza auxiliar para armanezenar nó anterior
                        anterior->dado = atual->dado; // anterior recebe atual
                        atual->dado = aux; // atual recebe aux
                        trocou = true; // sinaliza troca
                    }
                }

                // prossegue na lista
                anterior = atual;
                atual = atual->prox;
            }

        }
        while(trocou);

        return true;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return false;
    }
}

/// OPERAÇÃO 'C'
void infosClientes(NoClien **lista)
{
    if(!vaziaClien(lista))
    {
        NoClien *n = *lista;
        int contF = 0, contM = 0, cont30 = 0;
        while(n)
        {
            if(n->dado.sexo=='F')
                contF++;
            else if(n->dado.sexo=='M')
                contM++;

            n = n->prox;
        }

        n = *lista; // retorna o ponteiro para o início da lista
        while(n)
        {
            if(n->dado.idade>30)
                cont30++;

            n = n->prox;
        }

        cout << "Número de clientes do sexo feminino (F): " << contF << endl;
        cout << "Número de clientes do sexo masculino (M): " << contM << endl;
        cout << "Número de clientes acima de 30 anos: " << cont30 << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return;
    }
}

void mediaEquip(NoClien **lista)
{
    if(!vaziaClien(lista))
    {
        NoClien *n = *lista;
        int quantEquip = 0;
        while(n)
        {
            quantEquip += n->dado.equipClientes->tamanho; // acumula na variável o tamanho de cada lista

            n = n->prox;
        }
        cout << "-------------------------------------------------------------" << endl;
        cout << "Quantidade total de equipamentos: " << quantEquip << endl;
        int quantClien = totalClien(lista);
        cout << "Quantidade de clientes: " << quantClien << endl;
        cout << "-------------------------------------------------------------" << endl;
        float media = float(quantEquip) / float(quantClien);
        cout << "Média da quantidade de equipamentos nas residências: " << media << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return;
    }
}

/// OPERAÇÃO 'D'
void somaPotencia(NoClien **clientes, NoEquip **equipamentos)
{
    if(!vaziaClien(clientes))
    {
        int soma = 0;

        for(NoClien *c = *clientes; c != NULL; c = c->prox) // percorre lista de clientes
        {
            for(No *n = c->dado.equipClientes->inicio; n != NULL; n = n->prox) // percorre lista de equipamentos do cliente
            {
                for(NoEquip *e = *equipamentos; e != NULL; e = e->prox) // percorre lista de equipamentos
                {
                    if(n->dado == e->dado.codigo) // verifica se código na lista C equivale à lista E
                        soma += e->dado.potencia; // acumula potência na variável de soma
                }
            }
        }
        cout << "Soma total de potência dos equip. instalados: " << soma << "W" << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return;
    }
}

/// OPERAÇÃO 'E'
void buscaCliente(NoClien **clientes, int valor)
{
    NoClien *n = *clientes;
    int cont = 0; // variável contadora para quantidade de clientes encontrados
    cout << "Clientes que utilizam o equipamento: " << endl;
    for(NoClien *c = *clientes; c != NULL; c = c->prox) // percorre lista de clientes
    {
        for(No *n = c->dado.equipClientes->inicio; n != NULL; n = n->prox) // percorre lista de equipamentos do cliente
        {
            if(n->dado == valor) // verifica se é o mesmo código
            {
                cont++;
                cout << cont << "   -> " << c->dado.nome << endl;
            }

        }
    }

    return;
}

void mostraEquipMaisPotente(NoClien **clientes, NoEquip **equipamentos)
{
    if(!vaziaClien(clientes))
    {
        NoEquip *e = *equipamentos;
        int maiorPot = e->dado.potencia; // pré-define a primeira potência como a maior
        string maiorPotNome = e->dado.nome; // pré-define o nome do equipamento mais potente
        int maiorPotCod = e->dado.codigo; // pré-define o codigo do equipamento mais potente

        for(NoClien *c = *clientes; c != NULL; c = c->prox) // percorre lista de clientes
        {
            for(No *n = c->dado.equipClientes->inicio; n != NULL; n = n->prox) // percorre lista de equipamentos do cliente
            {
                for(e = *equipamentos; e != NULL; e = e->prox) // percorre lista de equipamentos
                {
                    if(n->dado == e->dado.codigo) // verifica se código na lista C equivale à lista E
                        if(e->dado.potencia > maiorPot) // verifica se potência é maior que a atual
                        {
                            maiorPot = e->dado.potencia; // substitui valor da potência
                            maiorPotNome = e->dado.nome; // substitui nome do equipamento
                            maiorPotCod = e->dado.codigo; // substitui código do equipamento
                        }
                }
            }
        }

        cout << "Nome do equipamento: " << maiorPotNome << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Potência do equipamento: " << maiorPot << "W" << endl;
        cout << "Código do equipamento: " << maiorPotCod << endl;
        cout << "-------------------------------------------------------------" << endl;

        buscaCliente(clientes, maiorPotCod); // aciona função para exibir clientes que possuírem o código obtido

        return;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return;
    }
}

/// OPERAÇÃO 'F'
void filtraCliente(NoClien **clientes, int cod, NoMunic **municipios)
{
    if(!vaziaClien(clientes))
    {
        NoMunic *m = *municipios;
        bool validaMunic = false; // validador do município


        while(m)
        {
            if(cod == m->dado.codigo) // verifica se código informado corresponde a um município cadastrado
            {
                cout << "   -> Município encontrado: " << cod << " - " << m->dado.nome << endl; // exibe nome do município
                validaMunic = true; // valida o município para permitir continuidade da função filtraCliente
            }

            m = m->prox;
        }

        if(validaMunic)
        {
            NoClien *c = *clientes;
            int cont = 0; // variável contadora para quantidade de clientes encontrados
            cout << "\nClientes residentes no município de código " << cod  << ": " << endl;
            while(c)
            {
                if(c->dado.codMunicipio == cod)
                {
                    cont++;
                    cout << cont << "   -> " << c->dado.nome << endl;
                }

                c = c->prox;
            }

            if(cont==0) // caso contador registre 0 clientes, retorna mensagem
                cout << "   -> Nenhum cliente encontrado!" << endl;
        }

        else // caso validador do município não encontre correspondência, retorna erro
            cout << "\nMunícipio não cadastrado ou código incorreto!" << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes está vazia!" << endl;

        return;
    }
}

int main()
{
    setlocale (LC_ALL, "Portuguese");

    /// Declaração dos nós
    NoEquip* EQUIPAMENTOS; // lista de equipamentos
    NoMunic* MUNICIPIOS; // lista de municípios
    NoClien* CLIENTES; // lista de clientes

    /// Inicialização das listas
    inicializaEquip(&EQUIPAMENTOS);
    inicializaMunic(&MUNICIPIOS);
    inicializaClien(&CLIENTES);

    /// Declaração das estruturas
    Equipamento equipamento;
    Municipio municipio;
    // variável cliente será declarada dentro do laço na leitura

    /// Leitura do .txt
    string linha;
    string dado;
    ifstream arquivo("cadastro.txt");
    if(arquivo.is_open())
    {
        int tipoLista;
        while(getline(arquivo, linha))
        {
            istringstream strBuffer(linha);
            // verificar lista de acordo com nome -> previne também que a linha de título caia no switch
            if(linha =="EQUIPAMENTOS")
            {
                tipoLista = 1; // deifinir o tipo de lista a ser lida
            }
            else if(linha == "MUNICIPIOS")
            {
                tipoLista = 2;
            }
            else if(linha == "CLIENTES")
            {
                tipoLista = 3;
            }
            else
            {
                switch(tipoLista)
                {
                case 1: // lista EQUIPAMENTOS
                {
                    int atributo = 1; // controle do tipo de dado na lista (codigo, nome...)
                    while(getline(strBuffer, dado, '#'))
                    {
                        if(atributo==1) // codigo
                            equipamento.codigo = stoi(dado); // converte string em int
                        else if(atributo==2) // nome
                            equipamento.nome = dado;
                        else if(atributo==3) // potencia
                            equipamento.potencia = stoi(dado); // converte string em int
                        atributo++; // aumenta contador do tipo
                    }
                    insereFimEquip(&EQUIPAMENTOS, equipamento); // insere na lista
                }
                break;
                case 2: // lista MUNICIPIOS
                {
                    int atributo = 1; // controle do tipo de dado na lista (codigo, nome...)
                    while(getline(strBuffer, dado, '#'))
                    {
                        if(atributo==1) // codigo
                            municipio.codigo = stoi(dado); // converte string em int
                        else if(atributo==2) // nome
                            municipio.nome = dado;
                        atributo++; // aumenta contador do tipo
                    }

                    insereFimMunic(&MUNICIPIOS, municipio);
                }
                break;
                case 3: // lista CLIENTES
                {
                    Cliente cliente; // declaração do cliente
                    cliente.equipClientes = new Lista(); // declaração da lista de equipamentos do cliente
                    int atributo = 1; // controle do tipo de dado na lista (codigo, nome...)
                    while(getline(strBuffer, dado, '#'))
                    {
                        if(atributo==1) // codigo
                            cliente.codigo = stoi(dado); // converte string em int
                        else if(atributo==2) // nome
                            cliente.nome = dado;
                        else if(atributo==3) // idade
                            cliente.idade = stoi(dado); // converte string em int
                        else if(atributo==4) // sexo
                            cliente.sexo = dado[1]; // posição dado[1] pois dado[0] armazena ' ' (espaço em branco)
                        if(atributo==5) // codMunicipio
                            cliente.codMunicipio = stoi(dado); // converte string em int
                        if(atributo>=6) // equipCliente
                            insereFimL(cliente.equipClientes, stoi(dado));
                        atributo++; // aumenta contador do tipo
                    }
                    insereFimClien(&CLIENTES, cliente);
                }
                break;
                }
            }
        }

        cout << "\n\n-------------------------------------------------------------" << endl;
        cout << "            Listas cadastradas com sucesso!" << endl;
        cout << "           Seguindo para o programa principal..." << endl;
        cout << "-------------------------------------------------------------\n\n" << endl;
    }

    else
    {
        cout << "\n\n-------------------------------------------------------------" << endl;
        cout << "            Erro no cadastramento de listas!" << endl;
        cout << "           Ausência do arquivo 'cadastro.txt'" << endl;
        cout << "-------------------------------------------------------------\n\n" << endl;
    }
    arquivo.close();

    system("pause");

    /// PROGRAMA PRINCIPAL -> CONCESSIONÁRIA RS ENERGIA

    char op; // variável de operação para controlar menu no switch...case

    do
    {
        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "               -- CONCESSIONÁRIA RS ENERGIA --               " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "  a) Mostrar listas de equipamentos, municípios e clientes" << endl;
        cout << "  b) Mostrar listas de equipamentos de forma ordenada" << endl;
        cout << "  c) Mostrar informações dos clientes" << endl;
        cout << "  d) Mostrar total de potência dos equipamentos instalados" << endl;
        cout << "  e) Mostrar equipamento mais potente e seus clientes" << endl;
        cout << "  f) Filtrar cliente por município" << endl;
        cout << "\n  z) Sair" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Sua opção: ";
        cin >> op;
        fflush(stdin);
        op = toupper(op); // transforma o char em maiúsculo para validar no switch...case

        switch(op)
        {
        case 'A':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                  -- EXIBIÇÃO DAS LISTAS --                  " << endl;
            cout << "-------------------------------------------------------------" << endl;
            mostraEquip(&EQUIPAMENTOS);
            cout << "\n";
            mostraMunic(&MUNICIPIOS);
            cout << "\n";
            mostraClien(&CLIENTES);
        }
        break;

        case 'B':
        {
            bool validaOrdem = true; // validador da escolha da ordenação
            do
            {
                system("cls");
                cout << "-------------------------------------------------------------" << endl;
                cout << "               -- ORDENAÇÃO DE EQUIPAMENTOS --               " << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "  a) Ordenação por nome (alfabética)" << endl;
                cout << "  b) Ordenação por potência dos equipamento. (crescente)" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "Sua opção: ";
                char ordem; // variável de escolha entre A e B
                cin >> ordem;
                fflush(stdin);
                ordem = toupper(ordem); // transforma o char em maiúsculo para validar no do...while
                if(ordem=='A')
                {
                    validaOrdem = true;
                    if(ordenaAlfabetica(&EQUIPAMENTOS))
                        cout << "\nLista ordenada com sucesso! Segue exibição abaixo:\n" << endl;
                    else
                        cout << "\nErro na ordenação!" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "           -- EQUIPAMENTOS EM ORDEM ALFABÉTICA --            " << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    mostraEquip(&EQUIPAMENTOS);
                }
                else if(ordem=='B')
                {
                    validaOrdem = true;
                    if(ordenaPotencia(&EQUIPAMENTOS))
                        cout << "\nLista ordenada com sucesso! Segue exibição abaixo:\n" << endl;
                    else
                        cout << "\nErro na ordenação!" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "            -- EQUIPAMENTOS EM ORDEM CRESCENTE --            " << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    mostraEquip(&EQUIPAMENTOS);
                }
                else
                {
                    cout << "\nOpção inválida! Selecione entre A ou B!\n\n";
                    validaOrdem = false;
                    system("pause");
                }
            }
            while(!validaOrdem); // do...while para forçar escolha correta entre A ou B
        }
        break;

        case 'C':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                -- INFORMAÇÕES DE CLIENTES --                " << endl;
            cout << "-------------------------------------------------------------" << endl;
            infosClientes(&CLIENTES);
            mediaEquip(&CLIENTES);
        }
        break;

        case 'D':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                -- SOMA TOTAL DE POTÊNCIAS --                " << endl;
            cout << "-------------------------------------------------------------" << endl;
            somaPotencia(&CLIENTES, &EQUIPAMENTOS);
        }
        break;

        case 'E':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "          -- EQUIPAMENTO MAIS POTENTE UTILIZADO --           " << endl;
            cout << "-------------------------------------------------------------" << endl;
            mostraEquipMaisPotente(&CLIENTES, &EQUIPAMENTOS);
        }
        break;

        case 'F':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                 -- FILTRAGEM DE CLIENTES --                 " << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "Insira o código do município para busca: ";
            int codMunic;
            cin >> codMunic;
            filtraCliente(&CLIENTES, codMunic, &MUNICIPIOS);
        }
        break;

        case 'Z':
        {
            cout << "\nSaindo do programa...";
            getchar();
            // destruição das estruturas de lista utilizadas
            destroiEquip(&EQUIPAMENTOS);
            destroiMunic(&MUNICIPIOS);
            destroiClien(&CLIENTES);
            exit(0);
        }

        default:
            cout << "\nOpção inválida\n";
            break;
        }


        cout << endl;
        system("pause");
        system("cls");

    }
    while(op!='Z');

}
