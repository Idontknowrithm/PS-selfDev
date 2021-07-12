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
    }
};

int N, D;
std::vector<data> commute;
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
        commute.push_back({a, b, i});
    }
    std::sort(commute.begin(), commute.end(), cmp);

}
