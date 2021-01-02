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
