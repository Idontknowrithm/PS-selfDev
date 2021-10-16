#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int puzzle[10][10], ans[10][10];
bool end;
std::vector<pp> emp;

bool possible(int r, int c, int val){
    for(int i = 0; i < 9; ++i){
        if(puzzle[i][c] == val) return false;
        if(puzzle[r][i] == val) return false;
    }
    for(int i = (r / 3) * 3; i < (r / 3) * 3 + 3; ++i)
    for(int u = (c / 3) * 3; u < (c / 3) * 3 + 3; ++u)
        if(puzzle[i][u] == val) return false;

    return true;
}
void backtracking(int idx){
    if(end) return;
    if(idx == emp.size()){
        end = true;
        for(int i = 0; i < 9; ++i)
        for(int u = 0; u < 9; ++u)
            ans[i][u] = puzzle[i][u];
        return;
    }
    int R = emp[idx].first, C = emp[idx].second;
    for(int i = 1; i <= 9; ++i){
        if(possible(R, C, i)){
            puzzle[R][C] = i;
            backtracking(idx + 1);
            puzzle[R][C] = 0;
        }
    }
}

int main() {
    for(int i = 0; i < 9; ++i)
    for(int u = 0; u < 9; ++u){
        scanf("%d", &puzzle[i][u]);
        if(!puzzle[i][u])
            emp.push_back({i, u});
    }
    backtracking(0);
    for(int i = 0; i < 9; ++i){
        for(int u = 0; u < 9; ++u)
            printf("%d ", ans[i][u]);
        puts("");
    }    
    return 0;
}
