// 갱신되는 구간 합을 간단히 구할 수 있음

#include<iostream>
#include<vector>
#define ll long long
typedef ll unit;

class fenwick{
    std::vector<unit> tree;
    public:
        fenwick(unit N) : tree(N + 5){}

        unit sum(unit idx){
            unit ret = 0;
            while(idx > 0){
                ret += tree[idx];
                idx &= (idx - 1); // delete a last bit
            }
            return ret;
        }
        void add(unit idx, unit val){
            while(idx < tree.size()){
                tree[idx] += val;
                idx += (idx & -idx); // extracting a last bit
            }
        }
        void renew(const unit idx, unit val){
            unit idx_cache = idx;
            unit val_cache = seq[idx];

            while(idx_cache < tree.size()){
                tree[idx_cache] -= val_cache;
                idx_cache += (idx_cache & -idx_cache);
            }
            seq[idx] = val;
            idx_cache = idx;
            while(idx_cache < tree.size()){
                tree[idx_cache] += val;
                idx_cache += (idx_cache & -idx_cache);
            }
        }
};
