// 각 알파벳의 가중치를 구하고, 가중치에 따라서 9부터 0까지 그리디하게 분배한 후,
// 0이 분배된 알파벳이 맨 앞에 출현해 0이 될 수 없다면, 0이 될 수 있는 알파벳 중
// 가중치가 가장 작은 것과 바꾸는 알고리즘을 갔는데 바꾸는 알고리즘에서 복잡한 부분이 있어
// WA 뜸. 따라서 10가지의 알파벳이 모두 사용되어 0이 꼭 들어갈 경우, 가중치가 적은 것부터
// 0이 될 수 있는 알파벳을 찾아 0을 먼저 할당한 뒤, 나머지 숫자를 할당하는 알고리즘으로 피벗

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long

const ll MAX = 55, INF = 90000000000000;
ll N, num_hash_table[15], weight[15], cant_zero[15];
std::vector<ll> aton[MAX];

int main() {
    std::string input;

    std::cin >> N;
    for(ll i = 0; i < N; ++i){
        std::cin >> input;
        for(ll u = 0; u < input.size(); ++u){
            ll tmp;
            tmp = input[u] - 'A';
            aton[i].push_back(tmp);
            if(!u) cant_zero[tmp] = 1;
        }
        ll dec = 1;
        for(ll u = 0; u < aton[i].size(); ++u){
            weight[aton[i][aton[i].size() - u - 1]] += dec;
            dec *= 10;
        }
    }
    ll num = 9, tmp_weight[15];
    for(ll i = 0; i < 10; ++i)
        tmp_weight[i] = weight[i];

    ll idx, max, min, digits = 0;
    for(ll i = 0; i < 10; ++i)
        digits += (weight[i]) ? 1 : 0;

    memset(num_hash_table, -1, sizeof(num_hash_table));
    if(digits == 10)
        for(ll i = 0; i < 10; ++i){
            idx = 10; min = INF;
            for(ll u = 0; u < 10; ++u){
                if(tmp_weight[u] && min > tmp_weight[u]){
                    min = tmp_weight[u];
                    idx = u;
                }
            }
            if(!cant_zero[idx]){
                num_hash_table[idx] = 0;
                break;
            }
            else 
                tmp_weight[idx] = 0;
        }

    for(ll i = 0; i < 10; ++i)
        tmp_weight[i] = weight[i];
    for(ll i = 0; i < 10; ++i){
        idx = 10; max = 0;
        for(ll u = 0; u < 10; ++u){
            if(max < tmp_weight[u]){
                max = tmp_weight[u];
                idx = u;
            }
        }
        tmp_weight[idx] = 0;
        if(num_hash_table[idx] != 0){
            num_hash_table[idx] = num; --num;
        }
    }
   
    ll ans = 0;
    for(ll i = 0; i < 10; ++i)
        ans += weight[i] * num_hash_table[i];
    std::cout << ans << std::endl;
    return 0;
}
