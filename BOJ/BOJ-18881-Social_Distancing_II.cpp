#include<iostream>
#include<algorithm>

const int MAX = 1000005, INF = 10000005;
int N, ans, safe_dist = INF, cow_line[MAX];
bool all_infected = true;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int c, s;
        scanf("%d %d", &c, &s);
        cow_line[c] = (s) ? 1 : -1;
        if(!s) all_infected = false;
    }
    if(all_infected){
        printf("1");
        return 0;
    }
    int start = 0;
    while(!cow_line[start++]);
    start;
    int prev_cow = start - 1, tmp_dist = 0;
    for(int i = start; i < MAX - 4; ++i){
        ++tmp_dist;
        if(cow_line[i]){
            if(cow_line[prev_cow] != cow_line[i]){
                safe_dist = std::min(safe_dist, i - prev_cow);
            }
            tmp_dist = 0;
            prev_cow = i;
        }
    }
    start = 0;
    while(cow_line[start++] != 1);
    prev_cow = start - 1;
    tmp_dist = 0;
    for(int i = start; i < MAX - 4; ++i){
        ++tmp_dist;
        if(cow_line[i] == 1 && tmp_dist < safe_dist){
            tmp_dist = 0;
            prev_cow = i;
        }
        else if(cow_line[i] == 1 && tmp_dist >= safe_dist){
            tmp_dist = 0;
            prev_cow = i;
            ++ans;
        }
    }
    printf("%d", ans + 1);
    return 0;
}
