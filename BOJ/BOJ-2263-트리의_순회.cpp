#include<iostream>
#include<vector>
#include<set>
#include<queue>

typedef struct{
    int is, ie, ps, pe;
}query;

int N, afa;
std::vector<int> in, post, pre;

// [start, end)
int find(int value){
    for(int i = 0; i < in.size(); ++i)
        if(in[i] == value) return i;
    return -1;
}
void traversal(int in_start, int in_end, int post_start, int post_end){
    
    pre.push_back(post[post_end - 1]);
    int divider = find(post[post_end - 1]);
    if(divider == -1) {
        printf("ERR\n");
        return;
    }
    if(afa < 100)
    printf("star %d %d %d %d\n", in_start, divider, post_start, divider);
    traversal(in_start, divider, post_start, divider);
    if(afa < 100)
    printf("en %d %d %d %d\n", divider + 1, in_end, divider, post_end - 1);
    traversal(divider + 1, in_end, divider, post_end - 1);
}
void trav(int in_start, int in_end, int post_start, int post_end){
    std::queue<query> q;
    q.push({in_start, in_end, post_start, post_end});

    while(!q.empty()){
        query tmp = q.front();
        q.pop();
        if(tmp.is == tmp.ie || tmp.ps == tmp.pe) continue;
        if(tmp.is + 1 == tmp.ie || tmp.ps + 1 == tmp.pe){
            pre.push_back(post[tmp.ps]);
            continue;
        }
        pre.push_back(post[tmp.pe - 1]);
        int divider = find(post[tmp.pe - 1]);
        traversal
    }
}

int main() {
    int input;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &input);
        in.push_back(input);
    }
    for(int i = 0; i < N; ++i){
        scanf("%d", &input);
        post.push_back(input);
    }
    traversal(0, in.size(), 0, post.size());
    
    for(int i = 0; i < pre.size(); ++i)
        printf("%d ", pre[i]);
    return 0;
}
