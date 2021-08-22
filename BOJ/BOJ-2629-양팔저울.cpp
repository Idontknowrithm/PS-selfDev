// 최대, 최소값을 찾는 DP가 아닌 답의 존재 여부를 캐싱하는 DP
// 문제의 목적: 주어진 추만을 사용하여 구슬의 무게를 확인 할 수 있는지를 결정하는 프로그램을 작성
// --> 특정 무게를 만들 수 있는지 여부를 묻는 것. 어떤 값의 최대 최소를 묻지는 않는다
// 여기서 파악해야했던 점은 최대 최소값이 아닌 가능 여부에 대한 DP 캐시를 만들어야함
// 캐시 요소를 정하는 과정에서는
// 먼저 어떤 추를 사용해야할 지에 대한 요소가 있어야할 것이고,
// 추의 무게에 대한 요소가 있어야할 것 같은데 이를 어떻게 조합하여
// 메모리 초과가 나지 않게끔 캐시를 구성할 것인지에 대해 생각한다면,
// 일단 추가 30개 이하, 한 추의 무게가 500 이하 -> 총 무게는 15000 이하
// 이를 캐시의 요소로 사용해야할 텐데 나는 처음에 무게의 차로 
// (오른쪽 저울) - (왼쪽 저울)에 대한 정보를 담기위해 15000 + diff를 담기위해
// cache[30][30000]을 만들었는데, 다른 블로그를 참고하여
// abs((오른쪽 저울) - (왼쪽 저울))을 이용해 cache[30][15000]으로 
// 캐시를 디자인할 수 있었음
// 캐시를 이렇게 만든다면 어떤 idx 까지의 추를 이용하여 diff 만큼의 무게 차를
// 만들 수 있는지에 대한 DP 함수를 만들 수 있음
// DP 함수 안에서는 다음 추를 왼쪽에 추가할 지, 오른 쪽에 추가할 지,
// 아예 빼버릴 지에 대해서 탐색할 수 있도록 구현해야함

#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>

int N, M, marble, weights[35];
bool cache[35][15005];

void DP(int idx, int diff){
    if(cache[idx][diff]) return;
    cache[idx][diff] = true;
    if(idx == N) return;
    DP(idx + 1, diff);
    DP(idx + 1, diff + weights[idx]);
    DP(idx + 1, std::abs(diff - weights[idx]));
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &weights[i]);
    scanf("%d", &M);
    for(int z = 0; z < M; ++z){
        scanf("%d", &marble);
        if(marble > 15000){
            printf("N ");
            continue;
        }
        memset(cache, 0, sizeof(cache));
        DP(0, 0);
        bool ans = false;
        for(int i = 0; i < 35; ++i)
            ans = (cache[i][marble]) ? true : ans;
        printf("%s ", (ans) ? "Y" : "N");
    }
    return 0;    
}
