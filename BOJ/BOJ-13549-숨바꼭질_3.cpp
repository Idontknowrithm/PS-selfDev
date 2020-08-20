// 쓸데없이 어렵게 생각한 부분이 있었고, 이건 피할 수 없었음
// 2배 뛰는 건 0초만에 하니까, BFS로 한다고 해도 거리가 순서대로 되지 않을 수 있다는 생각은 합리적이었음
// critical point는 왜 if문 마다에서 리턴을 했을 때는 안되는가... 인데
// 어차피 나중에 push로 들어갈 수 있을거면 if문으로 엮어낼 수 있을거라 생각했음
// 도대체 모르겠네... 나중에 꼭 다시 확인

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

int N, K, dcache[200005];

int possible(int a){
    return (a >= 0 && a <= 100000);
}

int find(){
    std::queue<int> bfs;
    int ans, f;
    for(int i = 0; i < 200005; ++i)
        dcache[i] = 100000000;
    bfs.push(N);
    dcache[N] = 0;

    while(!bfs.empty()){
        f = bfs.front();
        bfs.pop();
        if(f == K)
            return dcache[f];
        if(possible(f << 1) && dcache[f << 1] > dcache[f]){
            bfs.push(f << 1);
            dcache[f << 1] = dcache[f];
        }
        if(possible(f + 1) && dcache[f + 1] > dcache[f] + 1){
            bfs.push(f + 1);
            dcache[f + 1] = dcache[f] + 1;
        }
        if(possible(f - 1) && dcache[f - 1] > dcache[f] + 1){
            bfs.push(f - 1);
            dcache[f - 1] = dcache[f] + 1;
        }
    }
}

int main () {
    scanf("%d %d", &N, &K);

    if(N == K){
        printf("0");
        return 0;
    }

    printf("%d", find());

    return 0;
}
