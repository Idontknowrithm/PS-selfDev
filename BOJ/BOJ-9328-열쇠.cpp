// 비합리적인 부분을 파고드는 것은 조금 고쳤는데
// 이번에는 합리적인 오류를 찾는 자체에 조금 시간이 걸림
// 알고리즘 돌아가면서 필요한 부분에 대해 하나씩 

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#define pp std::pair<int, int>
#define r first
#define c second

int y[4] = {1, 0, -1, 0};
int x[4] = {0, -1, 0, 1};
int T, N, M, door, key, ans, visited[105][105];
char building[105][105], key_input[100005];
std::vector<pp> where_door;

bool possible(int R, int C){
    return (R >= 0 && R < N && C >= 0 && C < M);
}
void traversal(int startR, int startC){
    std::queue<pp> bfs;
    bfs.push({startR, startC});
    visited[startR][startC] = 1;
    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        if(building[tmp.r][tmp.c] >= 'A' && building[tmp.r][tmp.c] <= 'Z'){
            int t = building[tmp.r][tmp.c] - 'A';
            door |= (1 << t);
            where_door.push_back({tmp.r, tmp.c});
        }
        else{
            if(building[tmp.r][tmp.c] >= 'a' && building[tmp.r][tmp.c] <= 'z'){
                int t = building[tmp.r][tmp.c] - 'a';
                key |= (1 << t);
                building[tmp.r][tmp.c] = '.';
            }
            else if(building[tmp.r][tmp.c] == '$'){
                ++ans;
                building[tmp.r][tmp.c] = '.';
            }
            for(int i = 0; i < 4; ++i){
                if(possible(tmp.r + y[i], tmp.c + x[i]) && 
                   building[tmp.r + y[i]][tmp.c + x[i]] != '*' &&
                   !visited[tmp.r + y[i]][tmp.c + x[i]]){
                    visited[tmp.r + y[i]][tmp.c + x[i]] = 1;
                    bfs.push({tmp.r + y[i], tmp.c + x[i]});
                }
            }
        }
    }
}

int main() {    
    for(scanf("%d\n", &T); T > 0; --T){
        where_door.clear(); // 와.. 진짜 이거 때문에.. ㅠㅠㅠ
        ans = key = 0;
        scanf("%d %d\n", &N, &M);
        memset(building, '.', sizeof(building));
        for(int i = 1; i <= N; ++i){
            for(int u = 1; u <= M; ++u)
                scanf("%c", &building[i][u]);
            getchar();
        }
        N += 2; M += 2;
        int ptr = 0;
        while(1){
            char ch = getchar();
            if(ch == '\n') break;
            key_input[ptr++] = ch;
        }
        
        if(key_input[0] != '0'){
            for(int i = 0; i < ptr; ++i){
                int k = key_input[i] - 'a';
                key |= (1 << k);
            }
        }
        while(1){
            door = 0;
            memset(visited, 0, sizeof(visited));
            traversal(0, 0);
            if(!(door & key)) break;
            for(int i = 0; i < where_door.size(); ++i){
                int tmp_door = building[where_door[i].r][where_door[i].c] - 'A';
                if(key & (1 << tmp_door))
                    building[where_door[i].r][where_door[i].c] = '.';
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
// 한번 돌고 갈 수 있는 문 수집하고
// 문 중에서 딸 수 있는 게 있으면 따고 다음번 돌고
// 문 중에서 딸 수 있는 게 없으면 종료
