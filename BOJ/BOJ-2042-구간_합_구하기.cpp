#include<iostream>
#include<vector>
#define ll long long

ll N, M, K;
std::vector<ll> seq;

class fenwick{
    std::vector<ll> tree;
    public:
        fenwick(ll N) : tree(N + 5){}

        ll sum(ll idx){
            ll ret = 0;
            while(idx > 0){
                ret += tree[idx];
                idx &= (idx - 1); // delete a last bit
            }
            return ret;
        }
        void add(ll idx, ll val){
            while(idx < tree.size()){
                tree[idx] += val;
                idx += (idx & -idx); // extracting a last bit
            }
        }
        void renew(const ll idx, ll val){
            ll idx_cache = idx;
            ll val_cache = seq[idx];

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

int main() {
    ll input, query, qb, qc;
    scanf("%lld %lld %lld", &N, &M, &K);
    fenwick fentree(N);
    seq.push_back(0);
    for(ll i = 1; i <= N; ++i){
        scanf("%lld", &input);
        seq.push_back(input);
        fentree.add(i, input);
    }
    for(ll i = 0; i < M + K; ++i){
        scanf("%lld", &query);
        if(query == 1){
            scanf("%lld %lld", &qb, &qc);
            fentree.renew(qb, qc);
        }
        else if(query == 2){
            scanf("%lld %lld", &qb, &qc);
            ll ans = fentree.sum(qc) - fentree.sum(qb - 1);
            // printf("%lld %lld\n", fentree.sum(qc), fentree.sum(qb - 1));
            printf("%lld\n", ans);
        }
    }
    return 0;
}
