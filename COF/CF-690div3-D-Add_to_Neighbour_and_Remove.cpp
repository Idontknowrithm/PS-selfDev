#include<iostream>
#include<vector>

int main(){
    int T, N, total, arr[3005];
    std::vector<int> divisor;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        total = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        bool eq = true;
        for(int i = 1; i < N; ++i)
            eq = (arr[i] == arr[0]) ? eq : false;
        if(eq == true){
            printf("0\n");
            continue;
        }
        divisor.clear();
        for(int i = 2; i <= total / 2; ++i)
            if(total % i == 0)
                divisor.push_back(i);
        divisor.push_back(total);
        
        for(int i = 0; i < divisor.size(); ++i){
            int tempsum = 0, mini = 0;
            if(total / divisor[i] < N){
                for(int u = 0; u < N; ++u){
                    tempsum += arr[u];
                    if(tempsum == divisor[i]){
                        ++mini;
                        tempsum = 0;
                    }
                    else if(tempsum > divisor[i])
                        break;
                }
                if(tempsum != 0) continue;
                else{
                    printf("%d\n", N - mini);
                    break;
                }
            }
        }
    }
    return 0;
}
