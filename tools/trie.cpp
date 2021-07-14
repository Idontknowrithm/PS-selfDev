#include<iostream>
#include<cstring>

const int ALPHABETS = 26;
int ctoi(char ch){
    return ch - 'A';
}

class trie_node{
    trie_node* children[ALPHABETS];
    // Is it end node?
    bool terminal;
    trie_node() : terminal(false){
        memset(children, 0, sizeof(children));
    }
    ~trie_node(){
        for(int i = 0; i < ALPHABETS; ++i)
            if(children[i])
                delete children[i];
    }
    // add key(string) to trie whose root is this node
    void insert(const char* key){
        // if string is end, then change the value of terminal to true, and terminate
        if(*key == 0)
            terminal = true;
        else{
            int next = ctoi(*key);
            // if there is not a corresponding child node, create it
            if(children[next] == NULL)
                children[next] = new trie_node();
            // recurse by corresponding child node
            children[next]->insert(key + 1);
        }
    }
    trie_node* find(const char* key){
        if(*key == 0) return this;
        int next = ctoi(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key + 1);
    }
};
