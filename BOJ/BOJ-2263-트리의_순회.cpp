// 순회 방법을... 헷갈리지 말자!

#include<iostream>
#include<vector>
#include<set>
#include<queue>

typedef struct{
    int is, ie, ps, pe;
}query;

int N;
std::vector<int> in, post, pre;

// [start, end)
int find(int value){
    for(int i = 0; i < in.size(); ++i)
        if(in[i] == value) return i;
    return -1;
}
void traversal(int in_start, int in_end, int post_start, int post_end){
    if(in_start == in_end || post_start == post_end)
        return;
    if(in_start == in_end || post_start == post_end){
        pre.push_back(post[post_start]);
        return;
    }
    pre.push_back(post[post_end - 1]);
    int divider = find(post[post_end - 1]);
    
    traversal(in_start, divider, post_start, post_start + divider - in_start);
    traversal(divider + 1, in_end, post_end - (in_end - divider), post_end - 1);
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
