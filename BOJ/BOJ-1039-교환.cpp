// 우와... 어렵다

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define pp std::pair<int, int>

const int MAX = 1000005, digit_10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int N, K, digit, ans = -1;
bool num_cache[MAX], possible_num[MAX];

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
    if(digit_cal(n) != digit || k < 0 || num_cache[n])
        return;
    //printf("%d %d\n", n, k);
    if(!k){
        possible_num[n] = true;
        return;
    }
    for(int i = 0; i < digit - 1; ++i){
        for(int u = i + 1; u < digit; ++u){
            int tmp_n = exchange(n, i, u);
            if(!(k & 1)){
                num_cache[n] = true;
                possible_num[n] = true;
            }
            DFS(tmp_n, k - 1);
            if(!(k & 1))
                num_cache[n] = false;
            // DFS(tmp_n, k - 3);
            // DFS(tmp_n, k - 5);
            // DFS(tmp_n, k - 7);
            // DFS(tmp_n, k - 9);
        }
    }
}
void search(int n, int k){
    std::queue<pp> bfs;
    bfs.push({n, k});
    if(!(k & 1))
        num_cache[n] = true;
    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        if(num_cache[tmp.first]) continue;
        // if(!(tmp.second & 1)){
        //     num_cache[tmp.first] = true;
        // }
        for(int i = 0; i < digit - 1; ++i)
            for(int u = i + 1; u < digit; ++u){
                int t = exchange(tmp.first, i, u);
                if(!num_cache[t])
                    bfs.push({t, k - 1});
                if(!(k & 1))
                    num_cache[t] = true;
            }
    }
}
int solve(){
    int ans = 0;
    for(int i = MAX - 5; i >= 0; --i)
        if(num_cache[i]){
            ans = i;
            break;
        }
    
    return (digit_cal(ans) == digit_cal(N)) ? ans : -1;
}

int main() {
    scanf("%d %d", &N, &K);
    digit = digit_cal(N);
    if(N / 10 == 0 || (N < 100 && N % 10 == 0)){
        printf("-1");
        return 0;
    }
    //caching(N);
    // DFS(N, K);
    search(N, K);
    printf("%d", solve());
    return 0;
}
