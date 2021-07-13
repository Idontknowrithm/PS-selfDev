#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define pp std::pair<int, int>

typedef struct{
    int a, b, idx;
}data;
struct cmp_que{
    bool operator()(data a, data b){
        if(a.b == b.b) return a.a > b.a;
        else           return a.b > b.b;
    } // bool cmp랑 반대
};

int N, D, ans, included[100005];
std::vector<data> tmp_com, commute;
std::priority_queue<data, std::vector<data>, cmp_que> que;

bool cmp(const data a, const data b){
    if(a.a == b.a) return a.b < b.b;
    else           return a.a < b.a;
}


int main() {
    int a, b;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &a, &b);
        if(a > b) std::swap(a, b);
        tmp_com.push_back({a, b, i});
    }
    scanf("%d", &D);
    for(int i = 0; i < tmp_com.size(); ++i)
        if(tmp_com[i].b - tmp_com[i].a <= D)
            commute.push_back(tmp_com[i]);
    
    std::sort(commute.begin(), commute.end(), cmp);
    
    int rail_start = -1, tmp_ans = 0, start_incl = 0, start_excl = 0;
    for(int i = 0; i < commute.size(); ++i){
        if(rail_start == commute[i].a) continue;
        rail_start = commute[i].a;
        for(; start_excl < commute.size() && 
            commute[start_excl].a < rail_start; ++start_excl)
            --tmp_ans;
        for(; start_incl < commute.size() && 
            commute[start_incl].a < rail_start + D; ++start_incl)
            que.push(commute[start_incl]);

        while(!que.empty() && que.top().b <= rail_start + D){
            que.pop();
            ++tmp_ans;
        }
        
        ans = std::max(ans, tmp_ans);
    }
    
    printf("%d", ans);
    return 0;
}
