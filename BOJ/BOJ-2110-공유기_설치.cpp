// 이분탐색 시 과정을 이분탐색하는 것보다 답에 대해서 이분탐색하는
// 문제가 생각보다 많음

#include<iostream>
#include<vector>
#include<algorithm>

int N, C;
std::vector<int> houses;

// binary search
int BS(){
    int start = 1, end = houses[houses.size() - 1] - houses[0];

    while(start <= end){
        int tmpC = 1, mid = (start + end) / 2;
        int cur = houses[0];
        for(int i = 1; i < houses.size(); ++i){
            if(houses[i] - cur >= mid){
                ++tmpC;
                cur = houses[i];
            }
        }
        if(tmpC >= C)
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return end;
}

int main() {
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; ++i){
        int tmp;
        scanf("%d", &tmp);
        houses.push_back(tmp);
    }
    std::sort(houses.begin(), houses.end());
    printf("%d", BS());
    return 0;
}
