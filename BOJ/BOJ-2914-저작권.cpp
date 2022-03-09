#include<iostream>
#include<cmath>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    for(int i = 1;; ++i){
        double tmp = std::ceil((double)i / a);
        
        if((int)tmp == b){
            printf("%d", i);
            return 0;
        }
    }
}
