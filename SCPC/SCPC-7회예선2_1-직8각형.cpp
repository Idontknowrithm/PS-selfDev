// 첫 번째 성공할 뻔한 접근:
// 먼저 입력받은 8개의 점의 x값과 y값의 평균값을 구하고, 이 평균값을
// 중심으로 직8각형을 위치시킨다. 대신에 정수를 평균하면서, 또한 이
// 중심을 기준으로 x0, y0을 구하는 과정에서 오차가 생길 수 있으므로 
// 중심을 기준으로 +-2 한 점들을 모두 중심으로 삼아본다 -> 5*5 = 25개의 케이스
// 이렇게 직8각형의 위치를 결정한 후, 입력받은 8개의 점과 직8각형의 각 점을
// 브루트포스로 연결(8! ~ 4만)시켜 거리의 최솟값을 구한다
// -> 25개의 케이스를 일일히 하는 과정에서 TLE. 즉 한 번만에 직8각형의
//    위치를 결정할 수 있어야 한다.
    
// 해답 접근:
// 우리가 결정해야할 직8각형의 각 점의 좌표를 (x0, y0), ... , (x8, y8)이라
// 하고, 주어진 점의 좌표를 (a0, b0), ... , (a8, b8)이라 하자. 이때 우리가
// 구해야할 최소값은 ∑ |xi - au| + |yi - bu|가 된다. 이때 xi와 yi는 각각
// x0, y0을 기준으로 재정의할 수 있는데, x0 + nK, y0 + nK 꼴이 된다. 따라서
// 구해야하는 최소값을 ∑ |x0 - (au - nK)| + |y0 - (bu - nK)| 꼴로 바꾸어
// 생각할 수 있다. 이 값을 최소로 만드는 x0, y0은 각각 (au - nK)의 중간값,
// (bu - nK)의 중간값으로 결정할 수 있다. 따라서 이 방식으로 직8각형의 위치를
// 한 번에 결정시키고, 각 점들을 완전탐색으로 결정시키면 통과된다.
    
// ※왜 평균값이 아닌 중간값을 사용?
//     간단한 예시로 증명할 수 있다. 1, 1, 1, 1, 100에서 중간값과 평균값을
//     사용한 택시거리를 비교해보자.
//     중간값은 1, 이때의 택시거리는 0 + 0 + 0 + 0 + 99 = 99
//     평균값은 20, 이때의 택시거리는 19 + 19 + 19 + 19 + 80 = 156
//     99 < 156

// 이 문제에서는 적절한 어림값 사용은 TLE를 초래했다. 문제 자체의 아이디어를
// 여러 방법을 사용하여 수식적으로 접근해보면서 괜찮은 알고리즘을 찾아야했다.
// 물론 헝가리안 알고리즘이라고 이 문제에 적합한 알고리즘이 따로 있으나, 그
// 알고리즘을 공부하는 것 보다는 위 풀이처럼 언제나 생각할 수 있는 알고리즘을
// 사용해서 반응속도를 높이는 것이 더 실용적일 것 같다.

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#define ll long long
#define pp std::pair<ll, ll>

ll T, K;

ll min_len(std::vector<pp> &dots){
    std::vector<ll> x8 = {0, 0, K, 2 * K, 3 * K, 3 * K, 2 * K, K};
    std::vector<ll> y8 = {0, K, 2 * K, 2 * K, K, 0, -K, -K};
    ll xp, yp, ret = 1e10, x[8], y[8], s_x[8], s_y[8], perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    for(ll i = 0; i < 8; ++i){
        x[i] = dots[i].first;
        y[i] = dots[i].second;
    }
    do{
        ll tmp_ans = 0;

        for(ll i = 0; i < 8; ++i){
            s_x[i] = x[perm[i]] - x8[i];
            s_y[i] = y[perm[i]] - y8[i];
        }
        std::sort(s_x, s_x + 8);
        std::sort(s_y, s_y + 8);

        xp = s_x[3];
        yp = s_y[3];

        for(ll i = 0; i < 8; ++i){
            tmp_ans += std::abs((xp + x8[i]) - x[perm[i]]);
            tmp_ans += std::abs((yp + y8[i]) - y[perm[i]]);
        }
        ret = std::min(ret, tmp_ans);
    }while(std::next_permutation(perm, perm + 8));

    return ret;
}

int main() {
    scanf("%lld", &T);
    for(ll z = 1; z <= T; ++z){
        std::vector<pp> dots;

        scanf("%lld", &K);
        for(ll i = 0; i < 8; ++i){
            ll a, b;

            scanf("%lld %lld", &a, &b);
            dots.push_back({a, b});
        }

        printf("Case #%lld\n%lld\n", z, min_len(dots));
    }
    return 0;
}
