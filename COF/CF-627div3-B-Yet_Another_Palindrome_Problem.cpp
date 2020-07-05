#include<iostream>
#include<vector>
#include<algorithm>

int main () {
	bool check;
	int size, T, arr[5000];
	std::vector<int> position[5001];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &size);
		for(int i = 0; i < size; ++i){
			scanf("%d", &arr[i]);
			position[arr[i]].push_back(i);
		}
		check = false;
		for(int i = 0; i < size; ++i){
			if(position[i].size() > 2){
				printf("YES\n");
				check = true;
				break;
			}
			else if(position[i].size() == 2 && position[i][1] - position[i][0] != 1){
				printf("YES\n");
				check = true;
				break;
			}
		}
		if(!check)
			printf("NO\n");

		for(int i = 0; i < size; ++i)
			position[i].clear();
	}
	return 0;
}
