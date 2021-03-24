#include<iostream>
#include<algorithm>

int H, W, tile[505][505];

int DP(){
    int max = 0;
    if(H == 1){
        for(int i = 0; i < W; ++i)
            max = std::max(max, tile[0][i]);
        return max;
    }
    for(int i = 1; i < H; ++i){
        if(W == 1){
            tile[i][0] += tile[i - 1][0];
        }
        else{
            tile[i][0] += std::max(tile[i - 1][0], tile[i - 1][1]);
            for(int u = 1; u < W - 1; ++u)
                tile[i][u] += std::max(std::max(tile[i - 1][u - 1], tile[i - 1][u]), tile[i - 1][u + 1]);
            tile[i][W - 1] += std::max(tile[i - 1][W - 1], tile[i - 1][W - 2]);
        }
    }
    for(int i = 0; i < W; ++i)
        max = std::max(max, tile[H - 1][i]);
    return max;
}

int main(){
    scanf("%d %d", &H, &W);
    for(int i = 0; i < H; ++i)
    for(int u = 0; u < W; ++u)
        scanf("%d", &tile[i][u]);
    printf("%d", DP());

    return 0;
}
