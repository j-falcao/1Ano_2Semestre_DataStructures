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

void insertLeft(Node* root, Node* nodeToInsert){
    if(!root){
        printc("\n\t[red]Error![/red] Given node 'root' is NULL\n");
        return;
    }
    if(!nodeToInsert){
        printc("\n\t[red]Error![/red] Given node 'nodeToInsert' is NULL\n");
        return;
    }
    if(!root->left)
        root->left = nodeToInsert;
    if(nodeToInsert->info->age > root->left->info->age)
        insertRight(root->left, nodeToInsert);
    if(nodeToInsert->info->age < root->left->info->age)
        insertLeft(root->left, nodeToInsert);
}

void insertRight(Node* root, Node* nodeToInsert){
    if(!root){
        printc("\n\t[red]Error![/red] Given node 'root' is NULL\n");
        return;
    }
    if(!nodeToInsert){
        printc("\n\t[red]Error![/red] Given node 'nodeToInsert' is NULL\n");
        return;
    }
    if(!root->right)
        root->right = nodeToInsert;
    if(nodeToInsert->info->age > root->right->info->age)
        insertRight(root->right, nodeToInsert);
    if(nodeToInsert->info->age < root->right->info->age)
        insertLeft(root->right, nodeToInsert);
}

void insertNode(Tree* T, Node* newNode){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return;
    }
    if(!newNode){
        printc("\n\t[red]Error![/red] Given node is NULL\n");
        return;
    }
    if(!T->root)
        T->root = newNode;
    else{
        if(newNode->info->age > T->root->info->age)
            insertRight(T->root, newNode);
        if(newNode->info->age < T->root->info->age)
            insertLeft(T->root, newNode);
    }
    T->numNodes++;
}

Node* searchByAgeRecursive(Node* root, int age){
    if(!root){
        printc("\n\t[red]Error![/red] Given node is NULL\n");
        return NULL;
    }

    if(age > root->info->age)
        return searchByAgeRecursive(root->right, age);
    else if(age < root->info->age)
        return searchByAgeRecursive(root->left, age);
    return root;
}

Node* searchByAge(Tree* T, int age){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return NULL;
    }
    if(!T->root){
        printc("\n\t[red]Error![/red] Given tree is empty\n");
        return NULL;
    }

    if(age > T->root->info->age)
        return searchByAgeRecursive(T->root->right, age);
    else if(age < T->root->info->age)
        return searchByAgeRecursive(T->root->left, age);
    return T->root;
}

void printNode(Node* node){
    if(!node){
        printc("\n\t[red]Error![/red] Given node is NULL\n");
        return;
    }

    printf("\nName: %s\tAge: %d\tWeight: %.2f\tHeight: %.2f\n");
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
