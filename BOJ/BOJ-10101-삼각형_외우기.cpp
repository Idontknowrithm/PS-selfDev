#include<iostream>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c && a == 60)
        printf("Equilateral");
    else if(a + b + c == 180 && 
            (a == b || b == c || a == c))
        printf("Isosceles");
    else if(a + b + c == 180)
        printf("Scalene");
    else 
        printf("Error");
    return 0;
}
