// 문제 데이터 제한을 넘지 않는 선에서는 효율적인 방법을 찾기보다
// 어떻게든 빠르게 처리할 생각을 해보기
// ex) 이 문제에서는 nC2가 필요했으나 이를 직접 구현할 필요 없이
//     이중 for문으로 빠르게 끝낼 수 있었음

#include<iostream>
#include<set>
#include<algorithm>

int main() {
    int T, n, trees[55], comb[55];
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &n);
        for(int i = 0; i < 55; ++i)
            trees[i] = 0;
        for(int i = 0; i < n; ++i)
            scanf("%d", &trees[i]);
        if(n == 1){
            printf("0\n");
            continue;
        }
        std::set<int> width;
        for(int i = 0; i < 55; ++i)
            comb[i] = 0;
        comb[0] = comb[1] = 1;
        do{
            int diff, it;
            for(it = 0; it < n; ++it)
                if(comb[it] == 1){
                    diff = trees[it];
                    break;
                }
            ++it;
            for(; it < n; ++it)
                if(comb[it] == 1){
                    diff -= trees[it];
                    break;
                }   
            diff = (diff < 0) ? -diff : diff;
            width.insert(diff);
        }while(std::prev_permutation(comb, comb + n));

        printf("%d\n", width.size());
    }
    return 0;
}
