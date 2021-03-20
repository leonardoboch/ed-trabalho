#include "Node.h"
int readFile(string fileName) {
    int size = 0;
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << endl;
            size++;
        }
        myfile.close();
        return size;
    }

    else {
        cout << "Unable to open file";
        return 0;
    }
}

Node* allocation(int size) {
    Node* nodeList = new Node[size];
    for (int i = 0; i < size; i++) {
        nodeList[i].rg = 0;
        nodeList[i].pessoa = "";
    }
    return nodeList;
}

void storage(Node* nodeList, string fileName) {
    int size = 0;
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            nodeList[size].pessoa = line;
            size++;
        }
        myfile.close();
    }

    else {
        cout << "Unable to open file";
    }
}

void splitName(Node* nodeList, int size) {

    int commaIndex = 0;
    for (int i = 0; i < size; i++) {
        string aux = nodeList[i].pessoa;
        for (int j = 0; j <= aux.length(); j++) {

            if (aux[j] == ',') {
                commaIndex = j;
            }
        }

        aux = aux.substr((commaIndex + 1), aux.length());

        nodeList[i].rg = stoi(aux);
    }

    
}
void insertEndList(Node* nodeList, int *size) {
    int aux = *size, c = 0, m = 0;
    cout << "Insira uma string no formato  \" Nome,RG \" " << endl;
    string pessoaAux;
    cin >> pessoaAux;
    nodeList[aux].pessoa = pessoaAux;
    m++;
    *size = aux + 1;;
    splitName(nodeList, *size);

    cout << "Pessoa: " << pessoaAux << " inserida C(n) = " << c << " M(n) = " << m << endl;
    

}
void insertBeginList(Node* original, int *size) {
    Node atual, post;
    int aux = *size;
    int m = 0, c = 0;
    for (int i = 0; i < aux; i++) {
        if (i == 0) {
            atual.pessoa = original[i].pessoa;
            atual.rg = original[i].rg;
            m = m + 1;
            c = c + 1;
        }
        else {
            atual = post;
            m = m + 1;
        }
        

        post.pessoa = original[i + 1].pessoa;
        m = m + 1;
        post.rg = original[i + 1].rg;
        m = m + 1;

        original[i + 1].pessoa = atual.pessoa;
        m = m + 1;
        original[i + 1].rg = atual.rg;
        m = m + 1;

    }

    cout << "Insira uma string no formato  \" Nome,RG \" " << endl;
    string pessoaAux;
    cin >> pessoaAux;

    original[0].pessoa = pessoaAux;
    m = m + 1;
    aux++;
    *size = aux;

    cout << "Pessoa: " << pessoaAux << " inserida C(n) = " << c << " M(n) = " << m << endl;
    splitName(original, *size);

}

void insertNlist(Node* nodeList, int* size) {
    int pos = 0, m = 0, c = 0, aux = 0;
    aux = *size;
    cout << "Digite uma posicao da lista para inserir o elemento" << endl;
    cin >> pos;
    if (pos == 0) {
        insertBeginList(nodeList, size);
    }
    else if (pos == *size) {
        insertEndList(nodeList, size);
    }
    else {
        cout << "Insira uma string no formato  \" Nome,RG \" " << endl;
        string pessoaAux;
        cin >> pessoaAux;
        Node atual, posterior;
        atual = nodeList[pos];

        for (int i = (pos); i < *size; i++) {
            posterior = nodeList[i + 1];
            m++;
            nodeList[i + 1] = atual;
            m++;
            atual = posterior;
            m++;
        }
        nodeList[pos].pessoa = pessoaAux; 
        cout << "Pessoa: " << pessoaAux << " inserida C(n) = " << c << " M(n) = " << m << endl;

     }
    aux++;
    *size = aux;
    splitName(nodeList, *size);


}
void removeBeginList(Node* nodeList, int* size) {
    string pessoaAux = nodeList[0].pessoa;
    int m = 0, c = 0;
    for (int i = 0; i < *size; i++) {
        nodeList[i] = nodeList[i + 1];
        m++;

    }
    nodeList[*size].pessoa = "";
    m++;
    nodeList[*size].rg = 0;
    m++;
    *size = *size - 1;
    cout << "Pessoa: " << pessoaAux << " removida C(n) = " << c << " M(n) = " << m << endl;
}
void removeEndList(Node* nodeList, int* size) {
    string pessoaAux = nodeList[*size].pessoa;
    int c = 0, m = 0;
    nodeList[*size].pessoa = "";
    m++;
    nodeList[*size].rg = 0;
    m++;
    *size = *size - 1;
    cout << "Pessoa: " << pessoaAux << " removida C(n) = " << c << " M(n) = " << m << endl;

}

void removeNlist(Node* nodeList, int* size) {
    cout << "Digite a posicao que deseja remover : " << endl;
    int pos = 0, c = 0, m = 0;
    cin >> pos;
    if (pos == 0) {
        removeBeginList(nodeList, size);
    }
    else if (pos == *size) {
        removeEndList(nodeList, size);
    }
    else {
        string pessoaAux = nodeList[pos].pessoa;
        for (int i = pos; i < *size; i++) {
            nodeList[i] = nodeList[i + 1];
            m++;
        }
        nodeList[*size].pessoa = "";
        nodeList[*size].rg = 0;

        *size = *size - 1;
        cout << "Pessoa: " << pessoaAux << " removida C(n) = " << c << " M(n) = " << m << endl;


    }
}

void printList(Node* nodeList, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]";
        cout << nodeList[i].pessoa << endl;
        cout << "***************" << endl;
    }
}
void sequencialSearch(Node* nodeList, int* size) {
    cout << "Digite um RG para procurar na lista " << endl;
    int auxRg = 0, m = 0, c = 0;
    cin >> auxRg;

    for (int i = 0; i < *size; i++) {
        if (auxRg == nodeList[i].rg) {
            c++;
            cout << "Pessoa: " << nodeList[i].pessoa << endl;
            cout << "Posicao: " << i << endl;
        }
    }

    cout << "C(n) = c " << c << " M(n) = " << m << endl;
}
void writeToFile(Node* nodeList, int* size) {
    ofstream file("lista_sequencial.txt");
    for (int i = 0; i < *size; i++) {
        file << nodeList[i].pessoa;
        file << "\n";
    }
    file.close();
}

