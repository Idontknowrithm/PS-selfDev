// DP가 아니고 쌩 이분탐색이다...

#include<iostream>
#include<algorithm>

const int MAX = 305, INF = 30000;
int N, M, marbles[MAX], division[MAX];

void bi_search(){
    bool big_one;
    int mid, tmp_ans = INF, start = 1, end = INF;

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
            if(groups == M)
                tmp_ans = std::min(tmp_ans, mid);
            end = mid - 1;
        }
    }
    int div_size = 0, tmp = 0, ans = 0;
    for(int i = 0; i < N; ++i){
        if(tmp + marbles[i] > tmp_ans){
            if(!tmp){
                ++division[div_size++];
                ans = std::max(ans, marbles[i]);
                tmp = 0;
            }
            else{
                division[++div_size] = 1;
                ans = std::max(ans, tmp);
                tmp = marbles[i];
            }
        }
        else{
            tmp += marbles[i];
            ++division[div_size];
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i <= div_size; ++i)
        printf("%d ", division[i]);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", &marbles[i]);
    }
    bi_search();
    return 0;
}
