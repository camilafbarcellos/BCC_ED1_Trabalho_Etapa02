#include <iostream>
#include <cstring>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>

// Trabalho Final - Etapa 02 de ED1 - mar�o de 2022
// Camila Florao Barcellos
// 20202PF.CC0003

using namespace std;

#include "estruturas.hpp" // inclus�o do hpp de estruturas
#include "lista.hpp" // inclus�o do hpp de lista simples

/// OPERA��O 'A'
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

void mostraMunic(NoMunic **lista) // lista de munic�pios
{
    NoMunic *n = *lista;

    cout << "Munic�pios: {\n";
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

/// OPERA��O 'B'
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
                // verifica se � o �ltimo dado ou primeiro dado (rela��o direta com NULL)
                if(anterior)
                {
                    if((anterior->dado.nome) > (atual->dado.nome)) // verifica ordem
                    {
                        Equipamento aux = anterior->dado; // utiliza auxiliar para armanezenar n� anterior
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
        cout << "\nA lista de clientes est� vazia!" << endl;

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
                // verifica se � o �ltimo dado ou primeiro dado (rela��o direta com NULL)
                if(anterior)
                {
                    if((anterior->dado.potencia) > (atual->dado.potencia)) // verifica ordem
                    {
                        Equipamento aux = anterior->dado; // utiliza auxiliar para armanezenar n� anterior
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
        cout << "\nA lista de clientes est� vazia!" << endl;

        return false;
    }
}

/// OPERA��O 'C'
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

        n = *lista; // retorna o ponteiro para o in�cio da lista
        while(n)
        {
            if(n->dado.idade>30)
                cont30++;

            n = n->prox;
        }

        cout << "N�mero de clientes do sexo feminino (F): " << contF << endl;
        cout << "N�mero de clientes do sexo masculino (M): " << contM << endl;
        cout << "N�mero de clientes acima de 30 anos: " << cont30 << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes est� vazia!" << endl;

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
            quantEquip += n->dado.equipClientes->tamanho; // acumula na vari�vel o tamanho de cada lista

            n = n->prox;
        }
        cout << "-------------------------------------------------------------" << endl;
        cout << "Quantidade total de equipamentos: " << quantEquip << endl;
        int quantClien = totalClien(lista);
        cout << "Quantidade de clientes: " << quantClien << endl;
        cout << "-------------------------------------------------------------" << endl;
        float media = float(quantEquip) / float(quantClien);
        cout << "M�dia da quantidade de equipamentos nas resid�ncias: " << media << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes est� vazia!" << endl;

        return;
    }
}

/// OPERA��O 'D'
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
                    if(n->dado == e->dado.codigo) // verifica se c�digo na lista C equivale � lista E
                        soma += e->dado.potencia; // acumula pot�ncia na vari�vel de soma
                }
            }
        }
        cout << "Soma total de pot�ncia dos equip. instalados: " << soma << "W" << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes est� vazia!" << endl;

        return;
    }
}

