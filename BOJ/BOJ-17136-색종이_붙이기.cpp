#include<iostream>
#include<algorithm>
#include<cstring>
#define int_pages int p1, int p2, int p3, int p4, int p5
#define int_ref_pages int &p1, int &p2, int &p3, int &p4, int &p5
#define pages p1, p2, p3, p4, p5

const int MAX = 15, INF = 3000;
int ones, ans = INF, board[MAX][MAX], visited[MAX][MAX];

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
        visited[r + i][c + u] = (in) ? 1 : 0;
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
void DFS(int r, int c, int_pages, int left, int cur_size){
    if(p1 == -1 || p2 == -1 || p3 == -1 || p4 == -1 || p5 == -1 || visited[r][c])
        return;
    if(!left){
        ans = std::min(ans, cur_size);
        return;
    }
    if(r > 9 || r < 0 || c > 9 || c < 0)
        return;
    if(!board[r][c]){
        visited[r][c] = 1;
        DFS(r + 1, c, pages, left, cur_size);
        DFS(r, c + 1, pages, left, cur_size);
        DFS(r, c - 1, pages, left, cur_size);
        visited[r][c] = 0;
    }
    else{
        for(int i = 1; i <= 5; ++i){
            if(possible(r, c, i)){
                visiting(r, c, i, true);
                page_sub(pages, i);
                left -= i * i;
                DFS(r + i, c, pages, left, cur_size + 1);
                DFS(r, c + i, pages, left, cur_size + 1);
                DFS(r, c - 1, pages, left, cur_size + 1);
                left += i * i;
                page_add(pages, i);
                visiting(r, c, i, false);
            }
        }
    }
}

int main() {
    for(int i = 0; i < 10; ++i)
    for(int u = 0; u < 10; ++u){
        scanf("%d", &board[i][u]);
        ones += board[i][u];
    }
    DFS(0, 0, 5, 5, 5, 5, 5, ones, 0);
    printf("%d", ans);
    return 0;
}
