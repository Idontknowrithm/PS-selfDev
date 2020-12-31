// 이번에도 또 문제 조건 안읽음 - 메모리 제한 조건

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

int N, arr[3], maxi[2][3], mini[2][3];

int main(){
    int max = -1, min = 10000000;

    scanf("%d", &N);
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    if(N == 1){
        printf("%d %d", std::max(std::max(arr[0], arr[1]), arr[2]), 
                        std::min(std::min(arr[0], arr[1]), arr[2]));
        return 0;
    }
    maxi[1][0] = mini[1][0] = arr[0];
    maxi[1][1] = mini[1][1] = arr[1];
    maxi[1][2] = mini[1][2] = arr[2];
    for(int i = 1; i < N; ++i){
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        maxi[0][0] = std::max(maxi[1][0], maxi[1][1]) + arr[0];
        maxi[0][1] = std::max(std::max(maxi[1][0], maxi[1][1]), maxi[1][2]) + arr[1];
        maxi[0][2] = std::max(maxi[1][1], maxi[1][2]) + arr[2];
        mini[0][0] = std::min(mini[1][0], mini[1][1]) + arr[0];
        mini[0][1] = std::min(std::min(mini[1][0], mini[1][1]), mini[1][2]) + arr[1];
        mini[0][2] = std::min(mini[1][1], mini[1][2]) + arr[2];

        maxi[1][0] = maxi[0][0];
        maxi[1][1] = maxi[0][1];
        maxi[1][2] = maxi[0][2];
        mini[1][0] = mini[0][0];
        mini[1][1] = mini[0][1];
        mini[1][2] = mini[0][2];
    }
    printf("%d %d", std::max(std::max(maxi[1][0], maxi[1][1]), maxi[1][2]),
                    std::min(std::min(mini[1][0], mini[1][1]), mini[1][2]));    
    return 0;
}
