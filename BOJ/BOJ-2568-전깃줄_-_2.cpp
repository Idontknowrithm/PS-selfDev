// 문제 아이디어를 떠올리기 상당히 어려웠음
// 전깃줄 끊는 문제에 최장 증가 부분 수열이..?
// 전깃줄을 교차하게 하면 안되는데, 전깃줄이 교차한다는 것은
// 전깃줄 시작 기준으로 끝 부분의 인덱스 순서가 바뀌면 안됨
// 전깃줄 시작 부분과 끝 부분 모두 인덱스가 오름차순 정렬 되어있어야 하니까,
// 그 오름차순의 길이가 가장 긴 것, 즉 최장 증가 부분 수열을 찾기
// 문제 아이디어 상당히 지능적이네 멋진 

#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<unit, unit>
typedef int unit;

const unit MAX = 1000005, INF = 1000000005;
int N, prev_idx[MAX], ans[500005];
std::vector<unit> val, value_seq, idx_seq, lis_ans, B_search;
std::vector<pp> input;

void LIS(){
    value_seq.push_back(-INF);
    idx_seq.push_back(-1);

    for(int i = 0; i < N; ++i){
        if(val[i] > value_seq[value_seq.size() - 1]){
            prev_idx[i] = idx_seq[idx_seq.size() - 1];
            value_seq.push_back(val[i]);
            idx_seq.push_back(i);
        }
        else{
            std::vector<unit>::iterator it;
            it = std::lower_bound(value_seq.begin(), value_seq.end(), val[i]);
            *it = val[i];
            it = it - value_seq.begin() + idx_seq.begin();
            *it = i;
            prev_idx[i] = *(--it);
        }
    }
    
    int tmp = idx_seq[idx_seq.size() - 1];
    lis_ans.push_back(val[tmp]);
    tmp = prev_idx[tmp];
    while(tmp != -1){
        lis_ans.push_back(val[tmp]);
        tmp = prev_idx[tmp];
    }
    // LIS 길이 : value_seq.size() - 1
    // LIS 원소 : lis_ans 반대 방향(인덱스 lis_ans.size() - 1 부터)
}

int main() {
    int a, b;
    scanf("%d", &N);
    B_search.resize(500005, -1);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &a, &b);
        input.push_back({a, b});
        B_search[b] = a;
        ans[a] = 1;
    }
    std::sort(input.begin(), input.end());
    for(int i = 0; i < N; ++i)
        val.push_back(input[i].second);
    LIS();
    printf("%d\n", N - value_seq.size() + 1);
    for(int i = lis_ans.size() - 1; i >= 0; --i){
        ans[B_search[lis_ans[i]]] = 0;
    }
    for(int i = 0; i < 500005; ++i)
        if(ans[i])
            printf("%d\n", i);
    return 0;
}
