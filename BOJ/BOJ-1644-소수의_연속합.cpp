#include<iostream>
#include<vector>

const int MAX = 4000005;
int N, tmp_sum, right, left, ans, prime_sieve[MAX];
std::vector<int> prime;

int main() {
    for(int i = 2; i < MAX / 2; ++i){
        for(int u = i; u < MAX; u += i)
            if(u != i) prime_sieve[u] = -1;
    }
    for(int i = 2; i < MAX; ++i)
        if(!prime_sieve[i])
            prime.push_back(i);
    
    scanf("%d", &N);

    while(right != prime.size()){
        if(tmp_sum <= N)
            tmp_sum += prime[right++];
        else 
            tmp_sum -= prime[left++];
        if(tmp_sum == N)
            ++ans;
    }
    printf("%d", ans);
    return 0;
}
