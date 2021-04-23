#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define pp std::pair<double, double>

int N, table[100005];

bool cmp(const int& a, const int& b){
    return abs(a) < abs(b);
}

int main() {
    int ans1, ans2, min = INF;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &table[i]);
    std::sort(table, table + N, cmp);
    for(int i = 1; i < N; ++i){
        if(min > abs(table[i] + table[i - 1])){
            min = abs(table[i] + table[i - 1]);
            ans1 = table[i]; ans2 = table[i - 1];
        }
    }
    if(ans1 > ans2) std::swap(ans1, ans2);
    printf("%d %d", ans1, ans2);
    return 0;
}
