#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

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
        unit query(unit left, unit right){
            return query(left, right, 1, 1, N);
        }
        unit update(unit idx, unit new_val, unit root, unit this_left, unit this_right){
            if(idx < this_left || this_right < idx)
                return seq[root];
            if(this_left == this_right)
                return seq[root] = new_val;
            
            unit mid = (this_left + this_right) / 2;
            return seq[root] = std::min(update(idx, new_val, root * 2, this_left, mid), 
                                        update(idx, new_val, root * 2 + 1, mid + 1, this_right));
        }
        unit update(unit idx, unit new_val){
            return update(idx, new_val, 1, 1, N);
        }
};

int N, M, visited[40005];
std::vector<pp> graph[40005], tree;
std::vector<int> seg_input;

void treeing(int start, int val_sum){
    tree.push_back({start, val_sum});
    visited[start] = 1;
    for(int i = 0; i < graph[start].size(); ++i){
        if(!visited[graph[start][i].first]){
            treeing(graph[start][i].first, val_sum + graph[start][i].second);
            tree.push_back({start, val_sum});
        }
    }   
}

int main() {
    int a, b, val;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        scanf("%d %d %d", &a, &b, &val);
        graph[a].push_back({b, val});
        graph[b].push_back({a, val});
    }
    treeing(1, 0);

    for(int i = 0; i < tree.size(); ++i){
        seg_input.push_back(tree[i].second);
    }
    return 0;
}
