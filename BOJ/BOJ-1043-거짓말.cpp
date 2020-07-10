// 그래프 정보와 진실된 사람의 배열(truePP) 정보를 혼동하여 인덱스에 반영

#include<iostream>
#include<vector>
#include<queue>

std::vector<int> graph[60];
int N, M, truer, partyPP, inp, trueParty, truePP[60], visited[60], party[60][60];

void traversal(int target){
    std::queue<int> bfs;
    bfs.push(target);
    for(int i = 0; i < 60; ++i)
        visited[i] = 0;
    while(!bfs.empty()){
        for(int i = 0; i < graph[bfs.front()].size(); ++i){
            if(!visited[graph[bfs.front()][i]]){
                party[graph[bfs.front()][i]][55] = visited[graph[bfs.front()][i]] = 1;
                bfs.push(graph[bfs.front()][i]);
            }
        }
        bfs.pop();
    }
}

int main() {
    scanf("%d %d\n%d", &N, &M, &truer);
    for(int i = 0; i < truer; ++i)
        scanf("%d", &truePP[i]);
    for(int i = 0; i < M; ++i){
        scanf("%d", &partyPP);
        for(int u = 0; u < partyPP; ++u){
            scanf("%d", &inp);
            ++party[i][inp];
        }
    }

    for(int i = 0; i < truer; ++i){
        for(int u = 0; u < M; ++u){
            party[u][55] = (party[u][truePP[i]]) ? 1 : party[u][55];
        }
    }
    for(int i = 0; i < M; ++i){
        for(int u = 1; u <= N; ++u){
            if(party[i][u]){
                for(int k = 0; k < M; ++k){
                    if(k != i && party[k][u]){
                        graph[k].push_back(i);
                        graph[i].push_back(k);
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < M; ++i){
        for(int u = 0; u < truer; ++u){
            if(party[i][truePP[u]] == 1)
                traversal(i);
        }
    }

    for(int i = 0; i < M; ++i)
        trueParty += party[i][55];
    printf("%d", M - trueParty);

    return 0;
}
