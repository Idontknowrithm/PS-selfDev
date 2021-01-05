// 코포에서는 long long 범위 고려해야...
// long long 은 int 형 변환 잘 되는 듯

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

std::vector<int> num;
std::stack<int> stk;
int main(){
    int T, N, inp;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        num.clear();

        for(int i = 0; i < N; ++i){
            scanf("%d", &inp);
            num.push_back(inp);
        }
        std::sort(num.begin(), num.end());
        while(!stk.empty()) stk.pop();
        for(int i = 0; i < num.size(); ++i) stk.push(num[i]);

        long long alice = 0, bob = 0;
        while(!stk.empty()){
            alice += (stk.top() % 2 == 1) ? 0 : stk.top();
            stk.pop();
            if(stk.empty()) break;
            bob += (stk.top() % 2 == 1) ? stk.top() : 0;
            stk.pop();
        }
        if(alice < bob)
            printf("Bob\n");
        else if(alice > bob)
            printf("Alice\n");
        else 
            printf("Tie\n");
    }
    return 0;
}
