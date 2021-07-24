#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>

typedef int unit;

const double pi = 2.0 * acos(0.0);

class vec_2{
    public:
    unit x, y, p, q;

    explicit vec_2(unit x_ = 0, unit y_ = 0) : x(x_), y(y_) {}
    bool operator ==(const vec_2& v) const{
        return (x == v.x && y == v.y);
    }
    bool operator <(const vec_2& v) const{
        if(1ll * q * v.p != 1ll * p * v.q)
            return 1ll * q * v.p < 1ll * p * v.q;
        return (y != v.y) ? (y < v.y) : (x < v.x);
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

typedef std::vector<vec_2> polygon;
int N, M;
polygon input;

int convex_hull(polygon &points){
    std::stack<int> stk;
    int next, N = points.size();
    std::sort(points.begin(), points.end());
    for(int i = 1; i < N; ++i){
        points[i].p = points[i].x - points[0].x;
        points[i].q = points[i].y - points[0].y;
    }
    std::sort(points.begin() + 1, points.end());

    stk.push(0);
    stk.push(1);
    next = 2;
    while(next < N){
        while(stk.size() >= 2){
            int tmp1, tmp2;
            tmp1 = stk.top();
            stk.pop();
            tmp2 = stk.top();

            if(ccw(points[tmp2], points[tmp1], points[next]) > 0){
                stk.push(tmp1);
                break;
            }
        }
        stk.push(next++);
    }
    return stk.size();
}

int main() {
    int a, b;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &a, &b);
        vec_2 tmp(a, b);
        input.push_back(tmp);
    }
    printf("%d", convex_hull(input));
    return 0;
}
