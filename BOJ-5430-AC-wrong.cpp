// timeout

#include<iostream>
#include<deque>
#include<cstring>

std::deque<int> data;

int main () {
	int T, index, size;
	char query[100001];
	bool reverse, error;
	scanf("%d", &T);
	getchar();
	while(T--){
		scanf("%s\n%d", query, &size);
		while(getchar() != '[');
		for(int i = 0; i < size; ++i){
			scanf("%d", &index);
			data.push_back(index);
			getchar();
		}
		reverse = false; error = false;
		for(int i = 0; i < strlen(query); ++i){
			if(query[i] == 'R')
				reverse = (reverse) ? false : true;
			else if(query[i] == 'D' && data.empty()){
				error = true;
				break;
			}
			else if(query[i] == 'D' && !reverse)
				data.pop_front();
			else if(query[i] == 'D' && reverse)
				data.pop_back();
		}
		getchar();

		if(error)
			printf("error\n");
		else if(!error && data.empty())
			printf("[]\n");
		else if(!error && !reverse){
			printf("[%d", data.front());
			data.pop_front();
			while(!data.empty()){
				printf(",%d", data.front());
				data.pop_front();
			}
			printf("]\n");
		}
		else if(!error && reverse){
			printf("[%d", data.back());
			data.pop_back();
			while(!data.empty()){
				printf(",%d", data.back());
				data.pop_back();
			}
			printf("]\n");
		}
		data.clear();
	}
	return 0;
}
