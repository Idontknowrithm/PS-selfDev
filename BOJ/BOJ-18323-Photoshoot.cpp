// 예외 케이스 잘 확인하자

#include<iostream>
#include<vector>
#include<algorithm>

const int MAX = 50005;
int N, B[MAX];
std::vector<int> tmp, ans;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i)
        scanf("%d", &B[i]);
    for(int i = 1; i < B[0]; ++i){
        bool exist[MAX] = {false,};
        exist[i] = true;
        int division = i;
        tmp.push_back(i);
        bool neg = false;
        for(int u = 0; u < N - 1; ++u){
            division = B[u] - division;
            if(division <= 0){
                neg = true;
                break;
            }
            exist[division] = true;
            tmp.push_back(division);
        }
        if(neg){
            tmp.clear();
            continue;
        }
        int all = 0;
        for(int u = 1; u <= N; ++u)
            all += (exist[u]) ? 1 : 0;
        if(all == N){
            for(int u = 0; u < tmp.size(); ++u)
                printf("%d ", tmp[u]);
            return 0;
        }
        tmp.clear();
    }
    return 0;
}
