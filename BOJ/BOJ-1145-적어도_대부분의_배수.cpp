#include<iostream>
#include<algorithm>

int arr[10], comb[10] = {1, 1, 1, 0, 0};

int GCM(){
    int ptr = 0, three[3];
    for(int i = 0; i < 5; ++i)
        if(comb[i]) three[ptr++] = arr[i];
    ptr = 1;
    while(1){
        if(ptr % three[0] == 0 &&
           ptr % three[1] == 0 &&
           ptr % three[2] == 0)
           return ptr;
        ++ptr;
    }
}

int main() {
    for(int i = 0; i < 5; ++i)
        scanf("%d", &arr[i]);
    int min = 2147483647;
    do{
        min = std::min(min, GCM());
    }while(std::prev_permutation(comb, comb + 5));
    printf("%d", min);
    return 0;
}
