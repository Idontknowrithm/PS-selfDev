#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
 
bool isPalin(std::string str){
	for(int i = 0; i < str.size() / 2; ++i)
		if(str[i] != str[str.size() - i - 1])
			return false;
	return true;
}
 
int main () {
	int N, M, len = 0;
	std::deque<std::string> ans;
	std::vector<std::string> palinData;
	std::string arr[105], Rstr;
	std::cin >> N >> M;
	for(int i = 0; i < N; ++i)
		std::cin >> arr[i];
	for(int i = 0; i < N; ++i){
		Rstr = arr[i];
		std::reverse(Rstr.begin(), Rstr.end());
		for(int j = i + 1; j < N; ++j)
			if(Rstr == arr[j]){
				palinData.push_back(arr[j]);
				len += arr[j].size() * 2;
			}
	}
	for(int i = 0; i < N; ++i)
		if(isPalin(arr[i])){
			ans.push_back(arr[i]);
			len += arr[i].size();
			break;
		}
	for(int i = 0; i < palinData.size(); ++i){
		Rstr = palinData[i];
		std::reverse(Rstr.begin(), Rstr.end());
		ans.push_back(Rstr);
		ans.push_front(palinData[i]);
	}
	std::cout << len << "\n";
	while(!ans.empty()){
		std::cout << ans.front();
		ans.pop_front();
	}
	return 0;
}
