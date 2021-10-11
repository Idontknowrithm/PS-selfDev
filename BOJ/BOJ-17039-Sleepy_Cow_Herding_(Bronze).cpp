#include<iostream>
#include<algorithm>

int a, b, c, mini = 1000000000, maxi = 0;

int main() {
    scanf("%d %d %d", &a, &b, &c);
    if(a > b) std::swap(a, b);
    if(b > c) std::swap(b, c);
    if(a > b) std::swap(a, b);
    // min
    if(b - a == 1 && c - b == 1){
        printf("0\n0");
        return 0;
    }
    
    if(b - a == 2 || c - b == 2)
        mini = 1;
    else
        mini = 2;
        
    int times = 0, t1 = a, t2 = b, t3 = c;
    while(t2 - t1 != 1 || t3 - t2 != 1){
        ++times;
        t1 = t3 - 1;
        std::swap(t1, t2);
        if(t1 == t2 || t2 == t3){
            times = 0;
            break;
        }
        if(t2 - t1 == 1 && t3 - t2 == 1)
            break;
        ++times;
        t3 = t1 + 1;
        std::swap(t2, t3);
        if(t1 == t2 || t2 == t3){
            times = 0;
            break;
        }
    }
    maxi = (maxi < times) ? times : maxi;
    t1 = a; t2 = b; t3 = c;
    times = 0;
    while(t2 - t1 != 1 || t3 - t2 != 1){
        ++times;
        t3 = t1 + 1;
        std::swap(t2, t3);
        if(t1 == t2 || t2 == t3){
            times = 0;
            break;
        }
        if(t2 - t1 == 1 && t3 - t2 == 1)
            break;
        ++times;
        t1 = t3 - 1;
        std::swap(t1, t2);
        if(t1 == t2 || t2 == t3){
            times = 0;
            break;
        }
    }
    maxi = (maxi < times) ? times : maxi;
    printf("%d\n%d", mini, maxi);
    return 0;    
}
