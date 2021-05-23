// 문제 생기면 빠르게 print로 디버그 해볼 수밖에..

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#define ll long long
#define pp std::pair<unit, unit>

typedef ll unit;

const unit unit_max = std::numeric_limits<unit>::max();

unit N;
std::vector<pp> arr;

class segment_tree{
    unit N;
    std::vector<pp> seq;
    public:
        segment_tree(const std::vector<pp> &arr){
            N = arr.size() - 1;
            seq.resize(N * 4);
            base();
            init(arr, 1, N, 1);
        }
        void base(){
            for(int i = 0; i < N * 4; ++i)
                seq[i] = {i, unit_max};
        }
        pp init(const std::vector<pp> &arr, unit left, unit right, unit root){
            if(left == right){
              seq[root] = arr[left];
              return seq[root];
            }
            unit mid = (left + right) / 2;
            pp left_min = init(arr, left, mid, root * 2);
            pp right_min = init(arr, mid + 1, right, root * 2 + 1);
            if(left_min.second < right_min.second)
                seq[root] = left_min;
            else 
                seq[root] = right_min;
            return seq[root];
        }
        pp query(unit left, unit right, unit root, unit this_left, unit this_right){
            if(right < this_left || this_right < left)
                return {-1, unit_max};
            if(left <= this_left && this_right <= right)
                return seq[root];
            
            unit mid = (this_left + this_right) / 2;
            pp leftq = query(left, right, root * 2, this_left, mid);
            pp rightq = query(left, right, root * 2 + 1, mid + 1, this_right);
            if(leftq.second < rightq.second)
                return leftq;
            else 
                return rightq;
        }
        pp query(unit left, unit right){
            return query(left, right, 1, 1, N);
        }
};

unit DQ(segment_tree &st, pp divider, unit left, unit right){
    if(left > right) return 0;
    if(left == right) return divider.second;
    
    unit max = divider.second * (right - left + 1);
    pp left_div = st.query(left, divider.first - 1);
    max = std::max(max, DQ(st, left_div, left, divider.first - 1));
    pp right_div = st.query(divider.first + 1, right);
    max = std::max(max, DQ(st, right_div, divider.first + 1, right));
    return max;
}

int main() {
    while(1){
        unit input, ans = 0;
        scanf("%lld", &N);
        if(!N) return 0;
        arr.push_back({0, unit_max});
        for(unit i = 1; i <= N; ++i){
            scanf("%lld", &input);
            arr.push_back({i, input});
        }
        segment_tree segtree(arr);
        pp tmp = segtree.query(1, N);
        ans = DQ(segtree, tmp, 1, N);
        
        printf("%lld\n", ans);
        arr.clear();
    }
    return 0;
}
