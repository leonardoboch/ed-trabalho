#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

typedef struct LinkedNode {
	string pessoa;
	int rg;
	struct LinkedNode* next;
};

LinkedNode *linkedStorage(string fileName, int *size);
void printLinked(LinkedNode* list);
void splitNameLinked(LinkedNode* list);
LinkedNode* insertBeginLinked(LinkedNode* list, int*size);
LinkedNode* insertEndLinked(LinkedNode* list, int* size);
LinkedNode* insertNlinked(LinkedNode* list, int *size);
LinkedNode* removeBeginlinked(LinkedNode* list, int *size);
LinkedNode* removeEndlinked(LinkedNode* list, int *size);
LinkedNode* removeNlinked(LinkedNode* list, int *size);
void searchLinked(LinkedNode* list);
void linkedWrite(LinkedNode* list);
