#include<iostream>
#include<algorithm>
#include<vector>

const int MAX = 1000005, digit_10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int N, K, digit, ans = -1;
bool num_cache[MAX];

void caching(int n){
    std::vector<int> num;
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    std::sort(num.begin(), num.end());
    do{
        int tmp = 0;
        for(int i = 0; i < num.size(); ++i){
            tmp *= 10;
            tmp += num[i];
        }
        num_cache[tmp] = true;
    }while(std::next_permutation(num.begin(), num.end()));
}
int digit_cal(int n){
    int d = 0;
    while(n){
        ++d;
        n /= 10;
    }
    return d;
}
int exchange(int n, int i, int u){
    int i_digit = digit_10[i], u_digit = digit_10[u];
    int i_num = (n / i_digit) % 10, u_num = (n / u_digit) % 10;
    n -= i_num * i_digit + u_num * u_digit;
    n += i_num * u_digit + u_num * i_digit;
    return n;
}
void DFS(int n, int k){
    if(digit_cal(n) != digit || k < 0)
            return;
    if(!k){
        ans = std::max(ans, n);
        return;
    }
    for(int i = 0; i < digit - 1; ++i){
        for(int u = i + 1; u < digit; ++u){
            int tmp_n = exchange(n, i, u);
            DFS(tmp_n, k - 1);
            DFS(tmp_n, k - 3);
            DFS(tmp_n, k - 5);
            DFS(tmp_n, k - 7);
            DFS(tmp_n, k - 9);
        }
    }
}
void solve(){
    
}

int main() {
    scanf("%d %d", &N, &K);
    digit = digit_cal(N);
    caching(N);
    DFS(N, K);
    printf("%d", ans);
    return 0;
}
