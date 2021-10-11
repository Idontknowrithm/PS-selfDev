// 복붙 할 때는 바꿔야 하는 요소 꼼꼼하게 

#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>
#define tup std::pair<int, std::pair<int, int>>
#define uno first
#define dos second.first
#define tres second.second

int N, T, ans, infected[105], possible[105];
std::string input;
std::vector<tup> data;

bool equal(int *a, int *b){
    for(int i = 1; i <= N; ++i)
        if(a[i] != b[i])
            return false;
    return true;
}

int main() {
    std::cin >> N >> T >> input;
    for(int i = 0; i < N; ++i)
        infected[i + 1] = input[i] - '0';
    for(int i = 0; i < T; ++i){
        int t, x, y;
        std::cin >> t >> x >> y;
        data.push_back({t, {x, y}});
    }
    std::sort(data.begin(), data.end());
    int kmin = 10000, kmax = 0;
    for(int in = 1; in <= N; ++in){
        for(int K = 0; K <= 250; ++K){
            int tmp_infec[105] = {0,}, k_left[105] = {0,};
            tmp_infec[in] = 1;
            k_left[in] = K;
            for(int i = 0; i < data.size(); ++i){
                if(tmp_infec[data[i].dos] == 1 && tmp_infec[data[i].tres] == 0 &&
                   k_left[data[i].dos]){
                    --k_left[data[i].dos];
                    tmp_infec[data[i].tres] = 1;
                    k_left[data[i].tres] = K;
                }
                else if(tmp_infec[data[i].dos] == 0 && tmp_infec[data[i].tres] == 1 &&
                        k_left[data[i].tres]){
                    --k_left[data[i].tres];
                    tmp_infec[data[i].dos] = 1;
                    k_left[data[i].dos] = K;
                }
                else if(tmp_infec[data[i].dos] == 1 && tmp_infec[data[i].tres] == 1){
                    k_left[data[i].tres] -= (k_left[data[i].tres]) ? 1 : 0;
                    k_left[data[i].dos] -= (k_left[data[i].dos]) ? 1 : 0;
                }
            }
            if(equal(tmp_infec, infected)){
                possible[in] = 1;
                kmin = std::min(kmin, K);
                kmax = std::max(kmax, K);
            }
        }
    }
    for(int i = 0; i < 105; ++i)
        ans += possible[i];
    std::cout << ans << " ";
    if(kmin >= T)
        std::cout << "Infinity ";
    else 
        std::cout << kmin << " ";
    if(kmax >= T)
        std::cout << "Infinity";
    else 
        std::cout << kmax;
    return 0;
}
