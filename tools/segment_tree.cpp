// 세그트리 중에서도 range minimum query(RMQ) 구현
// 구간 안에서 가장 최소값을 파악 

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

typedef int unit;

const unit unit_max = std::numeric_limits<unit>::max();

class segment_tree{
    unit N;
    std::vector<unit> seq;
    public:
        segment_tree(const std::vector<unit> &arr){
            N = arr.size();
            seq.resize(N << 2);
            init(arr, 0, N - 1, 1);
        }
        unit init(const std::vector<unit> &arr, unit left, unit right, unit root){
            if(left == right)
                return seq[root] = arr[left];
            unit mid = (left + right) / 2;
            unit left_min = init(arr, left, mid, root * 2);
            unit right_min = init(arr, mid + 1, right, root * 2 + 1);
            return seq[root] = std::min(left_min, right_min);
        }
        unit query(unit left, unit right, unit root, unit this_left, unit this_right){
            if(right < this_left || this_right < left)
                return unit_max;
            if(left <= this_left && this_right <= right)
                return seq[root];
            
            unit mid = (this_left + this_right) / 2;
            return std::min(query(left, right, root * 2, this_left, mid),
                            query(left, right, root * 2 + 1, mid + 1, this_right));
        }
}
