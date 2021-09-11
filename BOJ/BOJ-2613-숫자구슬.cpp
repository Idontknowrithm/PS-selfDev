// DP가 아니고 쌩 이분탐색이다...

#include<iostream>
#include<algorithm>

const int MAX = 305, INF = 30000;
int N, M, marbles[MAX], division[MAX];

void bi_search(){
    bool big_one;
    int mid, ans = INF, start = 1, end = INF;

    while(start <= end){
        big_one = false;
        mid = (start + end) / 2;
        int tmp_sum = 0, groups = 1;
        for(int i = 0; i < N; ++i){
            if(marbles[i] > mid){
                start = mid + 1;
                big_one = true;
                break;
            }
            if(tmp_sum + marbles[i] > mid){
                if(!tmp_sum){
                    ++groups;
                    tmp_sum = 0;
                }
                else{
                    ++groups;
                    tmp_sum = marbles[i];
                }
            }
            else{
                tmp_sum += marbles[i];
            }
        }
        if(groups > M || big_one){
            start = mid + 1;
        }   
        else{
            ans = std::min(ans, mid);
            end = mid - 1;
        }
    }
    int div_size = 0, tmp = 0;
    for(int i = 0; i < N; ++i){
        if(marbles[i] + tmp > ans){
            tmp = marbles[i];
            division[++div_size] = 1;
        }
        else{
            tmp += marbles[i];
            ++division[div_size];
        }
    }
    printf("%d\n", ans);
    int idle = M - div_size - 1;
    for(int i = 0; i <= div_size; ++i){
        if(division[i] == 1)
            printf("%d ", division[i]);
        else{
            while(idle >= 1 && division[i] >= 2){
                printf("1 ");
                --division[i]; --idle;
            }
            printf("%d ", division[i]);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", &marbles[i]);
    }
    bi_search();
    return 0;
}
