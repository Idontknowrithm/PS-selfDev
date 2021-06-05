// 전체적인 알고리즘이 한 배열을 이용하여 LIS를 쌓아가면서,
// 중간부터 시작되는 가능한 예비 LIS를 그 배열에 기록해두면서 메모이제이션 하는 것
// 예를 들어서 배열에 1, 2, 4, 6 정도로 쌓아가면서, 중간에 3이 튀어나왔다, 그러면 
// 이 3이 LIS를 만들 수 있는 가능성이 있는 곳에 넣어주면서 일고리즘 진행(1, 2, 3, 6)
// 1, 2, 4, 6에서 1, 2, 3, 6으로 바꿀 때, 3은 6이 들어가는 LIS에 영향을 주지 않음
// 따라서 6의 관점에서는 3을 고려할 필요가 없음. 3이 들어왔다고 6의 관점에서 어떤 값을 바꿀 필요가 없다는 말
// ex) 3이 바뀌었다고 해서 6의 prev_idx를 바꿀 필요가 없음 애초에 관련 없으니까
// 그러니 각 원소를 추가할 때, 그 원소의 전 원소가 뭔 지만 그때마다 메모이제이션 해주는 
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#define pp std::pair<int, int>

int N, val[1000005], prev_idx[1000005];
std::vector<int> value_seq, idx_seq;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &val[i]);
    value_seq.push_back(-1000000005);
    idx_seq.push_back(-1);

    for(int i = 0; i < N; ++i){
        if(val[i] > value_seq[value_seq.size() - 1]){
            prev_idx[i] = idx_seq[idx_seq.size() - 1];
            value_seq.push_back(val[i]);
            idx_seq.push_back(i);
        }
        else{
            std::vector<int>::iterator it;
            it = std::lower_bound(value_seq.begin(), value_seq.end(), val[i]);
            *it = val[i];
            it = it - value_seq.begin() + idx_seq.begin();
            *it = i;
            prev_idx[i] = *(--it);
        }
    }
    std::stack<int> ans;
    int tmp = idx_seq[idx_seq.size() - 1];
    ans.push(val[tmp]);
    tmp = prev_idx[tmp];
    while(tmp != -1){
        ans.push(val[tmp]);
        tmp = prev_idx[tmp];
    }
    printf("%d\n", value_seq.size() - 1);
    while(!ans.empty()){
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}
