#include <iostream>
#include <ctime>

//Camila Florão Barcellos
//Trabalho prático 1

using namespace std;

void gerar(int **pvet, int tam, int &i);
void localizar(int **pvet, int **psobra, int tam, int &i, int &cont);
void mostrarVet(int **pvet, int tam);
void mostrarSobra(int **psobra, int tam);
void verificar(int **pvet, int tam);

int main ()
{
    setlocale (LC_ALL, "Portuguese");
    srand(time(NULL));

    int tam=0;
    int *pvet = new int[tam];
    int *psobra = new int[tam];
    int menu=-1, indice=-1, indice2=-1, cont=-1;

    do
    {
        system("cls");
        cout << "----------------------------" << endl;
        cout << "         -- MENU --         " << endl;
        cout << "----------------------------" << endl;
        cout << "  0- Sair                   " << endl;
        cout << "  1- Gerar valores          " << endl;
        cout << "  2- Localizar valor        " << endl;
        cout << "  3- Mostrar vetor vet      " << endl;
        cout << "  4- Mostrar vetor sobra    " << endl;
        cout << "----------------------------" << endl;
        cout << "Sua opção: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0:
            cout << "\n<< PROGRAMA FINALIZADO! >>\n";
            getchar();
            break;
        case 1:
        {
            system("cls");
            cout << "-- GERAR VETOR --" << endl;
            do
            {
                cout << "Insira o tamanho do vetor (máx. 100): ";
                cin >> tam;
                if(tam>=101)
                    cout << "<< TAMANHO INVÁLIDO! >>" << endl;
            }
            while(tam>=101);
            //inicializar vetor sobra com zeros
            for(int l=0; l<tam; l++)
            {
                *(psobra+l) = 0;
            }
            gerar(&pvet, tam, indice);
            getchar();
        }
        break;
        case 2:
            system("cls");
            if(indice<0)
                cout << "<< NÃO EXISTE NENHUM VETOR NO MOMENTO! >>";
            else
                localizar(&pvet, &psobra, tam, indice2, cont);
            getchar();
            break;
        case 3:
            system("cls");
            if(indice<0)
                cout << "<< NÃO EXISTE NENHUM VETOR NO MOMENTO! >>";
            else
                mostrarVet(&pvet, tam);
            getchar();
            break;
        case 4:
            system("cls");
            if(indice2<0)
                cout << "<< NÃO EXISTE NENHUM VETOR SOBRA NO MOMENTO! >>";
            else
                mostrarSobra(&psobra, tam);
            getchar();
            break;
        default:
            cout << "\n<< OPÇÃO INVÁLIDA! >>\n";
            getchar();
            break;

        };
    }
    while(menu!=0);
}

void gerar(int **pvet, int tam, int &i)
{
    i++;

    for(int l=0; l<tam; l++)
    {
        (*((*pvet)+l)) = rand()%100;
        for(int m=tam; m>=0; m--)
        {
            if((*((*pvet)+l))==(*((*pvet)+m))) //verificar repetição
                (*((*pvet)+l)) = rand()%100;
        }
    }

    cout << "\n-- VETOR GERADO COM SUCESSO! --" << endl;

    getchar();
    return;
}

void localizar(int **pvet, int **psobra, int tam, int &i, int &cont)
{
    i++;

    int val;

    cout << "-- LOCALIZAR VALOR --" << endl;
    cout << "Informe o valor de pesquisa: ";
    cin >> val;

    for(int l=0; l<tam; l++)
    {
        if(val==(*((*pvet)+l)))
        {
            cout << "\nValor " << val << " pertence ao vetor!" << endl;
            getchar();
            return;
        }

        else
        {
            cout << "\nValor " << val << " não pertence ao vetor!" << endl;
            cout << "O valor será incluído no vetor SOBRA, disponível na opção 4!" << endl;
            cont++; //contagem de vetor sobra
            if(cont>=tam) //verificar se há espaço no vetor
            {
                for(int l=0; l<tam; l++) //se não tiver espaço, zerar vetor
                {
                    (*((*psobra)+l)) = 0;
                }
                cont = 0;
                (*((*psobra)+cont)) = val;
                getchar();
                return;
            }

            else
            {
                (*((*psobra)+cont)) = val;
                getchar();
                return;
            }

        }
    }
}

void mostrarVet(int **pvet, int tam)
{
    cout << "-- VETOR GERADO --" << endl;
    for(int k=0; k<tam; k++)
    {
        cout << (*((*pvet)+k));
        if(k!=tam-1)
            cout << ", ";
        else
            cout << endl;
    }

    return;
}

void mostrarSobra(int **psobra, int tam)
{
    cout << "-- VETOR SOBRA --" << endl;
    for(int k=0; k<tam; k++)
    {
        cout << (*((*psobra)+k));
        if(k!=tam-1)
            cout << ", ";
        else
            cout << endl;
    }

    return;
}

