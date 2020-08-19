// pair 사용하면서 메모리 초과 남. pair를 int로 바꾸고 pair로 담던 한 정보를 배열로 담음으로써 해결
// 출발과 도착이 같은 edge case를 간과해서 RTE남. 이에 대한 생각을 해주는 게 좋을 듯

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
        distCache[i] = 100000000;
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
    if(N == K){
        printf("0\n1");
        return 0;
    }
    find();

    printf("%d\n%d", ans, ansNum);

    return 0;
}
