#include<iostream>
#include<queue>

typedef struct{
    long long num;
    int depth;
}data;

int find(long long A, long long B){
    std::queue<data> bfs;
    bfs.push({A, 1});
    while(!bfs.empty()){
        if(bfs.front().num * 10 + 1 == B)
            return bfs.front().depth + 1;
        if(bfs.front().num * 10 + 1 < B)
            bfs.push({bfs.front().num * 10 + 1, bfs.front().depth + 1});
        
        if(bfs.front().num << 1 == B)
            return bfs.front().depth + 1;
        if(bfs.front().num << 1 < B)
            bfs.push({bfs.front().num << 1, bfs.front().depth + 1});

        bfs.pop();
    }
    return -1;
}

int main () {
    long long A, B;
    scanf("%lld %lld", &A, &B);
    printf("%d", find(A, B));

    return 0;
}
