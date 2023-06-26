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
int SameNodesByAge(Node* A, Node* B);
void insertNode_version1(Tree* T, Node* newNode);
void insertRight_version1(Node* root, Node* nodeToInsert);
void insertLeft_version1(Node* root, Node* nodeToInsert);
void insertNode_version2(Tree* T, Node* newNode);
Node* insertNode_version2_recursive(Node* root, Node* newNode);
Node* searchByAge(Tree* T, int age);
void printNode(Node* node);
void printInOrder(Node* root);
void printPreOrder(Node* root);
void printPostOrder(Node* root);
void freeNode(Node* node);
void removeNodeByAge(Tree* T, Node* node);
int countNodes(Tree* T);
int countNodeAgeGreaterThan(Tree* T, int age);
int countNodeWeightLessThan(Tree* T, float MaxWeight);
int HeightTree(Tree* T);
void CleanTree(Tree* T);
#endif