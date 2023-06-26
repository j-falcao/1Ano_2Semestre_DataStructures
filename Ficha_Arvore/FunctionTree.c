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
    node->info = generateRandomPerson();
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

void insertLeft_version1(Node* root, Node* nodeToInsert){
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
        insertRight_version1(root->left, nodeToInsert);
    if(nodeToInsert->info->age < root->left->info->age)
        insertLeft_version1(root->left, nodeToInsert);
}

void insertRight_version1(Node* root, Node* nodeToInsert){
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
        insertRight_version1(root->right, nodeToInsert);
    if(nodeToInsert->info->age < root->right->info->age)
        insertLeft_version1(root->right, nodeToInsert);
}

void insertNode_version1(Tree* T, Node* newNode){
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
            insertRight_version1(T->root, newNode);
        if(newNode->info->age < T->root->info->age)
            insertLeft_version1(T->root, newNode);
    }
    T->numNodes++;
}

Node* insertNode_version2_recursive(Node* root, Node* newNode){
    if(!root)
        return newNode;
    if(newNode->info > root->info)
        root->right = insertNode_version2_recursive(root->right, newNode);
    if(newNode->info < root->info)
        root->left = insertNode_version2_recursive(root->left, newNode);
    return root;
}

void insertNode_version2(Tree* T, Node* newNode){
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
            T->root->right = insertNode_version2_recursive(T->root->right, newNode);
        if(newNode->info->age < T->root->info->age)
            T->root->left = insertNode_version2_recursive(T->root->left, newNode);
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

    printf("\nName: %s\tAge: %d\tWeight: %.2f\tHeight: %.2f\n", node->info->name, node->info->age, node->info->weight, node->info->height);
}

void printInOrder(Node* root){
    if(!root)
        return;
    printInOrder(root->left);
    printNode(root);
    printInOrder(root->right);
}

void printPreOrder(Node* root){
    if(!root)
        return;
    printNode(root);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(Node* root){
    if(!root)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printNode(root);
}

void freeNode(Node* node){
    free(node->info);
    free(node);
}

Node* removeNodeRecursive(Node* root, Node* nodeToRemove){
    if(nodeToRemove->info->age > root->info->age){
        root->right = removeNodeRecursive(root->right, nodeToRemove);
    } 
    else if(nodeToRemove->info->age < root->info->age){
        root->left = removeNodeRecursive(root->left, nodeToRemove);
    }   
    else{
        if(!root->left && !root->right){    //Case 1: No children
            freeNode(root);
            return NULL;
        }
        else if(!root->left){               //Case 2: One child
            Node* aux = root->right;
            freeNode(root);
            return aux;
        }
        else if(!root->right){              //Case 3: One child
            Node* aux = root->left;
            freeNode(root);
            return aux;
        } 
        else{                               //Case 4: Two children
            Node* aux = root->right;
            while(aux->left)
                aux = aux->left;
            *(root->info) = *(aux->info);
            root->right = removeNodeRecursive(root->right, aux);
        }
    }
    return root;
}

void removeNodeByAge(Tree* T, Node* node){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return;
    }
    if(!T->root){
        printc("\n\t[red]Error![/red] Given tree is empty\n");
        return;
    }
    if(!node){
        printc("\n\t[red]Error![/red] Given node is NULL\n");
        return;
    }

    T->root = removeNodeRecursive(T->root, node);
    T->numNodes--; //Posso fazer isto porque esta funcao a chamada depois de ser chamada a searchByAge, entao vai sempre apagar algum no
}

int countNodes(Tree* T){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return -1;
    }
    return T->numNodes;
}

int countNodeAgeGreaterThanRecursive(Node* root, int age){
    if(!root) return 0;

    int count = countNodeAgeGreaterThanRecursive(root->left, age) + countNodeAgeGreaterThanRecursive(root->right, age);
    return root->info->age > age ? ++count : count;
}

int countNodeAgeGreaterThan(Tree* T, int age){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return -1;
    }
    return countNodeAgeGreaterThanRecursive(T->root, age);
}

int countNodeWeightLessThanRecursive(Node* root, float MaxWeight){
    if(!root) return 0;

    int count = countNodeAgeGreaterThanRecursive(root->left, MaxWeight) + countNodeAgeGreaterThanRecursive(root->right, MaxWeight);
    return root->info->height < MaxWeight ? ++count : count;
}   

int countNodeWeightLessThan(Tree* T, float MaxWeight){
        if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return -1;
    }
    return countNodeAgeGreaterThanRecursive(T->root, MaxWeight);
}

int HeightTreeRecursive(Node* root, int nivel){
    if(!root) return nivel-1;

    int left = HeightTreeRecursive(root->left, nivel + 1);
    int right = HeightTreeRecursive(root->right, nivel + 1);
    return left > right ? left : right;
}

int HeightTree(Tree* T){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return -1;
    }

    int nivel = 0;
    return HeightTreeRecursive(T->root, nivel);
}

void CleanTreeRecursive(Node* root){
    if(!root) return;
    CleanTreeRecursive(root->left);
    CleanTreeRecursive(root->right);
    freeNode(root);
}

void CleanTree(Tree* T){
    if(!T){
        printc("\n\t[red]Error![/red] Given tree is NULL\n");
        return;
    }
    if(T->root) CleanTreeRecursive(T->root), free(T);
}
