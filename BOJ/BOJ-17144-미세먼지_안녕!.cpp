#include<iostream>
#include<vector>
#include<algorithm>

typedef struct{
    int r, c, weight;
}dustData;
int y[4] = {1, 0, -1, 0};
int x[4] = {0, -1, 0, 1};
int N, M, T, room[55][55];
int machine; // below
std::vector<dustData> dust;

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M);
}
void diffusion(){
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            if(room[i][u] > 0)
                dust.push_back({i, u, room[i][u]});
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        room[i][u] = 0;
    room[machine][0] = -1;
    room[machine - 1][0] = -1;
    
    for(int i = 0; i < dust.size(); ++i){
        int prop = 0;
        for(int u = 0; u < 4; ++u){
            if(possible(dust[i].r + y[u], dust[i].c + x[u]) && room[dust[i].r + y[u]][dust[i].c + x[u]] != -1){
                room[dust[i].r + y[u]][dust[i].c + x[u]] += dust[i].weight / 5;
                ++prop;
            }
        }
        room[dust[i].r][dust[i].c] += dust[i].weight - dust[i].weight / 5 * prop;
    }

    dust.clear();
}
void runMachine(){
    for(int i = machine - 2; i > 0; --i)
        room[i][0] = room[i - 1][0];
    for(int i = 0; i < M - 1; ++i)
        room[0][i] = room[0][i + 1];
    for(int i = 0; i < machine - 1; ++i)
        room[i][M - 1] = room[i + 1][M - 1];
    for(int i = M - 1; i > 1; --i)
        room[machine - 1][i] = room[machine - 1][i - 1];
    room[machine - 1][1] = 0;

    for(int i = machine + 1; i < N - 1; ++i)
        room[i][0] = room[i + 1][0];
    for(int i = 0; i < M - 1; ++i)
        room[N - 1][i] = room[N - 1][i + 1];
    for(int i = N - 1; i > machine; --i)
        room[i][M - 1] = room[i - 1][M - 1];
    for(int i = M - 1; i > 1; --i)
        room[machine][i] = room[machine][i - 1];
    room[machine][1] = 0;
}
int main () {
    scanf("%d %d %d", &N, &M, &T);

    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%d", &room[i][u]);
            if(room[i][u] == -1)
                machine = i;
        }
    }

    for(int i = 0; i < T; ++i){
        diffusion();
        runMachine();
    }
    int ans = 0;
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        ans += (room[i][u] != -1) ? room[i][u] : 0;

    printf("%d", ans);

    return 0;
}
