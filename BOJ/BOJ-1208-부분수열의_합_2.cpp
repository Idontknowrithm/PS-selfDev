// 입력의 범위가 다 int라도 출력의 범위가 long long일 수 있음..

#include<iostream>
#include<vector>
#include<algorithm>

long long N, S, seq1_size, seq2_size, input[45], seq1[45], seq2[45];
long long ans;
std::vector<long long> sum1, sum2;

bool cmp(const long long &a, const long long &b){
    return a > b;
}
void make_sum1(long long idx, long long prev_sum){
    if(idx == seq1_size){
        sum1.push_back(prev_sum);
        return;
    }
    make_sum1(idx + 1, prev_sum);
    make_sum1(idx + 1, prev_sum + seq1[idx]);
}
void make_sum2(long long idx, long long prev_sum){
    if(idx == seq2_size){
        sum2.push_back(prev_sum);
        return;
    }
    make_sum2(idx + 1, prev_sum);
    make_sum2(idx + 1, prev_sum + seq2[idx]);
}

int main() {
    scanf("%lld %lld", &N, &S);
    for(long long i = 0; i < N; ++i)
        scanf("%lld", &input[i]);
    for(long long i = 0; i < N / 2; ++i)
        seq1[i] = input[i];
    for(long long i = 0; i < N - N / 2; ++i)
        seq2[i] = input[i + N / 2];
    seq1_size = N / 2;
    seq2_size = N - N / 2;

    make_sum1(0, 0);
    make_sum2(0, 0);
    std::sort(sum1.begin(), sum1.end());
    std::sort(sum2.begin(), sum2.end(), cmp);
    
    long long ptr1 = 0, ptr2 = 0;
    while(ptr1 != sum1.size() && ptr2 != sum2.size()){
        long long count1 = 1, count2 = 1;
        if(sum1[ptr1] + sum2[ptr2] == S){
            while(ptr1 != sum1.size() - 1 && sum1[ptr1] == sum1[ptr1 + 1]){
                ++count1;
                ++ptr1;
            }
            while(ptr2 != sum2.size() - 1 && sum2[ptr2] == sum2[ptr2 + 1]){
                ++count2;
                ++ptr2;
            }
            ans += count1 * count2;
            ++ptr1; ++ptr2;
        }
        else if(sum1[ptr1] + sum2[ptr2] < S) ++ptr1;
        else                                 ++ptr2;
    }
    if(S == 0) --ans;
    printf("%lld", ans);
    return 0;
}
