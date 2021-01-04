#include<iostream>
#include<cstring>
 
int main(){
    int T, N;
    char str[205];
    for(scanf("%d\n", &T); T > 0; --T){
        bool possible = false;
        scanf("%d\n", &N);
        scanf("%s", str);
        getchar();
        
        if((str[0] == '2' && str[1] == '0' && str[2] == '2' && str[3] == '0') ||
           (str[N - 1] == '0' && str[N - 2] == '2' && str[N - 3] == '0' && str[N - 4] == '2') ||
           (str[0] == '2' && str[N - 1] == '0' && str[N - 2] == '2' && str[N - 3] == '0') ||
           (str[0] == '2' && str[1] == '0' && str[N - 1] == '0' && str[N - 2] == '2') ||
           (str[0] == '2' && str[1] == '0' && str[2] == '2' && str[N - 1] == '0'))
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
