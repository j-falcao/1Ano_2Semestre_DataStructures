#ifndef ARVORES_H_INCLUDED
#define ARVORES_H_INCLUDED

#include "TipoDados.h"

typedef struct node{
    Person *info;
    struct node *left, *right;
}Node;

typedef struct{
    Node *root;
    int numNodes;
}Tree;

Tree* createTree();
Node* createNode();
void WriteToNode(Node* node);
int compareNodeByAge(Node* A, Node* B);
int SameNodesByAge(Node* A, Node* B);
void InsertNode(Tree* T, Node* newNode);
Node* searchByAge(Tree* T, int age);
void printNode(Node* node);
void mostrarInOrder(Node* root);
void mostrarPreOrder(Node* root);
void mostrarPostOrder(Node* root);
void freeNode(Node* node);
Node* removeNodeByAge(Tree* T, Node* node);
int countNodes(Tree* T);
int countNodeAgeGreaterThan(Tree* T, int age);
int countNodeWeightLessThan(Tree* T, float MaxWeight);
int HeightTree(Tree* T);




#endif