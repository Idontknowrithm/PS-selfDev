#include <string>
#include <vector>

using namespace std;

int N, M, test[25][25];

bool brute(int r, int c, vector<vector<int>> &key, vector<vector<int>> &lock){
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        test[i][u] = lock[i][u];
    for(int i = 0; i < M; ++i)
    for(int u = 0; u < M; ++u){
        if(r + i >= 0 && r + i < N &&
           c + u >= 0 && c + u < N){
            test[r + i][c + u] += key[i][u];
        }
    }
    bool possible = true;
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        possible = (test[i][u] == 1) ? possible : false;
    return possible;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    N = lock.size(); M = key.size();

    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < N + M + 1; ++i){
            for(int u = 0; u < N + M + 1; ++u){
                answer = (brute(i - M, u - M, key, lock)) ? true : answer;        
            }
        }
        int tmp[25][25];
        for(int i = 0; i < M; ++i)
        for(int u = 0; u < M; ++u)
            tmp[M - u - 1][i] = key[i][u];
        for(int i = 0; i < M; ++i)
        for(int u = 0; u < M; ++u)
            key[i][u] = tmp[i][u];
    }

    return answer;
}
