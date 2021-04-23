#include<iostream>
#include<vector>
#include<queue>
#define INF 2147483647

int N, table[1000005];
std::queue<int> bfs;
std::vector<int> nums[1000005];

int main() {
    scanf("%d", &N);
    for(int i = 1; i < N; ++i)
        table[i] = INF;
    table[N] = 0;
    nums[N].push_back(N);
    bfs.push(N);
    while(!bfs.empty() && table[1] == INF){
        int tmp = bfs.front();
        bfs.pop();
        if(tmp % 3 == 0 && table[tmp / 3] > table[tmp] + 1){
            table[tmp / 3] = table[tmp] + 1;
            nums[tmp / 3] = nums[tmp];
            nums[tmp / 3].push_back(tmp / 3);
            bfs.push(tmp / 3);
        }
        if(tmp % 2 == 0 && table[tmp / 2] > table[tmp] + 1){
            table[tmp / 2] = table[tmp] + 1;
            nums[tmp / 2] = nums[tmp];
            nums[tmp / 2].push_back(tmp / 2);
            bfs.push(tmp / 2);
        }
        if(tmp != 1 && table[tmp - 1] > table[tmp] + 1){
            table[tmp - 1] = table[tmp] + 1;
            nums[tmp - 1] = nums[tmp];
            nums[tmp - 1].push_back(tmp - 1);
            bfs.push(tmp - 1);
        }
    }

    printf("%d\n", table[1]);
    for(int i = 0; i < nums[1].size(); ++i)
        printf("%d ", nums[1][i]);
    
    return 0;
}
