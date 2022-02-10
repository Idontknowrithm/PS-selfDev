// 알고리즘을 알고 있느냐 보다 알고있는 자료구조를
// 잘 사용할 수 있느냐를 묻는 문제
// 처음에 set(레드블랙 트리) 이용해서 앞에서부터 하나씩
// set에 담고 여기에서 upper bound 이용해서 레이저 맞는
// 건물 탐색하려고 했는데 이터레이터 어떻게 쓸 지 감이
// 안와서 알고리즘 분류 봤는데 스택 되어있어서 바로 피벗
// 문제를 볼 때는 쉬운 생각, 혹은 알고리즘부터 시작해서
// 점점 안풀리면 어려운 생각으로 가야할 것 같음

#include<iostream>
#include<algorithm>
#include<stack>
#define pp std::pair<int, int>

int N;
std::stack<pp> stk;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int input;
        scanf("%d", &input);
        while(!stk.empty() && stk.top().first < input)
            stk.pop();
        
        if(stk.empty())
            printf("0 ");
        else
            printf("%d ", stk.top().second);
        
        stk.push({input, i + 1});
    }
    return 0;
}
