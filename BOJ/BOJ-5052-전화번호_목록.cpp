#include<iostream>
#include<cstring>

const int NUMBERS = 10;
int ctoi(char ch){
    return ch - '0';
}

class trie_node{
    public:
        trie_node* children[NUMBERS];
        // Is it end node?
        bool terminal;
        trie_node() : terminal(false){
            memset(children, 0, sizeof(children));
        }
        ~trie_node(){
            for(int i = 0; i < NUMBERS; ++i)
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

int T, N;
bool consistent;
char input[15], archive[10005][15];

void is_consistent(trie_node *t, const char *key){
    if(*key == 0) return;

    int next = ctoi(*key);
    if(t->terminal && t->children[next]){
        consistent = false;
        return;
    }
    if(t->children[next])
        is_consistent(t->children[next], key + 1);

}

int main() {
    for(scanf("%d\n", &T); T > 0; --T){
        trie_node trie;
        scanf("%d\n", &N);
        for(int i = 0; i < N; ++i){
            scanf("%s", input);
            getchar();
            trie.insert(input);
            strcpy(archive[i], input);
        }
        consistent = true;
        for(int i = 0; i < N; ++i){
            is_consistent(&trie, archive[i]);
        }
        printf("%s\n", (consistent) ? "YES" : "NO");
    }
}
