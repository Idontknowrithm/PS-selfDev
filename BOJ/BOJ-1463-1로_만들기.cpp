// 0.15초니까.. 과도하게 시간이 촉박하다면 메모리 할당 시간도 고려할 것

#include<iostream>
#include<queue>
#include<algorithm>
#define pp std::pair<int, int>
#define INF 2147483647

int N, min = INF;

void search(int N){
    std::queue<pp> bfs;
    bfs.push({N, 0});
    while(!bfs.empty()){
        pp temp = bfs.front();
        bfs.pop();
        if(temp.first == 1){
            min = (min > temp.second) ? temp.second : min;
        }
        if(min < temp.second || temp.first == 1) continue;

        if(!(temp.first & 1))
            bfs.push({temp.first / 2, temp.second + 1});
        if(temp.first % 3 == 0)
            bfs.push({temp.first / 3, temp.second + 1});
        if(temp.first != 1)
            bfs.push({temp.first - 1, temp.second + 1});
    }
}

int main() {
    scanf("%d", &N);
    search(N);
    printf("%d", min);
    return 0;
}
