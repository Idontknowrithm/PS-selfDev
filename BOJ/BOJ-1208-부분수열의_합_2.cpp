#include<iostream>
#include<vector>
#include<algorithm>

int N, S, ans, seq1_size, seq2_size, seq1[45], seq2[45];
std::vector<int> sum1, sum2;

bool cmp(const int &a, const int &b){
    return a > b;
}
void make_sum1(int idx, int prev_sum){
    if(idx == seq1_size){
        sum1.push_back(prev_sum);
        return;
    }
    make_sum1(idx + 1, prev_sum);
    make_sum1(idx + 1, prev_sum + seq1[idx]);
}
void make_sum2(int idx, int prev_sum){
    if(idx == seq2_size){
        sum2.push_back(prev_sum);
        return;
    }
    make_sum2(idx + 1, prev_sum);
    make_sum2(idx + 1, prev_sum + seq2[idx]);
}

int main() {
    scanf("%d %d", &N, &S);
    if(N & 1)
        for(int i = 0; i < N; ++i)
            if(i <= N / 2)
                scanf("%d", &seq1[i]);
            else 
                scanf("%d", &seq2[i - N / 2 - 1]);
    else
        for(int i = 0; i < N; ++i)
            if(i < N / 2)
                scanf("%d", &seq1[i]);
            else 
                scanf("%d", &seq2[i - N / 2]);
    seq1_size = N / 2;
    seq2_size = N / 2;
    (N % 2 == 1) ? (++seq1_size) : 0;
    make_sum1(0, 0);
    make_sum2(0, 0);
    std::sort(sum1.begin(), sum1.end());
    std::sort(sum2.begin(), sum2.end(), cmp);

    int ptr1 = 0, ptr2 = 0;
    while(ptr1 != sum1.size() && ptr2 != sum2.size()){
        int count1 = 0, count2 = 0;
        while(ptr1 != sum1.size() - 1 && sum1[ptr1] + sum2[ptr2] == S && sum1[ptr1] == sum1[ptr1 + 1]){
            ++count1;
            ++ptr1;
        }
        if(count1) --ptr1;
        while(ptr2 != sum2.size() - 1 && sum1[ptr1] + sum2[ptr2] == S && sum2[ptr2] == sum2[ptr2 + 1]){
            ++count2;
            ++ptr2;
        }
        if(count2) --ptr2;
        ans += count1 * count2;
        if(sum1[ptr1] + sum2[ptr2] < S) ++ptr1;
        else                            ++ptr2;
    }
    if(S == 0) --ans;
    printf("%d", ans);
    return 0;
}
