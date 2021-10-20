#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#define pp std::pair<int, int>

int N, ans[1000005];
std::stack<pp> stk;

int main() {
    scanf("%d", &N);
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < N; ++i){
        int tmp;
        scanf("%d", &tmp);
        while(!stk.empty() && stk.top().first < tmp){
            ans[stk.top().second] = tmp;
            stk.pop();
        }
        stk.push({tmp, i});
    }
    for(int i = 0; i < N; ++i)
        printf("%d ", ans[i]);
    return 0;
}
