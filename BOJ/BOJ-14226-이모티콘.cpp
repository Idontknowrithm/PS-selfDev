#include<iostream>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>
#define clip tmp.second
const int INF = 2100000000;
int S, cache[2005];

int emoji(){
    std::queue<pp> bfs;
    cache[1] = 0;
    bfs.push({1, 0});

    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        if(tmp.first + clip < 2001 && cache[tmp.first + clip] > cache[tmp.first] + 1){
            cache[tmp.first + clip] = cache[tmp.first] + 1;
            bfs.push({tmp.first + clip, clip});
        }
        if(tmp.first != 1 && cache[tmp.first - 1] > cache[tmp.first] + 1){
            cache[tmp.first - 1] = cache[tmp.first] + 1;
            bfs.push({tmp.first - 1, clip});
        }
        if(tmp.first != 1 && cache[tmp.first - 1] > cache[tmp.first] + 2){
            cache[tmp.first - 1] = cache[tmp.first] + 2;
            bfs.push({tmp.first - 1, tmp.first});
        }
        if(tmp.first < 1001 && cache[tmp.first << 1] > cache[tmp.first] + 2){
            cache[tmp.first << 1] = cache[tmp.first] + 2;
            bfs.push({tmp.first << 1, tmp.first});
        }
        
    }
    return cache[S];
}

int main() {
    scanf("%d", &S);
    for(int i = 0; i < 2005; ++i)
        cache[i] = INF;
    printf("%d", emoji());
    return 0;
}
