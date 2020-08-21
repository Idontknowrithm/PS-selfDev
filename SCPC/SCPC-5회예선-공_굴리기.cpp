#include<cstdio>
#include<cmath>

const double PI = 3.14159265358979;
int T, obs;

double S, E, R, obsTable[1005][3]; // l : r : h
int main () {
    scanf("%d", &T);

    for(int z = 0; z < T; ++z){
        scanf("%lf %lf %lf\n%d", &R, &S, &E, &obs);
        
        obsTable[0][2] = 1000000000;
        obsTable[0][1] = S - R;
        for(int i = 1; i <= obs; ++i){
                                 // l             // r             // h
            scanf("%lf %lf %lf", &obsTable[i][0], &obsTable[i][1], &obsTable[i][2]);
        }
        double ans = 0;
        for(int i = 1; i <= obs; ++i){
            double lastH = obsTable[i - 1][2], lastR = obsTable[i - 1][1];
            double l = obsTable[i][0], r = obsTable[i][1], h = obsTable[i][2];
            // ㅡ 길이 구하기 - a
            ans += l - lastR - R - R;
            if(h < R){
                ans += R - sqrt(R*R - (R-h)*(R-h));
            }
            if(lastH < R){
                ans += R - sqrt(R*R - (R-lastH)*(R-lastH));
            }

            // ㅣ 길이 2개 구하기 - b
            ans += (h > R) ? 2 * (h - R) : 0;

            // 굽이 2개 구하기 - c
            if(h >= R){
                ans += R * PI;
            }
            else{
                ans += 2 * R * acos((R - h) / R);
            }

            // 위에 ㅡ 구하기 - d
            ans += r - l;
        }
        ans += E - obsTable[obs][1] - R;
        if(obsTable[obs][2] < R){
            ans += R - sqrt(R*R - (R-obsTable[obs][2])*(R-obsTable[obs][2]));
        }
        printf("Case #%d\n%.8lf\n", z + 1, ans);
    }

    return 0;
}