/// OPERA��O 'E'
void buscaCliente(NoClien **clientes, int valor)
{
    NoClien *n = *clientes;
    int cont = 0; // vari�vel contadora para quantidade de clientes encontrados
    cout << "Clientes que utilizam o equipamento: " << endl;
    for(NoClien *c = *clientes; c != NULL; c = c->prox) // percorre lista de clientes
    {
        for(No *n = c->dado.equipClientes->inicio; n != NULL; n = n->prox) // percorre lista de equipamentos do cliente
        {
            if(n->dado == valor) // verifica se � o mesmo c�digo
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
        int maiorPot = e->dado.potencia; // pr�-define a primeira pot�ncia como a maior
        string maiorPotNome = e->dado.nome; // pr�-define o nome do equipamento mais potente
        int maiorPotCod = e->dado.codigo; // pr�-define o codigo do equipamento mais potente

        for(NoClien *c = *clientes; c != NULL; c = c->prox) // percorre lista de clientes
        {
            for(No *n = c->dado.equipClientes->inicio; n != NULL; n = n->prox) // percorre lista de equipamentos do cliente
            {
                for(e = *equipamentos; e != NULL; e = e->prox) // percorre lista de equipamentos
                {
                    if(n->dado == e->dado.codigo) // verifica se c�digo na lista C equivale � lista E
                        if(e->dado.potencia > maiorPot) // verifica se pot�ncia � maior que a atual
                        {
                            maiorPot = e->dado.potencia; // substitui valor da pot�ncia
                            maiorPotNome = e->dado.nome; // substitui nome do equipamento
                            maiorPotCod = e->dado.codigo; // substitui c�digo do equipamento
                        }
                }
            }
        }

        cout << "Nome do equipamento: " << maiorPotNome << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Pot�ncia do equipamento: " << maiorPot << "W" << endl;
        cout << "C�digo do equipamento: " << maiorPotCod << endl;
        cout << "-------------------------------------------------------------" << endl;

        buscaCliente(clientes, maiorPotCod); // aciona fun��o para exibir clientes que possu�rem o c�digo obtido

        return;
    }

    else
    {
        cout << "\nA lista de clientes est� vazia!" << endl;

        return;
    }
}

/// OPERA��O 'F'
void filtraCliente(NoClien **clientes, int cod, NoMunic **municipios)
{
    if(!vaziaClien(clientes))
    {
        NoMunic *m = *municipios;
        bool validaMunic = false; // validador do munic�pio


        while(m)
        {
            if(cod == m->dado.codigo) // verifica se c�digo informado corresponde a um munic�pio cadastrado
            {
                cout << "   -> Munic�pio encontrado: " << cod << " - " << m->dado.nome << endl; // exibe nome do munic�pio
                validaMunic = true; // valida o munic�pio para permitir continuidade da fun��o filtraCliente
            }

            m = m->prox;
        }

        if(validaMunic)
        {
            NoClien *c = *clientes;
            int cont = 0; // vari�vel contadora para quantidade de clientes encontrados
            cout << "\nClientes residentes no munic�pio de c�digo " << cod  << ": " << endl;
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

        else // caso validador do munic�pio n�o encontre correspond�ncia, retorna erro
            cout << "\nMun�cipio n�o cadastrado ou c�digo incorreto!" << endl;

        return;
    }

    else
    {
        cout << "\nA lista de clientes est� vazia!" << endl;

        return;
    }
}

int main()
{
    setlocale (LC_ALL, "Portuguese");

    /// Declara��o dos n�s
    NoEquip* EQUIPAMENTOS; // lista de equipamentos
    NoMunic* MUNICIPIOS; // lista de munic�pios
    NoClien* CLIENTES; // lista de clientes

    /// Inicializa��o das listas
    inicializaEquip(&EQUIPAMENTOS);
    inicializaMunic(&MUNICIPIOS);
    inicializaClien(&CLIENTES);

    /// Declara��o das estruturas
    Equipamento equipamento;
    Municipio municipio;
    // vari�vel cliente ser� declarada dentro do la�o na leitura

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
            // verificar lista de acordo com nome -> previne tamb�m que a linha de t�tulo caia no switch
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
                    Cliente cliente; // declara��o do cliente
                    cliente.equipClientes = new Lista(); // declara��o da lista de equipamentos do cliente
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
                            cliente.sexo = dado[1]; // posi��o dado[1] pois dado[0] armazena ' ' (espa�o em branco)
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
        cout << "           Aus�ncia do arquivo 'cadastro.txt'" << endl;
        cout << "-------------------------------------------------------------\n\n" << endl;
    }
    arquivo.close();

    system("pause");

    /// PROGRAMA PRINCIPAL -> CONCESSION�RIA RS ENERGIA

    char op; // vari�vel de opera��o para controlar menu no switch...case

    do
    {
        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "               -- CONCESSION�RIA RS ENERGIA --               " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "  a) Mostrar listas de equipamentos, munic�pios e clientes" << endl;
        cout << "  b) Mostrar listas de equipamentos de forma ordenada" << endl;
        cout << "  c) Mostrar informa��es dos clientes" << endl;
        cout << "  d) Mostrar total de pot�ncia dos equipamentos instalados" << endl;
        cout << "  e) Mostrar equipamento mais potente e seus clientes" << endl;
        cout << "  f) Filtrar cliente por munic�pio" << endl;
        cout << "\n  z) Sair" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Sua op��o: ";
        cin >> op;
        fflush(stdin);
        op = toupper(op); // transforma o char em mai�sculo para validar no switch...case

        switch(op)
        {
        case 'A':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                  -- EXIBI��O DAS LISTAS --                  " << endl;
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
            bool validaOrdem = true; // validador da escolha da ordena��o
            do
            {
                system("cls");
                cout << "-------------------------------------------------------------" << endl;
                cout << "               -- ORDENA��O DE EQUIPAMENTOS --               " << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "  a) Ordena��o por nome (alfab�tica)" << endl;
                cout << "  b) Ordena��o por pot�ncia dos equipamento. (crescente)" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "Sua op��o: ";
                char ordem; // vari�vel de escolha entre A e B
                cin >> ordem;
                fflush(stdin);
                ordem = toupper(ordem); // transforma o char em mai�sculo para validar no do...while
                if(ordem=='A')
                {
                    validaOrdem = true;
                    if(ordenaAlfabetica(&EQUIPAMENTOS))
                        cout << "\nLista ordenada com sucesso! Segue exibi��o abaixo:\n" << endl;
                    else
                        cout << "\nErro na ordena��o!" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "           -- EQUIPAMENTOS EM ORDEM ALFAB�TICA --            " << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    mostraEquip(&EQUIPAMENTOS);
                }
                else if(ordem=='B')
                {
                    validaOrdem = true;
                    if(ordenaPotencia(&EQUIPAMENTOS))
                        cout << "\nLista ordenada com sucesso! Segue exibi��o abaixo:\n" << endl;
                    else
                        cout << "\nErro na ordena��o!" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "            -- EQUIPAMENTOS EM ORDEM CRESCENTE --            " << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    mostraEquip(&EQUIPAMENTOS);
                }
                else
                {
                    cout << "\nOp��o inv�lida! Selecione entre A ou B!\n\n";
                    validaOrdem = false;
                    system("pause");
                }
            }
            while(!validaOrdem); // do...while para for�ar escolha correta entre A ou B
        }
        break;

        case 'C':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                -- INFORMA��ES DE CLIENTES --                " << endl;
            cout << "-------------------------------------------------------------" << endl;
            infosClientes(&CLIENTES);
            mediaEquip(&CLIENTES);
        }
        break;

        case 'D':
        {
            system("cls");
            cout << "-------------------------------------------------------------" << endl;
            cout << "                -- SOMA TOTAL DE POT�NCIAS --                " << endl;
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
            cout << "Insira o c�digo do munic�pio para busca: ";
            int codMunic;
            cin >> codMunic;
            filtraCliente(&CLIENTES, codMunic, &MUNICIPIOS);
        }
        break;

        case 'Z':
        {
            cout << "\nSaindo do programa...";
            getchar();
            // destrui��o das estruturas de lista utilizadas
            destroiEquip(&EQUIPAMENTOS);
            destroiMunic(&MUNICIPIOS);
            destroiClien(&CLIENTES);
            exit(0);
        }

        default:
            cout << "\nOp��o inv�lida\n";
            break;
        }


        cout << endl;
        system("pause");
        system("cls");

    }
    while(op!='Z');

}
