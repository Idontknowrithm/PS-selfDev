// 최적화 문제는 브루트포스 -> 백트래킹 -> DP -> 분할정복 순으로 생각해볼 수 있어야 함
// 제한된 크기가 충분히 작으면서 브루트포스로는 불가능할 때 백트래킹을 생각해볼 수 있음
// 생각의 흐름: DP로 생각했다가 DP 테이블과 알고리즘을 설계하기 어려워 구글링을 해본 후 백트래킹 알고리즘으로
// 메모이제이션을 없애고 DFS로 진행했다가 선별적인 탐색 알고리즘 오류로 문제 발생 -> 다시 모든 경우의 수 탐색하는
// 백트래킹 아이디어로 해결

#include<iostream>
#include<algorithm>
#include<cstring>
#define int_pages int p1, int p2, int p3, int p4, int p5
#define int_ref_pages int &p1, int &p2, int &p3, int &p4, int &p5
#define pages p1, p2, p3, p4, p5

const int MAX = 15, INF = 3000;
bool visited[MAX][MAX];
int ones, ans = INF, board[MAX][MAX];

bool possible(int r, int c, int size){
    for(int i = r; i < r + size; ++i)
    for(int u = c; u < c + size; ++u)
        if(i < 0 || i > 9 || u < 0 || u > 9 || !board[i][u] || visited[i][u])
            return false;
    return true;
}
void visiting(int r, int c, int size, bool in){
    for(int i = 0; i < size; ++i)
    for(int u = 0; u < size; ++u)
        visited[r + i][c + u] = (in) ? true : false;
}
void page_sub(int_ref_pages, int idx){
    if(idx == 1) --p1;
    if(idx == 2) --p2;
    if(idx == 3) --p3;
    if(idx == 4) --p4;
    if(idx == 5) --p5;
}
void page_add(int_ref_pages, int idx){
    if(idx == 1) ++p1;
    if(idx == 2) ++p2;
    if(idx == 3) ++p3;
    if(idx == 4) ++p4;
    if(idx == 5) ++p5;
}
void DFS(int pos, int_pages, int left, int cur_size){
    if(p1 == -1 || p2 == -1 || p3 == -1 || p4 == -1 || p5 == -1)
        return;
    if(!left){
        ans = std::min(ans, cur_size);
        return;
    }
    int first_one;
    for(first_one = pos; first_one < 100; ++first_one){
        int tr = first_one / 10, tc = first_one % 10;
        if(!visited[tr][tc] && board[tr][tc]) break;
    }
    if(first_one == 100)
        return;

    int r = first_one / 10, c = first_one % 10;
    for(int i = 5; i > 0; --i){
        if(possible(r, c, i)){
            visiting(r, c, i, true);
            page_sub(pages, i);
            DFS(first_one + i, pages, left - i * i, cur_size + 1);
            page_add(pages, i);
            visiting(r, c, i, false);
        }
    }
}

int main() {
    for(int i = 0; i < 10; ++i)
    for(int u = 0; u < 10; ++u){
        scanf("%d", &board[i][u]);
        ones += board[i][u];
    }
    DFS(0, 5, 5, 5, 5, 5, ones, 0);
    printf("%d", (ans == 3000) ? -1 : ans);
    return 0;
}
