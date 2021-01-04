#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

int main() {
    int T, input;
    char numstr[20], strptr;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &input);
        if(input > 45){
            printf("-1\n");
            continue;
        }
        strptr = 0;
        for(int i = 9; i > 0; --i){
            if(input > i){
                numstr[strptr++] = '0' + i;
                input -= i;
            }
            else{
                numstr[strptr++] = '0' + input;
                break;
            }
        }
        std::sort(numstr, numstr + strptr);
        for(int i = 0; i < strptr; ++i)
            printf("%c", numstr[i]);
        puts("");
    }
    return 0;
}
