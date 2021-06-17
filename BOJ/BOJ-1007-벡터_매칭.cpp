// 점들의 집합에서 벡터를 만들려면 시작점과 끝점이 있어야한다는 점이 문제 핵심
// N개의 점에서 N/2개의 점은 시작점이고 N/2개의 점은 끝점인데, 이때
// 점 A, B로 만드는 벡터는 B - A, 즉 점의 반은 -, 나머지 반은 +

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#define pp std::pair<double, double>
#define x first
#define y second

const double INF = 1e20;
int T, N, combi[25];
double ans; pp tmp;
std::vector<pp> input;

int main() {
    double ia, ib;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%lf %lf", &ia, &ib);
            input.push_back({ia, ib});
        }
        memset(combi, 0, sizeof(combi));
        for(int i = 0; i < N / 2; ++i)
            combi[i] = 1;
        ans = INF;
        do{
            tmp = {0, 0};
            for(int i = 0; i < N; ++i){
                if(combi[i]){
                    tmp.x += input[i].x;
                    tmp.y += input[i].y;
                }
                else{
                    tmp.x -= input[i].x;
                    tmp.y -= input[i].y;
                }
            }
            ans = std::min(ans, sqrt((tmp.x * tmp.x) + (tmp.y * tmp.y)));
        }while(std::prev_permutation(combi, combi + N));

        printf("%.7lf\n", ans);
        input.clear();
    }
    return 0;
}
