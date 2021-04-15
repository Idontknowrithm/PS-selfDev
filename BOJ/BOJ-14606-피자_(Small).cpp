#include<iostream>
#include<queue>

int N, ans;
std::queue<int> pizza;

int main() {
    scanf("%d", &N);
    pizza.push(N);
    while(!pizza.empty()){
        int tmp = pizza.front();
        pizza.pop();
        if(tmp != 1 && (tmp & 1)){
            ans += (tmp / 2) * (tmp / 2 + 1);
            pizza.push(tmp / 2);
            pizza.push(tmp / 2 + 1);
        }
        else if(tmp != 1){
            ans += (tmp / 2) * (tmp / 2);
            pizza.push(tmp / 2);
            pizza.push(tmp / 2);
        }
    }
    printf("%d", ans);
    return 0;
}
