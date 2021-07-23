#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

typedef double unit;

const unit pi = 2.0 * acos(0.0);

class vec_2{
    public:
    unit x, y, p, q;

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
    // len of vec
    unit norm() const{
        return hypot(x, y);
    }
    // unit vec
    vec_2 normalize() const{
        return vec_2(x / norm(), y / norm());
    }
    // size of degree
    unit polar() const{
        return fmod(atan2(y, x) + 2 * pi, 2 * pi);
    }
    unit dot(const vec_2& v) const{
        return x * v.x + y * v.y;
    }
    unit cross(const vec_2& v) const{
        if(x * v.y - v.x * y < 0)  return (unit)-1;
        if(x * v.y - v.x * y > 0)  return (unit)1;
        if(x * v.y - v.x * y == 0) return (unit)0;
    }
    // projection
    vec_2 project(const vec_2& v) const{
        vec_2 r = v.normalize();
        return r * r.dot(*this);
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
vec_2 perp_foot(vec_2 p, vec_2 a, vec_2 b){
    return a + (p - a).project(b - a);
}
// 점과 선 사이의 거리
unit point_to_line(vec_2 p, vec_2 a, vec_2 b){
    return (p - perp_foot(p, a, b)).norm();
}
bool cmp(const vec_2 &a, const vec_2 &b){
    if(a.y == b.y) return a.x < b.x;
    else           return a.y < b.y;
}

typedef std::vector<vec_2> polygon;

polygon convex_hull(polygon &points){
    int N = points.size();
    std::sort(points.begin(), points.end(), cmp);
    for(int i = 1; i < N; ++i){
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }
}
