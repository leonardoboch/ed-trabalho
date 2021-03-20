#include <iostream>
#include "Node.h"
#include"Linked.h"
using namespace std;

int main()
{

    int opc = 0;

    cout << "Selecione o tipo de Lista" << endl;
    cout << "1 ----> Lista Sequencial" << endl;
    cout << "2 ----> Lista Encadeada" << endl;
    cin >> opc;

    if (opc == 1) {
        int aux = -1;
        Node* seq;
        cout << "Digite o nome do arquivo : " << endl;
        string fileName;
        cin >> fileName;
        int size = readFile(fileName);
        seq = allocation(size + 10);
        storage(seq, fileName);
        splitName(seq, size);
        do
        {
            cout << "Selecione o tipo de Operacao" << endl;
            cout << "1 ----> Inserir no inicio" << endl;
            cout << "2 ----> Inserir no Fim" << endl;
            cout << "3 ----> Inserir na posicao N" << endl;
            cout << "4 ----> Remover do Inicio" << endl;
            cout << "5 ----> Remover do fim" << endl;
            cout << "6 ----> Remover da posicao N" << endl;
            cout << "7 ----> Pesquisar" << endl;
            cout << "8 ----> Escrever no Arquivo" << endl;
            cout << "9 ----> Imprimir" << endl;
            cout << "0 ----> Sair" << endl;
            cin >> aux;
            switch (aux)
            {
            case 1: 
                insertBeginList(seq, &size);
                break;
            case 2:
                insertEndList(seq, &size);
                break;
            case 3:
                insertNlist(seq, &size);
                break;
            case 4:
                removeBeginList(seq, &size);
                break;
            case 5:
                removeEndList(seq, &size);
                break;
            case 6:
                removeNlist(seq, &size);
                break;
            case 7:
                splitName(seq, size);
                sequencialSearch(seq, &size);
                break;
            case 8:
                writeToFile(seq, &size);
                break;
            case 9:
                printList(seq, size);
                break;
            }

        } while (aux != 0);
    }
    else if (opc == 2) {
        int aux = -1;
        int size = 0;
        LinkedNode* list;
        cout << "Digite o nome do arquivo : " << endl;
        string fileName;
        cin >> fileName;
        list = linkedStorage(fileName, &size);
        do
        {
            cout << "Selecione o tipo de Operacao" << endl;
            cout << "1 ----> Inserir no inicio" << endl;
            cout << "2 ----> Inserir no Fim" << endl;
            cout << "3 ----> Inserir na posicao N" << endl;
            cout << "4 ----> Remover do Inicio" << endl;
            cout << "5 ----> Remover do fim" << endl;
            cout << "6 ----> Remover da posicao N" << endl;
            cout << "7 ----> Pesquisar" << endl;
            cout << "8 ----> Escrever no Arquivo" << endl;
            cout << "9 ----> Imprimir" << endl;
            cout << "0 ----> Sair" << endl;
            cin >> aux;
            switch (aux)
            {
            case 1:
                list = insertBeginLinked(list, &size);
                break;
            case 2:
                list = insertEndLinked(list, &size);
                break;
            case 3:
                list = insertNlinked(list, &size);
                break;
            case 4:
                list = removeBeginlinked(list, &size);
                break;
            case 5:
                list = removeEndlinked(list, &size);
                break;
            case 6:
                list =  removeNlinked(list, &size);
                break;
            case 7:
                cout << "Entrando em Procura de RG" << endl;
                splitNameLinked(list);
                searchLinked(list);
                break;
            case 8:
                linkedWrite(list);
                break;
            case 9:
                printLinked(list);
                break;
            }

        } while (aux != 0);

    }

}