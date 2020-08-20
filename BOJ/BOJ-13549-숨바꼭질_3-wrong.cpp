// normal wrong

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
    bool goTo = false;
    for(int i = 0; i < 200005; ++i)
        dcache[i] = 100000000;
    bfs.push(N);
    dcache[N] = 0;

    while(!bfs.empty() && !goTo){
        f = bfs.front();
        
        bfs.pop();
        if(possible(f << 1) && dcache[f << 1] > dcache[f]){
            if((f << 1) == K){
                return dcache[f];
            }
            else{
                bfs.push(f << 1);
                dcache[f << 1] = dcache[f];
            }
        }
        if(possible(f + 1) && dcache[f + 1] > dcache[f]){
            if(f + 1 == K){
                return dcache[f] + 1;
            }
            else{
                bfs.push(f + 1);
                dcache[f + 1] = dcache[f] + 1;
            }
        }
        if(possible(f - 1) && dcache[f - 1] > dcache[f]){
            if(f - 1 == K){
                return dcache[f] + 1;
            }
            else{
                bfs.push(f - 1);
                dcache[f - 1] = dcache[f] + 1;
            }
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
