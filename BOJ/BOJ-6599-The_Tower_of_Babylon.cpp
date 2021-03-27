#include<iostream>
#include<algorithm>
#include<vector>

typedef struct{
    int x, y, z;
}block;

int N, cache[100];
std::vector<block> babylon;

bool cmp(const block &a, const block &b){
    return (a.x == b.x) ? a.y > b.y : a.x > b.x;
}
int DP(int start){
    if(start == babylon.size() - 1) return babylon[babylon.size() - 1].z;
    
    int &ret = cache[start];
    if(ret) return ret;

    ret = 0;

    for(int i = start + 1; i < babylon.size(); ++i){
        if(start == -1)
            ret = std::max(ret, DP(i));
        else if(babylon[start].x > babylon[i].x && babylon[start].y > babylon[i].y)
            ret = std::max(ret, DP(i) + babylon[start].z);
    }
    return ret;
}

int main() {
    int a, b, c, rotate = 1;
    while(1){
        babylon.clear();
        for(int i = 0; i < 100; ++i) cache[i] = 0;
        
        scanf("%d", &N);
        if(!N) return 0;
        
        for(int i = 0; i < N; ++i){
            scanf("%d %d %d", &a, &b, &c);
            if(a < b) babylon.push_back({a, b, c});
            else      babylon.push_back({b, a, c});
            if(b < c) babylon.push_back({b, c, a});
            else      babylon.push_back({c, b, a});
            if(a < c) babylon.push_back({a, c, b});
            else      babylon.push_back({c, a, b});
        }
        std::sort(babylon.begin(), babylon.end(), cmp);
        puts("arr start");
        for(int i = 0; i < babylon.size(); ++i)
            printf("%d %d %d\n", babylon[i].x, babylon[i].y, babylon[i].z);
        puts("");
        printf("Case %d: maximum height = %d\n", rotate++, DP(-1));
        for(int i = 0; i < 10; ++i) printf("%d ", cache[i]);
        puts("");
    }
    return 0;
}
