#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

int F, S, G, U, D, building[1000005];

void BFS(){
    std::queue<int> que;

    building[S] = 0;
    que.push(S);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        int next = cur + U;
        if(next <= F && building[next] > building[cur] + 1){
            que.push(next);
            building[next] = building[cur] + 1;
        }
        next = cur - D;
        if(next >= 1 && building[next] > building[cur] + 1){
            que.push(next);
            building[next] = building[cur] + 1;
        }
    }
}

int main() {
    memset(building, 1, sizeof(building));
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    BFS();

    if(building[G] == building[0])
        printf("use the stairs");
    else 
        printf("%d", building[G]);
    return 0;
}
