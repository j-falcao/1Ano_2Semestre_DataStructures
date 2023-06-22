#include "Tree.h"


Tree* createTree(){
    Tree* newTree = (Tree*) malloc(sizeof(Tree));
    newTree->numNodes = 0;
    newTree->root = NULL;
    return newTree;
}

Node* createNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void WriteToNode(Node* node){
    if(!node){
        printc("\n\t[red]Error![/red] Given node is NULL\n");
        return;
    }
    node = generateRandomPerson();
}

int SameNodesByAge(Node* A, Node* B){
    if(!A){
        printc("\n\t[red]Error![/red] Given node 'A' is NULL\n");
        return 0;
    }
    if(!B){
        printc("\n\t[red]Error![/red] Given node 'B' is NULL\n");
        return 0;
    }
    if(A->info->age == B->info->age)
        return 1;
    return 0;
}

void InsertNode(Tree* T, Node* newNode){
    
}

Node* searchByAge(Tree* T, int age){

}

void printNode(Node* node){

}

void mostrarInOrder(Node* root){

}

void mostrarPreOrder(Node* root){

}

void mostrarPostOrder(Node* root){

}

void freeNode(Node* node){

}

Node* removeNodeByAge(Tree* T, Node* node){

}

int countNodes(Tree* T){

}

int countNodeAgeGreaterThan(Tree* T, int age){

}

int countNodeWeightLessThan(Tree* T, float MaxWeight){

}

int HeightTree(Tree* T){

}
