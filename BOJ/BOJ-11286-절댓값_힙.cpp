#include<iostream>
#include<queue>
#include<algorithm>

typedef struct{
    int num;
    int sign;
} data;
typedef struct{
    bool operator()(const data& a, const data& b){
        if(a.num > b.num)
            return 1;
        else if(a.num < b.num)
            return 0;
        else 
            return a.sign > b.sign;
    }
}compare;

std::priority_queue<data, std::vector<data>, compare> heap;

int main () {
    int N, inp;

    for(scanf("%d", &N); N > 0; --N){
        scanf("%d", &inp);
        if(!inp){
            if(heap.empty())
                printf("0\n");
            else if(heap.top().sign == 1){
                printf("%d\n", heap.top().num);
                heap.pop();
            }
            else{
                printf("%d\n", -heap.top().num);
                heap.pop();
            }
        }
        else {
            if(inp < 0)
                heap.push({-inp, -1});
            else if(inp > 0)
                heap.push({inp, 1});
        }
    }

    return 0;
}
