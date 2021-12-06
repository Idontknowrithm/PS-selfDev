#include<iostream>
#include<cstring>

const int ALPHABETS = 26;
int ctoi(char ch){
    return ch - 'a';
}

class trie_node{
    public:
        int child_size = 0;
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
                if(children[next] == NULL){
                    children[next] = new trie_node();
                    ++child_size;
                }
                // recurse by corresponding child node
                children[next]->insert(key + 1);
            }
        }
        int find(char* key){
            int ret = 1;
            char *next = key + 1;
            trie_node *ptr = this->children[ctoi(*key)];
            while(1){
                if(!(*next)){
                    break;
                }
                if(ptr->child_size > 1 || ptr->terminal == true){
                    ++ret;
                }
                ptr = ptr->children[ctoi(*next)];
                ++next;
            }
            return ret;
        }
};

int N;
char str[100005][85];

int main() {
    while(scanf("%d\n", &N) != EOF){
        trie_node trie;
        for(int i = 0; i < N; ++i){
            scanf("%s", str[i]);
            getchar();
            trie.insert(str[i]);
        }
        double ans = 0;
        for(int i = 0; i < N; ++i){
            ans += trie.find(str[i]);
        }
        ans /= N;
        printf("%.2lf\n", ans);
    }
    return 0;
}
