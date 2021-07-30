#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

typedef int unit;

const unit unit_max = 2147483647;

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
};

const int MAX = 100005;
int N, M, this_idx, visited[MAX];
int real2vir[MAX], vir2real[MAX], first_idx[MAX];
std::vector<int> seg_input, tree, graph[MAX];

void treeing(int start){
    int tmp = ++this_idx;
    tree.push_back(tmp);
    if(!real2vir[start]){
        real2vir[start] = tmp;
        vir2real[tmp] = start;
    }
    visited[start] = 1;
    for(int i = 0; i < graph[start].size(); ++i){
        if(!visited[graph[start][i]]){
            treeing(graph[start][i]);
            tree.push_back(tmp);
        }
    }   
}

int main() {
    int a, b, val;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    treeing(1);

    memset(first_idx, -1, sizeof(first_idx));
    for(int i = 0; i < tree.size(); ++i){
        if(first_idx[tree[i]] == -1)
            first_idx[tree[i]] = i;
    }
    segment_tree RMQ(tree);

    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &a, &b);
        if(a == b){
            printf("%d\n", a);
            continue;
        }
        int tmpa = first_idx[real2vir[a]], tmpb = first_idx[real2vir[b]];
        if(tmpa > tmpb) std::swap(tmpa, tmpb);
        printf("%d\n", vir2real[RMQ.query(++tmpa, ++tmpb)]);
    }
    return 0;
}
