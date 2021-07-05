#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define SS start_segments
#define ES end_segments

typedef int unit;
const unit pi = 2.0 * acos(0.0);

class vec_2{
    unit x, y;
    
    public:
    explicit vec_2(unit x_ = 0, unit y_ = 0) : x(x_), y(y_) {}
    bool operator ==(const vec_2& v) const{
        return (x == v.x && y == v.y);
    }
    bool operator <(const vec_2& v) const{
        return (x != v.x) ? (x < v.x) : (y < v.y);
    }
    vec_2 operator +(const vec_2& v) const{
        return vec_2(x + v.x, y + v.y);
    }
    vec_2 operator -(const vec_2& v) const{
        return vec_2(x - v.x, y - v.y);
    }
    vec_2 operator *(const unit v) const{
        return vec_2(x * v, y * v);
    }
    unit cross(const vec_2& v) const{
        if(x * v.y - v.x * y < 0)  return (unit)-1;
        if(x * v.y - v.x * y > 0)  return (unit)1;
        if(x * v.y - v.x * y == 0) return (unit)0;
    }
};

int N, num_of_group, max_size_of_group, set[3005], group_size[3005];
std::vector<vec_2> start_segments, end_segments;

// CCW(Counter Clock Wise)
// a에 대해 b가 반시계 방향에 있으면 양수, 시계 방향이면 음수, 평행이면 0
unit ccw(vec_2 a, vec_2 b){
    return a.cross(b);
}
// 점 p를 기준으로 a에 대해 b가 반시계 방향에 있으면 양수
unit ccw(vec_2 p, vec_2 a, vec_2 b){
    return ccw(a - p, b - p);
}
// 선분 교차 여부
bool seg_intersection(vec_2 s1, vec_2 e1, vec_2 s2, vec_2 e2){
    unit one, two;
    one = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    two = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if(one == 0 && two == 0){
        if(e1 < s1) std::swap(s1, e1);
        if(e2 < s2) std::swap(s2, e2);
        return (!(e1 < s2 || e2 < s1)) || (e1 == s2 || e1 == e2 || s1 == s2 || s1 == e2);
    }
    return one <= 0 && two <= 0;
}
int find_set(int num){
    if (set[num]==num)
        return num;
    int parent = find_set(set[num]);
    set[num] = parent;
    return parent;
}
void union_set(int first, int second){
    int temp;
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}

int main() {
    for(int i = 0; i < 3005; ++i)
        set[i] = i;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        start_segments.push_back(vec_2(a, b));
        end_segments.push_back(vec_2(c, d));
    }
    for(int i = 0; i < N - 1; ++i){
        for(int u = i + 1; u < N; ++u){
            if(seg_intersection(SS[i], ES[i], SS[u], ES[u])){
                if(find_set(i) != find_set(u))
                    union_set(find_set(i), find_set(u));
            }
        }
    }
    for(int i = 0; i < N; ++i)
        ++group_size[find_set(i)];
    for(int i = 0; i < N; ++i){
        num_of_group += (group_size[i]) ? 1 : 0;
        max_size_of_group = std::max(max_size_of_group, group_size[i]);
    }
    printf("%d\n%d", num_of_group, max_size_of_group);
    return 0;
}
