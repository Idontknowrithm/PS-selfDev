#include<iostream>
#include<math.h>
#include<algorithm>

int arr[200];

int main(){
    int T, N, inp, one, two;
    
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        one = two = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", &inp);
            (inp == 1) ? ++one : ++two;
        }
        if(one % 2 == 1)
            printf("NO\n");
        else if(one > 1 && two % 2 == 1)
            printf("Yes\n");
        else if(two % 2 == 1)
            printf("NO\n");
        else 
            printf("YES\n");
    }
    return 0;
}
