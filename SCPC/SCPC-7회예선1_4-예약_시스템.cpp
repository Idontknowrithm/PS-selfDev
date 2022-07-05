// 알고리즘은 그리디 + 조건분기 느낌이었다. 스트레스가 생기는 고객은
// 각 그룹에 최대 4명이다. 그룹을 묶을 때 최소가 가능한 모양은
// a b c
// d e f
// -> 이때 스트레스 = a + c + d + f

// a b c
//   d e f
// -> 이때 스트레스 = 2a + c + d + 2f
  
// a b c
// d e
// -> 이때 스트레스 = a + 2c + d + e

// 이렇게 되는데 호텔의 양쪽 끝에는 벽이 있으므로 두 그룹에서 두 명씩
// 스트레스를 없앨 수 있다

// 먼저 각 그룹에서 가장 작은 4개의 값을 뽑아내서 테이블(t)을 만들고, 그
// 테이블으로만 계산한다. 부분점수만 받으려면(각 그룹이 홀수만 혹은 짝수만)
// t에서 세번째 네번째 값을 더한 값이 가장 큰 두 그룹을 양 사이드로 붙이고
// 계산하면 끝
// 홀짝이 함께인 경우에는 밀린 짝수 형태를 생각해야한다. 생각해보면
// 짝수 그룹의 수는 상관이 없고
// 1. 홀수의 그룹이 두 개일때
//    * * a a a b b * * * * * *
//    * * a a b b b * * * * * *
//    -> 홀수끼리 붙어있으면 문제 없다
   
//    * * a a a * * * b b * * *
//    * * a a * * * b b b * * *
//    -> 떨어져있으면서 중간에 있을 때는 그냥 홀수끼리 붙여서
//       스트레스를 최소화할 수 있다
      
//    a a a * * * * * * * * b b
//    a a * * * * * * * * b b b
//    -> a와 b에 충분히 큰 값이 3개 있다면 떨어져있으면서 양 사이드에 있는
//       경우를 생각해봐야한다.
  
// 2. 홀수의 그룹이 네 개 이상일 때
//    -> 어떻게든 홀수끼리 붙이는 경우가 더 최적답이므로 밀린 짝수가 나올 수 없다

// 따라서 밀린 짝수가 나오는 경우는 홀수 그룹이 두 개일 때가 유일하므로, 이 경우를
// 따로 예외처리 해준다. 결론은

// 1. 홀수 그룹이 두개라면 홀수가 양 사이드에 있는 경우, 홀수가 한 쪽 사이드에 있는
//    경우, 홀수가 사이드에 없는 경우를 계산한다
// 2. 나머지는 t의 세번째 네번째 값을 더한 값이 가장 큰 두 그룹을 양 사이드로 붙여
//    계산한다

// 여기서 나는 밀린 짝수가 나오는 경우를 생각하지 못했다. 이 경우를 빼놓고 알고리즘을
// 설계하다가 마지막에 밀린 짝수가 나올 수 있다는 경우를 발견해서 알고리즘을 수정하려고
// 하니 내가 설계해둔 알고리즘에서 수정하여 그 경우를 통과시키기에는 너무 힘들 것 같아서
// 해답 아이디어를 보고 영감을 받아 AC를 받았다
// -> 경우를 나누어 생각할 떄 그냥 복잡해보인다고 그 경우를 배제하지 말고 여러 예시를
//    들어보면서 그 경우가 절대 안나올 것 같은 경우만 배제하도록 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
#define pp std::pair<ll, ll>

const ll MAX = 20005; // group
ll T, N, M, even, odd, spe_ans, ans, min4[MAX][10];

std::vector<pp> max_in_min;
std::vector<ll> group[MAX];

int main() {
    scanf("%lld", &T);
    for(ll z = 1; z <= T; ++z){
        spe_ans = 1e13;
        even = 0; odd = 0;
        max_in_min.clear();
        for(ll i = 0; i < MAX; ++i)
            group[i].clear();

        scanf("%lld %lld", &N, &M); // group, booker
        for(ll i = 0; i < N; ++i){
            ll gsize;

            scanf("%lld", &gsize);
            (gsize & 1) ? (++odd) : (++even);
            for(ll u = 0; u < gsize; ++u){
                ll input;

                scanf("%lld", &input);
                group[i].push_back(input);
            }
            std::sort(group[i].begin(), group[i].end());

            for(ll u = 0; u < 4; ++u)
                min4[i][u] = group[i][u];
        }

        if(odd == 2 && even){
            std::vector<pp> exO, exE;
            ll idx1, idx2;

            // exception
            spe_ans = 0;
            for(ll i = 0; i < N; ++i){
                if(group[i].size() & 1)
                    spe_ans += min4[i][0] * 2 + min4[i][1];
                else 
                    spe_ans += min4[i][0] * 2 + min4[i][1] * 2 +
                               min4[i][2] + min4[i][3];
            }
            // exception

            for(ll i = 0; i < N; ++i){
                if(group[i].size() & 1)
                    exO.push_back({min4[i][2] + min4[i][3], i});
                else
                    exE.push_back({min4[i][2] + min4[i][3], i});
            }
            std::sort(exE.begin(), exE.end());
            std::sort(exO.begin(), exO.end());

            if(even == 1){
                idx1 = exO[exO.size() - 1].second;
                idx2 = exE[exE.size() - 1].second;
            }
            else{
                idx1 = exE[exE.size() - 1].second;
                if(exE[exE.size() - 2].first > exO[exO.size() - 1].first)
                    idx2 = exE[exE.size() - 2].second;
                else
                    idx2 = exO[exO.size() - 1].second;
            }
            min4[idx1][2] = min4[idx1][3] = min4[idx2][2] = min4[idx2][3] = 0;
        }
        else{
            for(ll i = 0; i < N; ++i)
                max_in_min.push_back({min4[i][2] + min4[i][3], i});
            
            std::sort(max_in_min.begin(), max_in_min.end());
            
            ll max1 = max_in_min[max_in_min.size() - 1].second;
            ll max2 = max_in_min[max_in_min.size() - 2].second;
            
            min4[max1][2] = min4[max1][3] = min4[max2][2] = min4[max2][3] = 0;
        }

        ans = 0;

        for(ll i = 0; i < N; ++i){
            if(group[i].size() & 1)
                ans += min4[i][0] * 2 + min4[i][1] + min4[i][2] + min4[i][3];
            else 
                ans += min4[i][0] + min4[i][1] + min4[i][2] + min4[i][3];
        }

        ans = std::min(ans, spe_ans);
        printf("Case #%lld\n%lld\n", z, ans);
    }
    return 0;
}
