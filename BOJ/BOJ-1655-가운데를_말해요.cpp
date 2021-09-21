// 숫자가 계속 들어오면서 동시에 중간값을 구하라는 쿼리를 처리해야하는데
// splay 트리의 kth 원소 구하기를 이용하려 했는데 어디선가 널포인트 에러 나서 접음
// 알고보니 두 개의 우선순위 큐를 이용하여 풀 수 있는 간단한 문제였는데 생각을 깊게 하지않아
// 쓸 데 없는 세그와 WA를 내게 됨

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> n_heap;
std::priority_queue<int> x_heap;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int tmp, x_top, n_top;
        scanf("%d", &tmp);
        if(i & 1)
            n_heap.push(tmp);
        else
            x_heap.push(tmp);
        if(!i){
            printf("%d\n", tmp);
            continue;
        }
        x_top = x_heap.top();
        n_top = n_heap.top();
        if(x_top > n_top){
            x_heap.pop();
            n_heap.pop();
            x_heap.push(n_top);
            n_heap.push(x_top);
        }
        
        if(i & 1)
            printf("%d\n", std::min(n_heap.top(), x_heap.top()));
        else 
            printf("%d\n", x_heap.top());
    }
    return 0;
}
