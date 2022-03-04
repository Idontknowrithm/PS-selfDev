// 이 문제도 문제 자체의 통찰을 요구했다. 대회에서 풀 때는 문제 자체에 대한
// 고민을 별로 안하고 어떻게 해결할지만 생각해서 여러 알고리즘을 생각해봤다.
// 예를들어서 가능한 모든 구간에 대해서 탐색해보려다가 N^2 복잡도를 나타내므로,
// NlogN 시간복잡도를 갖는 알고리즘을 생각해봤다. 문제를 간단히 본 바로는 N의 
// 복잡도는 절대 안될 것 같아서 생각 자체를 안했다. 그러나 이 문제에서는 K가
// S의 두 배가 되는 것을 어떻게 표현할 것인지에 대해서 깊은 통찰이 필요했고,
// 이 통찰로 N 복잡도를 가지는 알고리즘을 사용할 수 있었는데 그 통찰의 내용은
// S를 2, K를 -1로 둠으로써 (다른 문자는 0) 누적합을 사용했을 때 K가 S의 두
// 배가 되었을 때 0이 될 수 있게 만드는 것이다. 이 방법을 사용하면
//   1. 문자열을 0, -1, 2로 구성된 수열로 바꾼다
//   2. 그 수열에 대한 누적합을 구한다
//   3. 다른 배열을 하나 만들어서 그 배열에 각 누적합의 
//      값을 가지는 최소 인덱스를 저장한다. 다시 말해 배열의
//      인덱스가 각 누적합의 값이고, 배열의 값이 그 누적합의
//      값을 가지는 가장 최소의 인덱스이다
//   4. 3번의 배열을 사용해 모든 인덱스에 대한 SKK 문자열의
//      길이를 구하고, 그 길이중 max 값을 출력한다
// 위와 같은 문제 풀이 방향을 설정할 수 있다

#include<iostream>
#include<algorithm>

const int MAX = 100005;
int N, ans;
int str[MAX], where_S[MAX], sum_min_idx[MAX << 1], sum[MAX];
std::string input;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> input;
    N = input.size();
    for(int i = 0; i < N; ++i){
        if(input[i] == 'S')
            str[i] = 2;
        else if(input[i] == 'K')
            str[i] = -1;
        else 
            str[i] = 0;

        where_S[i + 1] = where_S[i] + ((input[i] == 'S') ? 1 : 0);
    }
        
    
    for(int i = 1; i <= N; ++i){
        sum[i] = sum[i - 1] + str[i - 1];
        if(sum[i] >= 0 && !sum_min_idx[sum[i]])
            sum_min_idx[sum[i]] = i;
        else if(sum[i] < 0 && !sum_min_idx[MAX - 5 - sum[i]])
            sum_min_idx[MAX - 5 - sum[i]] = i;
    }
    sum_min_idx[0] = 0;

    for(int i = 2; i <= N; ++i){
        if(sum[i] >= 0 && sum[i] == sum[sum_min_idx[sum[i]]] && 
           where_S[i] - where_S[sum_min_idx[sum[i]]] > 0)
            ans = std::max(ans, i - sum_min_idx[sum[i]]);
        
        else if(sum[i] < 0 && sum[i] == sum[sum_min_idx[MAX - 5 - sum[i]]] &&
                where_S[i] - where_S[sum_min_idx[MAX - 5 - sum[i]]])
            ans = std::max(ans, i - sum_min_idx[MAX - 5 - sum[i]]);
    }

    ans = (ans < 3) ? -1 : ans;
    std::cout << ans;

    return 0;
}
