#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int N, M, start, dest, visited[105];
std::vector<int> family[105];

int find(){
    std::queue<std::pair<int, int>> bfs;
    bfs.push({start, 0});

    while(!bfs.empty()){
        int curS, curL;
        curS = bfs.front().first;
        curL = bfs.front().second;
        bfs.pop();
        if(curS == dest) return curL;
        for(int i = 0; i < family[curS].size(); ++i){
            if(!visited[family[curS][i]]){
                bfs.push({family[curS][i], curL + 1});
                visited[family[curS][i]] = 1;
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d\n%d %d\n%d", &N, &start, &dest, &M);

    for(int i = 0; i < M; ++i){ //start from 1, not 0
        int inp1, inp2;
        scanf("%d %d", &inp1, &inp2);
        family[inp1].push_back(inp2);
        family[inp2].push_back(inp1);
    }
    printf("%d", find());

    return 0;
}
