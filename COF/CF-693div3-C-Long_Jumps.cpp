#include<iostream>

int arr[200005], temp[200005];
int main(){
    int T, N, inp;
    
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            arr[i] = temp[i] = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", &arr[i]);
            temp[i] = arr[i];
        }
        for(int i = 0; i < N; ++i){
            if(i + arr[i] < N){
                temp[i + arr[i]] = (temp[i + arr[i]] < temp[i] + arr[i + arr[i]]) ? temp[i] + arr[i + arr[i]] : temp[i + arr[i]];
            }
        }
        int max = -1;
        for(int i = 0; i < N; ++i){
            max = (temp[i] > max) ? temp[i] : max;
        }
        printf("%d\n", max);
    }
    return 0;
}
