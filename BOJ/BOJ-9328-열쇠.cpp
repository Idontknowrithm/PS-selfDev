#include<iostream>
#include<queue>
#include<algorithm>

int T, N, M, door[30], key[30];
std::string building[105], key_input;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(std::cin >> T; T > 0; --T){
        std::cin >> N >> M;
        for(int i = 0; i < N; ++i)
            std::cin >> building[i];
        std::cin >> key_input;
    }
}
// 한번 돌고 갈 수 있는 문 수집하고
// 문 중에서 딸 수 있는 게 있으면 따고 다음번 돌고
// 문 중에서 딸 수 있는 게 없으면 종료
