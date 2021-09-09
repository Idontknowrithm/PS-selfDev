// DP가 아니고 쌩 이분탐색이다...

#include<iostream>
#include<vector>

const int MAX = 305;
int N, M, marbles[MAX];

void solve(){
    int start = 0, end = 30000, mid;
    std::vector<int> group, count;

    while(start <= end){
        mid = (start + end) / 2;
        group.clear();
        count.clear();
        group.push_back(0);
        count.push_back(0);
        int size = 0;
        for(int i = 0; i < N; ++i){
            if(group[size] + marbles[i] > mid){
                if(!group[size]){
                    group[size] += marbles[i];
                    count[size] += 1;
                }
                else{
                    ++size;
                    group.push_back(0);
                    group[size] += marbles[i];
                    count.push_back(1);
                }
            }
            else{
                group[size] += marbles[i];
                count[size] += 1;
            }
        }
        // if(size + 1 == M){
        //     int max = 0;
        //     for(int i = 0; i < size + 1; ++i)
        //         max = std::max(max, group[i]);
        //     printf("%d\n", max);
        //     for(int i = 0; i < count.size(); ++i)
        //         printf("%d ", count[i]);
        //     return;
        // }
        if(size + 1 <= M)
            end = mid - 1;
        else
            start = mid + 1;
    }
    int max = 0;
    for(int i = 0; i < group.size(); ++i)
        max = std::max(max, group[i]);
    printf("%d\n", max);
    for(int i = 0; i < count.size(); ++i)
        printf("%d ", count[i]);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", &marbles[i]);
    }
    solve();
    return 0;
}
