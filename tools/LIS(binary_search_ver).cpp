// O(nlogn)

#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<unit, unit>
typedef int unit;

const unit MAX = 1000005, INF = 1000000005;
int N, prev_idx[MAX];
unit val[MAX];
std::vector<unit> value_seq, idx_seq, ans;

void LIS(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &val[i]);
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
    ans.push_back(val[tmp]);
    tmp = prev_idx[tmp];
    while(tmp != -1){
        ans.push_back(val[tmp]);
        tmp = prev_idx[tmp];
    }
    // LIS 길이 : value_seq.size() - 1
    // LIS 원소 : ans 반대 방향(인덱스 ans.size() - 1 부터)
}
