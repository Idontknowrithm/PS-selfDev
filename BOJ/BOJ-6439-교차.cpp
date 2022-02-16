// 직사각형과 선분의 교차를 판별하는 문제였는데 문제를 잘못 이해해서
// 선분이 직사각형에 포함된 경우를 거짓으로 판별해버렸다

#include<iostream>
#include<algorithm>
#include<cmath>
#define pp std::pair<int, int>
#define r first
#define c second
typedef int unit;

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

int T;
pp lstart, lend, sq1, sq2;

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
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d %d %d %d %d %d %d",
              &lstart.r, &lstart.c, &lend.r, &lend.c, &sq1.r, &sq1.c, &sq2.r, &sq2.c);
        if(sq1.r > sq2.r)
            std::swap(sq1.r, sq2.r);
        if(sq1.c > sq2.c)
            std::swap(sq1.c, sq2.c);
        
        int L, R, U, D;
        L = std::min(lstart.r, lend.r);
        R = std::max(lstart.r, lend.r);
        U = std::max(lstart.c, lend.c);
        D = std::min(lstart.c, lend.c);
        if(sq1.r < L && sq2.r > R && sq1.c < D && sq2.c > U){
            printf("T\n");
            continue;
        }
        
        vec_2 line_s(lstart.r, lstart.c);
        vec_2 line_e(lend.r, lend.c);

        vec_2 sqline1(sq1.r, sq1.c);
        vec_2 sqline2(sq1.r, sq2.c);
        vec_2 sqline3(sq2.r, sq2.c);
        vec_2 sqline4(sq2.r, sq1.c);

        if(seg_intersection(line_s, line_e, sqline1, sqline2) ||
           seg_intersection(line_s, line_e, sqline2, sqline3) ||
           seg_intersection(line_s, line_e, sqline3, sqline4) ||
           seg_intersection(line_s, line_e, sqline4, sqline1)){
            printf("T\n");
        }
        else 
            printf("F\n");
    }
    return 0;
}
