#include<iostream>
#include<algorithm>

typedef struct{
	std::string address, password;
}pair;

int N, M;
pair data[100000];

bool compare(pair a, pair b){
	return a.address < b.address;
}
std::string search(std::string find){
	int mid, start = 0, end = N - 1;
	while(start <= end){
		mid = (start + end) / 2;
		if(data[mid].address == find)
			return data[mid].password;
		else if(data[mid].address > find)
			end = mid - 1;
		else 	
			start = mid + 1;
	}
}
int main () {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string find;

	std::cin >> N >> M;
	for(int i = 0; i < N; ++i)
		std::cin >> data[i].address >> data[i].password;
	std::sort(data, data + N, compare);
	for(int i = 0; i < M; ++i){
		std::cin >> find;
		std::cout << search(find) << "\n";
	}
	return 0;
}
