#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
typedef struct Node {
	string pessoa;
	int rg;
};
int readFile(string fileName);
Node* allocation(int size);
void storage(Node* nodeList, string fileName);
void splitName(Node* nodeList, int size);
void printList(Node* nodeList, int size);
void insertEndList(Node* nodeList, int *size);
void insertBeginList(Node* nodeList, int *size);
void insertNlist(Node* nodeList, int* size);
void removeBeginList(Node* nodeList, int* size);
void removeEndList(Node* nodeList, int* size);
void removeNlist(Node* nodeList, int* size);
void sequencialSearch(Node* nodeList, int* size);
void writeToFile(Node* nodeList, int* size);


