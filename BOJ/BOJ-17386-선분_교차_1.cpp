#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long

class vec_2{
    
    public:
    ll x, y;
    explicit vec_2(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
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
    vec_2 operator *(const ll v) const{
        return vec_2(x * v, y * v);
    }
    ll cross(const vec_2& v) const{
        if(x * v.y - v.x * y < 0)  return (ll)-1;
        if(x * v.y - v.x * y > 0)  return (ll)1;
        if(x * v.y - v.x * y == 0) return (ll)0;
        
    }
};
// CCW(Counter Clock Wise)
// a에 대해 b가 반시계 방향에 있으면 양수, 시계 방향이면 음수, 평행이면 0
ll ccw(vec_2 a, vec_2 b){
    return a.cross(b);
}
// 점 p를 기준으로 a에 대해 b가 반시계 방향에 있으면 양수
ll ccw(vec_2 p, vec_2 a, vec_2 b){
    return ccw(a - p, b - p);
}
bool seg_llersection(vec_2 s1, vec_2 e1, vec_2 s2, vec_2 e2){
    ll one, two;
    one = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    two = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if(one == 0 && two == 0){
        if(e1 < s1) std::swap(s1, e1);
        if(e2 < s2) std::swap(s2, e2);
        return (!(e1 < s2 || e2 < s1)) || (e1 == s2 || e1 == e2 || s1 == s2 || s1 == e2);
    }
    return one <= 0 && two <= 0;
}
int main() {
    ll i[10];
    for(ll t = 0; t < 8; ++t)
        scanf("%lld", &i[t]);
    vec_2 a(i[0], i[1]), b(i[2], i[3]), c(i[4], i[5]), d(i[6], i[7]);
    
    if(seg_llersection(a, b, c, d))
        printf("1");
    else 
        printf("0");
    return 0;
}
