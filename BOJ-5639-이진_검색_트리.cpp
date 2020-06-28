#include<iostream>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

void printSuffix(Node *tree){
    if(tree == NULL){
        return;
    }
    printSuffix(tree->left);
    printSuffix(tree->right);
    printf("%d\n", tree->data);
}
int main(){
    Node *temp, *newNode, *root = NULL;
    int input; bool first = true;
    while(scanf("%d", &input) != EOF){
        if(first == true){
            newNode = new Node;
            newNode->data = input;
            newNode->left = newNode->right = NULL;
            root = newNode;
            first = false;
            continue;
        }
        temp = root;
        newNode = NULL;
        while(1){
            if(temp->data < input && !temp->right){
                newNode = new Node;
                newNode->data = input;
                newNode->left = newNode->right = NULL;
                temp->right = newNode;
                break;
            }
            else if(temp->data > input && !temp->left){
                newNode = new Node;
                newNode->data = input;
                newNode->left = newNode->right = NULL;
                temp->left = newNode;
                break;
            }
            else if(temp->data < input){
                temp = temp->right;
            }
            else if(temp->data > input){
                temp = temp->left;
            }
        }
    }
    printSuffix(root);
    
    return 0;
}
