#include<iostream>
#include<vector>
#include<algorithm>

int cache[101][101]; // W - S
std::string W, str;

int match(int w, int s){
	int& ref = cache[w][s];
	if(ref != -1) return ref;

	while(s < str.size() && w < W.size() && (W[w] == '?' || W[w] == str[s])){
		++s; ++w;
	}
	if(w == W.size())
		return ref = (s == str.size());
	if(W[w] == '*'){
		for(int skip = 0; s + skip <= str.size(); ++skip)
			if(match(w + 1, s + skip))
				return ref = 1;
	}
	return ref = 0;
}

int main () {
	int T, t;
	std::vector<std::string> comp;
	std::cin >> T;
	while(T--){
		std::cin >> W;
		std::cin >> t;
		for(int i = 0; i < t; ++i){
			for(int y = 0; y < 101; ++y)
			for(int u = 0; u < 101; ++u)
				cache[y][u] = -1;
			std::cin >> str;
			if(match(0, 0)){
				comp.push_back(str);
			}
		}
		std::sort(comp.begin(), comp.end());
		for(int i = 0; i < comp.size(); ++i)
			std::cout << comp[i] << "\n";
		comp.clear();
	}
	return 0;
}
