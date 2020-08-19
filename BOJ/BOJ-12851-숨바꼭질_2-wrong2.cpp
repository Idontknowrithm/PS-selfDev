// runtime error

#include<iostream>
#include<algorithm>
#include<queue>

int N, K, ans, ansNum, distCache[200005];

bool possible(int a){
    return (a >= 0 && a < 100001);
}
void find(){
    int f; bool goTo = false;
    std::queue<int> bfs;
    for(int i = 0; i < 200005; ++i)
        distCache[i] = 10000000;
    bfs.push(N); distCache[N] = 0;
    while(!goTo){
        f = bfs.front();
        bfs.pop();

        if(possible(f + 1) && distCache[f + 1] > distCache[f]){
            if(f + 1 == K){
                goTo = true;
                ans = distCache[f] + 1;
            }
            else{
                bfs.push(f + 1);
                distCache[f + 1] = distCache[f] + 1;
            }
        }
        if(possible(f - 1) && distCache[f - 1] > distCache[f]){
            if(f - 1 == K){
                goTo = true;
                ans = distCache[f] + 1;
            }
            else{
                bfs.push(f - 1);
                distCache[f - 1] = distCache[f] + 1;
            }
        }
        if(possible(f << 1) && distCache[f << 1] > distCache[f]){
            if((f << 1) == K){
                goTo = true;
                ans = distCache[f] + 1;
            }
            else{
                bfs.push(f << 1);
                distCache[f << 1] = distCache[f] + 1;
            }
        }
    }
    if(goTo)
        ansNum = 1;
    while(!bfs.empty()){
        f = bfs.front();
        bfs.pop();
        if(distCache[f] < ans){
            if(possible(f + 1) && (f + 1 == K || distCache[f + 1] > distCache[f])){
                if(f + 1 == K)
                    ++ansNum;
                else{
                    bfs.push(f + 1);
                    distCache[f + 1] = distCache[f] + 1;
                }
            }
            if(possible(f - 1) && (f - 1 == K || distCache[f - 1] > distCache[f])){
                if(f - 1 == K)
                    ++ansNum;
                else{
                    bfs.push(f - 1);
                    distCache[f - 1] = distCache[f] + 1;
                }
            }
            if(possible(f << 1) && ((f << 1) == K || distCache[f << 1] > distCache[f])){
                if((f << 1) == K)
                    ++ansNum;
                else{
                    bfs.push(f << 1);
                    distCache[f << 1] = distCache[f] + 1;
                }
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
