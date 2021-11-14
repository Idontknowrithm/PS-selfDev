일반적인 경우는 교차점을 찾는 식을 이용했고, 두 직선이 기울기가 같으면서
만나는 특수한 경우는 따로 구해주었다(이때 한 점에서 만날 수도 있고, 여러
점에서 만날 수도 있기 때문)
또한 기울기를 비교할 때는 정수로 된 점을 이용해 기울기를 직접 구해 비교하면
형 변환에 시간이 많이 걸리고, 형 변환 시 오차범위를 벗어나는 오차가 생길 수 있음
  -> (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4)가 0인지를 이용

#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
#define pp std::pair<ll, ll>
#define x first
#define y second

typedef ll unit;

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
    unit dot(const vec_2& v) const{
        return x * v.x + y * v.y;
    }
    unit cross(const vec_2& v) const{
        if(x * v.y - v.x * y < 0)  return (unit)-1;
        if(x * v.y - v.x * y > 0)  return (unit)1;
        if(x * v.y - v.x * y == 0) return (unit)0;
    }
};
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

int main() {
    pp as, ae, bs, be;
    scanf("%lld %lld %lld %lld", &as.x, &as.y, &ae.x, &ae.y);
    scanf("%lld %lld %lld %lld", &bs.x, &bs.y, &be.x, &be.y);
    if(as > ae) std::swap(as, ae);
    if(bs > be) std::swap(bs, be);
    vec_2 vas(as.x, as.y), vae(ae.x, ae.y);
    vec_2 vbs(bs.x, bs.y), vbe(be.x, be.y);
    bool ans = seg_intersection(vas, vae, vbs, vbe);
    printf("%d", ans);
    double x_numer = (as.x * ae.y - as.y * ae.x) * (bs.x - be.x) - (as.x - ae.x) * (bs.x * be.y - bs.y * be.x);
    double y_numer = (as.x * ae.y - as.y * ae.x) * (bs.y - be.y) - (as.y - ae.y) * (bs.x * be.y - bs.y * be.x);
    double deno = (as.x - ae.x) * (bs.y - be.y) - (as.y - ae.y) * (bs.x - be.x);
    double X = x_numer / deno, Y = y_numer / deno;
    if(ans){
        if(deno == 0){
            if(ae == bs)
                printf("\n%lld %lld", ae.x, ae.y);
            else if(as == be)
                printf("\n%lld %lld", be.x, be.y);
        }
        else{
    
            printf("\n%.10lf %.10lf", X, Y);
        }
    }

    return 0;
}
