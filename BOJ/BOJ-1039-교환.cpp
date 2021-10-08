중복이 생기는 것을 지우는 게 관건이었는데, 무엇을 지워야 하는 지를 잘못 찾았음
내가 생각했던 지워야하는 중복: 132 -> 123 -> 132 같이 한 번 건너서 같은 숫자가 나오므로
하나 건너서 중복을 지워야 함
지워야하는 중복의 정답: 같은 단계(같은 k)에서 중복을 지움
123을 예로 들자면, 물론 세 번째에서 123이 나오는 중복도 있지만, 두 번째에서 세 번째로 갈 때
많은 123이 나옴, 즉(123이 k=1이라 치면) 같은 k = 3 단계에서 123이 여러개 나옴
-> 그러면 k = 4에서 같은 123에 대해 여러번 탐색을 하게 될 것이고, 그러면 제대로 의미없는 탐색을 할 것
따라서 같은 단계의 중복을 지워줘야 한다

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 1000005, digit_10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int N, K, digit, ans = -1;
bool num_cache[MAX];

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
int solve(int n, int k){
    std::queue<pp> bfs;
    bfs.push({n, k});

    for(int l = 0; l < k; ++l){
        int qsize = bfs.size();
        memset(num_cache, false, sizeof(num_cache));
        for(int j = 0; j < qsize; ++j){
            pp tmp = bfs.front();
            bfs.pop();
            if(num_cache[tmp.first])
                continue;
            num_cache[tmp.first] = true;
            for(int i = 0; i < digit - 1; ++i)
                for(int u = i + 1; u < digit; ++u){
                    int t = exchange(tmp.first, i, u);
                    bfs.push({t, k - 1});
                }
        }
    }
    int ans = 0;
    while(!bfs.empty()){
        ans = std::max(ans, bfs.front().first);
        bfs.pop();
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
    
    printf("%d", solve(N, K));
    return 0;
}
