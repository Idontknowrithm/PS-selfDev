#include<iostream>

typedef struct _node{
    char data;
    struct _node* left;
    struct _node* right;
}node;

node tree[26];
int N;

void prefix(node Node){
    std::cout << Node.data;
    if(Node.left)
        prefix(*Node.left);
    if(Node.right)
        prefix(*Node.right);
}
void inorder(node Node){
    if(Node.left)
        inorder(*Node.left);
    std::cout << Node.data;
    if(Node.right)
        inorder(*Node.right);
}
void postfix(node Node){
    if(Node.left)
        postfix(*Node.left);
    if(Node.right)
        postfix(*Node.right);
    std::cout << Node.data;
}

int main () {
    char inp[3];

    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> inp[0] >> inp[1] >> inp[2];

        tree[inp[0] - 'A'].data = inp[0];
        tree[inp[0] - 'A'].left = (inp[1] != '.') ? &tree[inp[1] - 'A'] : NULL;
        tree[inp[0] - 'A'].right = (inp[2] != '.') ? &tree[inp[2] - 'A'] : NULL;
    }
    prefix(tree[0]);
    std::cout << std::endl;
    inorder(tree[0]);
    std::cout << std::endl;
    postfix(tree[0]);
    return 0;
}
