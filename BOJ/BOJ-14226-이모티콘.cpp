// #include<iostream>
// #include<algorithm>
// #include<queue>
// #define pp std::pair<int, int>
// #define clip tmp.second
// const int INF = 2100000000;
// int S, cache[2005];

// int emoji(){
//     std::queue<pp> bfs;
//     cache[1] = 0;
//     bfs.push({1, 0});

//     while(!bfs.empty()){
//         pp tmp = bfs.front();
//         bfs.pop();
//         if(tmp.first + clip < 2001 && cache[tmp.first + clip] > cache[tmp.first] + 1){
//             cache[tmp.first + clip] = cache[tmp.first] + 1;
//             bfs.push({tmp.first + clip, clip});
//         }
//         if(tmp.first != 1 && cache[tmp.first - 1] > cache[tmp.first] + 1){
//             cache[tmp.first - 1] = cache[tmp.first] + 1;
//             bfs.push({tmp.first - 1, clip});
//         }
//         if(tmp.first != 1 && cache[tmp.first - 1] > cache[tmp.first] + 2){
//             cache[tmp.first - 1] = cache[tmp.first] + 2;
//             bfs.push({tmp.first - 1, tmp.first});
//         }
//         if(tmp.first < 1001 && cache[tmp.first << 1] > cache[tmp.first] + 2){
//             cache[tmp.first << 1] = cache[tmp.first] + 2;
//             bfs.push({tmp.first << 1, tmp.first});
//         }
        
//     }
//     return cache[S];
// }

// int main() {
//     scanf("%d", &S);
//     for(int i = 0; i < 2005; ++i)
//         cache[i] = INF;
//     printf("%d", emoji());
//     return 0;
// }

// 2차원 DP를 1차원 DP로 접근
// if문을 억지로 많이 쓰는 듯하면 잘못된 접근임을 
#include<iostream>
#include<queue>
#include<algorithm>

typedef struct{
    int len, time, clip;
}data;

const int INF = 10000;
int S, visited[1005][1005], cache[1005]; // row: len, col: clip

int emoji(){
    std::queue<data> bfs;
    bfs.push({1, 0, 0});
    visited[1][0] = 1;

    while(!bfs.empty()){
        data tmp = bfs.front();
        bfs.pop();
        if(!visited[tmp.len][tmp.len]){
            visited[tmp.len][tmp.len] = 1;
            bfs.push({tmp.len, tmp.time + 1, tmp.len});
        }
        if(tmp.len - 1 >= 0 && !visited[tmp.len - 1][tmp.clip]){
            visited[tmp.len - 1][tmp.clip] = 1;
            bfs.push({tmp.len - 1, tmp.time + 1, tmp.clip});
            cache[tmp.len - 1] = std::min(cache[tmp.len - 1], tmp.time + 1);
        }
        if(tmp.len + tmp.clip <= 1000 && !visited[tmp.len + tmp.clip][tmp.clip]){
            visited[tmp.len + tmp.clip][tmp.clip] = 1;
            bfs.push({tmp.len + tmp.clip, tmp.time + 1, tmp.clip});
            cache[tmp.len + tmp.clip] = std::min(cache[tmp.len + tmp.clip], tmp.time + 1);
        }
    }
    return cache[S];
}

int main() {
    scanf("%d", &S);
    for(int i = 0; i < 1005; ++i)
        cache[i] = INF;
    printf("%d", emoji());
    return 0;
}
