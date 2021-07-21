// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<map>
// // justice hui's code

// struct Node{
//     // 한 글자를 담고, 다음 노드를 가리키는 노드 대신
//     // 한 단어를 담고, 다음 노드를 가리키는 노드를 생성
// 	std::map<std::string, Node> child;
// }root;

// // v를 루트로 하는 노드에다가 한 줄로 받은 문자열 배열인 arr을 넣기
// // idx는 arr 중에서 몇 개의 문자열을 넣었는 지에 대한 정보
// void insert(Node &v, std::vector<std::string> &arr, int idx){
//     // 다 넣었으면 끝내기
// 	if(idx == arr.size()) return;

//     // 현 노드에 해당 idx의 문자열이 없다면 그 문자열에 해당하는 노드를 만들기
// 	if(!v.child.count(arr[idx])) v.child[arr[idx]] = Node();
//     // 해당 문자열이 있다면 그 문자열에 해당하는 노드 밑으로 가서 insert 재귀
// 	insert(v.child[arr[idx]], arr, idx+1);
// }

// // v 노드를 루트로 하는 트리에 dfs 탐색. dep은 트리의 깊이를 의미
// void dfs(Node &v, int dep = 0){
//     // v 루트 바로 아래에 있는 노드들에 대해 탐색
// 	for(auto i : v.child){
//         // dep 별로 -- 길이를 달리 해야하기 때문에
// 		for(int j=0; j<dep; j++) std::cout << "--";
// 		std::cout << i.first << "\n";
//         // dfs로 재귀 돌리기
// 		dfs(i.second, dep+1);
// 	}
// }

// int main(){
// 	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
// 	int t; std::cin >> t;
// 	while(t--){
// 		int n; std::cin >> n;
// 		std::vector<std::string> v(n);
// 		for(int i=0; i<n; i++) std::cin >> v[i];
// 		insert(root, v, 0);
// 	}
// 	dfs(root);
// }

#include<iostream>
#include<vector>
#include<map>

struct node{
    std::map<std::string, node> child;
};

int T, N;
node root;
std::vector<std::string> input;

void insert(node &root, std::vector<std::string>& ant, int idx){
    if(ant.size() == idx) return;

    if(!root.child.count(ant[idx]))
        root.child[ant[idx]] = node();
    insert(root.child[ant[idx]], ant, idx + 1);
}
void dfs(node &root, int depth){
    for(auto i : root.child){
        for(int u = 0; u < depth; ++u)
            std::cout << "--";
        std::cout << i.first << "\n";
        dfs(i.second, depth + 1);
    }


    
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for(std::cin >> T; T > 0; --T){
        std::cin >> N;
        for(int i = 0; i < N; ++i){
            std::string tmp;
            std::cin >> tmp;
            input.push_back(tmp);
        }
        insert(root, input, 0);
        input.clear();
    }
    dfs(root, 0);
    return 0;
}
