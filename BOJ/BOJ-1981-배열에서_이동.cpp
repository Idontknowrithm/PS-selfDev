// 배열에서 이동하면서 이동한 자취에서 최대 최소의 차가 최소일 때 그 최솟값 구하기
// 일단 DFS로 접근해서 TLE 나면 메모이제이션을 추가해주려 했는데 조금 복잡한 것 같아서
// 풀이를 참고 -> DFS + DP가 아닌 이분탐색 활용한 BFS
// 정답 지향적으로 풀이해야했음
// 처음(0, 0)부터 시작해서 올라가면서 답을 찾기 (X)
// 답이 mid라고 가정하고 해보고, 되는지 안되는지 판단하기 (O)
// 정답 풀이: 최대 최소의 차를 0, 200이라 놓고(여기에서는 차의 최대를 200으로
// 놓지 않고 배열의 최대 최소를 구해 그 차를 최대로 함) 이분탐색을 진행
// mid를 (start + end) / 2로 놓고, 차가 mid 안으로 가능한 지에 대해서 bfs로 
// 돈 후 가능하면 차의 범위를 줄이기(end = mid - 1), 불가능하면 차의 범위를 늘리기
// (start = mid + 1)

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105, INF = 10005;
bool visited[MAX][MAX];
int N, H = -1, L = INF, arr[MAX][MAX];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}
bool BFS(int mid){
    for(int t = L; t <= H - mid; ++t){
        memset(visited, true, sizeof(visited));
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u){
            if(arr[i][u] >= t && arr[i][u] <= t + mid)
                visited[i][u] = false;
        }
        bool arrived = false;
        std::queue<pp> que;
        que.push({0, 0});
        if(visited[0][0])
            continue;
        else 
            visited[0][0] = true;
        while(!que.empty()){
            int r = que.front().first, c = que.front().second;
            que.pop();
            if(r == N - 1 && c == N - 1){
                arrived = true;
                break;
            }
            for(int i = 0; i < 4; ++i){
                int R = r + y[i], C = c + x[i];
                if(possible(R, C) && !visited[R][C]){
                    visited[R][C] = true;
                    que.push({R, C});
                }
            }
        }
        if(arrived)
            return true;
    }
    return false;        
}
int binary_search(){
    int start = 0, end = H - L, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(BFS(mid))
            end = mid - 1;
        else 
            start = mid + 1;
    }
    return end + 1;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        scanf("%d", &arr[i][u]);
        H = std::max(H, arr[i][u]);
        L = std::min(L, arr[i][u]);
    }
    printf("%d", binary_search());
    return 0;
}
