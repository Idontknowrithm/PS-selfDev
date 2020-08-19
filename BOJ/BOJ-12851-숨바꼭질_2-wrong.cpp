// out of memory

#include<iostream>
#include<algorithm>
#include<queue>

int N, K, ans, ansNum, visited[200005];

bool possible(int a){
    return (a >= 0 && a < 100001);
}
void find(){
    int f, s; bool goTo = false;
    std::queue<std::pair<int, int>> bfs; // pair<ans, ansNum>
    bfs.push({N, 0});
    visited[N] = 1;
    while(!goTo){
        f = bfs.front().first;
        s = bfs.front().second;
        bfs.pop();

        if(possible(f + 1) && !visited[f + 1]){
            if(f + 1 == K){
                goTo = true;
                ans = s + 1;
            }
            else            
                bfs.push({f + 1, s + 1});
        }
        if(possible(f - 1) && !visited[f - 1]){
            if(f - 1 == K){
                goTo = true;
                ans = s + 1;
            }
            else            
                bfs.push({f - 1, s + 1});
        }
        if(possible(f * 2) && !visited[f << 1]){
            if((f << 1) == K){
                goTo = true;
                ans = s + 1;
            }
            else            
                bfs.push({(f << 1), s + 1});
        }
    }
    if(goTo)
        ansNum = 1;
    while(!bfs.empty()){
        f = bfs.front().first;
        s = bfs.front().second;
        bfs.pop();
        if(s < ans){
            if((f + 1 == K || !visited[f + 1]) && possible(f + 1)){
                if(f + 1 == K)
                    ++ansNum;
                else            
                    bfs.push({f + 1, s + 1});
            }
            if((f - 1 == K || !visited[f - 1]) && possible(f - 1)){
                if(f - 1 == K)
                    ++ansNum;
                else            
                    bfs.push({f - 1, s + 1});
            }
            if(((f << 1) == K || !visited[f << 1]) && possible(f * 2)){
                if((f << 1) == K)
                    ++ansNum;
                else            
                    bfs.push({(f << 1), s + 1});
            }
        }
    }
}

int main () {
    scanf("%d %d", &N, &K);

    find();

    printf("%d\n%d", ans, ansNum);

    return 0;
}
