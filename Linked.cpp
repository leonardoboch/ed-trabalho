#include "Linked.h"
LinkedNode* linkedStorage(string fileName, int *size) {
    string line;
    LinkedNode* list = NULL;
    int count = 0;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (list == NULL) {
                LinkedNode* newNode = new LinkedNode;
                newNode->pessoa = line;
                newNode->next = NULL;
                list = newNode;
            }
            else {
                LinkedNode* newNode = new LinkedNode;
                newNode->pessoa = line;
                newNode->next = NULL;
                newNode->next = list;
                list = newNode;
            }
            count++;
        }
        myfile.close();
        *size = count;
        return list;
    }

    else {
        cout << "Unable to open file";
    }


}
void searchLinked(LinkedNode* list) {
    cout << "Digite o RG que deseja achar" << endl;
    int rgAux = 0, count = 0, c = 0, m = 0;
    cin >> rgAux;

    LinkedNode* aux = list;

    while (rgAux != aux->rg) {
        c++;
        aux = aux->next;
        m++;
        count++;
    }
    cout << "Pessoa: " << aux->pessoa << "[" << count << "]" << "C(n) = " << c <<
        "M(n) = " << m << endl;
}
LinkedNode* insertBeginLinked(LinkedNode* list, int* size) {
    int c = 0, m = 0;
    cout << "Digite um nome e RG separados por virgula" << endl;
    string pessoaAux;
    cin >> pessoaAux;
    LinkedNode* newNode = new LinkedNode;
    newNode->pessoa = pessoaAux;
    m++;
    newNode->rg = 0;
    m++;
    newNode->next = list;
    m++;
    list = newNode;
    m++;
    *size = *size + 1;
    cout << "Pessoa: " << pessoaAux <<" [0] " << " inserida C(n) = " << c << " M(n) = " << m << endl;
    return list;
}
LinkedNode* insertEndLinked(LinkedNode* list, int* size) {
    int c = 0, m = 0;
    cout << "Digite um nome e RG separados por virgula" << endl;
    string pessoaAux;
    cin >> pessoaAux;
    LinkedNode* newNode = new LinkedNode;
    newNode->pessoa = pessoaAux;
    m++;
    newNode->rg = 0;
    m++;
    newNode->next = NULL;
    m++;
    LinkedNode* aux = list;
    m++;

    while (aux->next != NULL) {
        c++;
        aux = aux->next;
        m++;
    }
    aux->pessoa = pessoaAux;
    m++;
    *size = *size + 1;
    cout << "Pessoa: " << pessoaAux << '[' << *size << "] "<< " inserida C(n) = " << c << " M(n) = " << m << endl;
    return list;
}
LinkedNode* insertNlinked(LinkedNode* list, int *size) {
    cout << "Digite a posicao que deseja inserir" << endl;
    int pos = 0, count = 0, m = 0, c = 0;
    cin >> pos;
    if (pos == 0) {
        list = insertBeginLinked(list, size);
    }
    else if (pos == *size) {
        list = insertEndLinked(list, size);
    }
    else {
        LinkedNode* atual = list;
        LinkedNode* anterior = NULL;

        while (count != pos) {
            anterior = atual;
            atual = atual->next;
            count++;
            c++;
        }
        cout << "Digite um nome e RG separados por virgula" << endl;
        string pessoaAux;
        cin >> pessoaAux;

        LinkedNode* newNode = new LinkedNode;
        newNode->pessoa = pessoaAux;
        newNode->next = atual;
        m++;
        anterior->next = newNode;
        m++;
        cout << "Pessoa: " << pessoaAux << '['<< pos << "] " << " inserida C(n) = " << c << " M(n) = " << m << endl;
        *size = *size + 1;
    }
    return list;
}

LinkedNode* removeBeginlinked(LinkedNode* list, int* size) {
    int c = 0, m = 0;
    LinkedNode* aux = list;
    m++;
    list = list->next;
    m++;
    cout << "Pessoa: " << aux->pessoa <<"[0] "<< " removida C(n) = " << c << " M(n) = " << m << endl;
    free(aux);
    *size = *size - 1;
    return list;

}
LinkedNode* removeEndlinked(LinkedNode* list, int* size) {
    LinkedNode* atual = list;
    LinkedNode* anterior = NULL;
    int c = 0, m = 0;

    while (atual->next != NULL) {
        c++;
        anterior = atual;
        m++;
        atual = atual->next;
        m++;
    }
    cout << "Pessoa: " << atual->pessoa <<"[" <<(*size - 1) << "] " <<  " removida C(n) = " << c << " M(n) = " << m << endl;
    anterior->next = NULL;
    free(atual);
    *size = *size - 1;
    return list;


}
LinkedNode* removeNlinked(LinkedNode* list, int* size) {
    LinkedNode* anterior = NULL, * atual = list;
    int pos = 0, c = 0, m = 0;

    cout << "Digite a possicao que deseja remover" << endl;
    cin >> pos;
    if (pos == 0) {
        list = removeBeginlinked(list, size);
    }
    else if (pos == *size) {
        list = removeEndlinked(list, size);
    }
    else {
        int count = 0;
        while (count != pos) {
            c++;
            count++;
            anterior = atual;
            m++;
            atual = atual->next;
            m++;
        }        
        anterior->next = atual->next;
        m++;
        cout << "Pessoa: " << atual->pessoa << "[" << pos << "] " << " removida C(n) = " << c << " M(n) = " << m << endl;
        free(atual);
        *size = *size - 1;
        
    }
    return list;
}

void printLinked(LinkedNode* list) {
    LinkedNode* aux = list;

    while (aux != NULL) {
        cout << aux->pessoa << endl;
        cout << aux->rg << endl;
        aux = aux->next;
    }
}

void splitNameLinked(LinkedNode* list) {
    LinkedNode* aux = list;

    int commaIndex = 0;
    for (LinkedNode* aux = list; aux != NULL; aux = aux->next) {
        string auxStr = aux->pessoa;
        for (int i = 0; i < auxStr.length(); i++) {
            if (auxStr[i] == ',') {
                commaIndex = i;
            }
        }
        auxStr = auxStr.substr((commaIndex + 1), auxStr.length());
        aux->rg = stoi(auxStr);
    }
}
void linkedWrite(LinkedNode* list) {
    LinkedNode* aux = list;
    ofstream file("lista_encadeada.txt");
    while (aux != NULL) {
        file << aux->pessoa;
        file << "\n";
        aux = aux->next;
    }
    file.close();
}

