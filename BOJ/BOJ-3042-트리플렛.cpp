// 직사각형 판에 직선들을 완탐할 때에는
// 같은 직선 위의 점들은 서로의 기울기가 같다는
// 개념을 이용하는게 가장 나에게 쉬운 것 같음

#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int N, ans;
std::vector<pp> point_arr;
std::string arr[105];

bool straight(pp a, pp b, pp c){
    double ab, bc;
    ab = (double)(a.first - b.first) / (a.second - b.second);
    bc = (double)(b.first - c.first) / (b.second - c.second);
    return (ab == bc);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    for(int i = 0; i < N; ++i)
        std::cin >> arr[i];
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        if(arr[i][u] != '.')
            point_arr.push_back({i, u});
    
    for(int i = 0; i < point_arr.size(); ++i)
    for(int u = i + 1; u < point_arr.size(); ++u)
    for(int k = u + 1; k < point_arr.size(); ++k){
        ans += (straight(point_arr[i], point_arr[u], point_arr[k])) ? 1 : 0;
    }
    std::cout << ans;
    return 0;
}
