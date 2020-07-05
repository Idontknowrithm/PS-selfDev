#include<iostream>
#include<queue>

int main () {
    std::queue<int> table;
    int N, ans;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        table.push(i + 1);
    while(1){
        ans = table.front();
        table.pop();
        if(table.empty()) break;
        ans = table.front();
        table.push(ans);
        table.pop();
    }
    printf("%d", ans);
    return 0;
}
