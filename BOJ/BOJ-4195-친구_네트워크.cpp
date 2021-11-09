// 맵 써서 인풋 처리하는 것까지 생각했는데
// 유니온 셋 합집합 크기 재는 걸 처음 봤음

#include<iostream>
#include<set>
#include<map>

const int MAX = 200005;
int T, F, uni_set[MAX], set_size[MAX];
std::set<std::string> names;
std::map<std::string, int> name_to_int;

int find_set(int num){
    if (uni_set[num]==num)
        return num;
    int parent = find_set(uni_set[num]);
    uni_set[num] = parent;
    return parent;
}
void union_set(int first, int second){
    if(first == second) return;

    if(set_size[first] < set_size[second])
        std::swap(first, second);

    uni_set[second] = first;
    set_size[first] += set_size[second];
    set_size[second] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(std::cin >> T; T > 0; --T){
        int uni_set_idx = 0;
        names.clear();
        name_to_int.clear();
        for(int i = 0; i < MAX; ++i){
            uni_set[i] = i;
            set_size[i] = 1;
        }
        std::cin >> F;
        for(int i = 0; i < F; ++i){
            std::string user1, user2;
            std::cin >> user1 >> user2;
            if(names.find(user1) == names.end())
                name_to_int.insert({user1, uni_set_idx++});
            if(names.find(user2) == names.end())
                name_to_int.insert({user2, uni_set_idx++});
            int userint1 = name_to_int[user1], userint2 = name_to_int[user2]; 
            union_set(find_set(userint1), find_set(userint2));

            std::cout << std::max(set_size[find_set(userint1)], set_size[find_set(userint2)]) << "\n";
        }
    }
    return 0;
}
