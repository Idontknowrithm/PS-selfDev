#include<iostream>
#include<cstring>

int main () {
	int T, front, back, size, data[100000];
	char query[100001];
	bool reverse, error;
	scanf("%d", &T);
	getchar();
	while(T--){
		scanf("%s\n%d", query, &size);
		while(getchar() != '[');
		for(int i = 0; i < size; ++i){
			scanf("%d", &data[i]);
			getchar();
		}
		getchar();
		front = 0; back = size - 1;
		reverse = false; error = false;
		for(int i = 0; i < strlen(query); ++i){
			if(query[i] == 'R')
				reverse = (reverse) ? false : true;
			else if(query[i] == 'D' && front > back){
				error = true;
				break;
			}
			else if(query[i] == 'D' && !reverse)
				++front;
			else if(query[i] == 'D' && reverse)
				--back;
		}

		if(error)
			printf("error\n");
		else if(!error && front > back)
			printf("[]\n");
		else if(!error && !reverse){
			printf("[%d", data[front++]);
			for(int i = front; i <= back; ++i)
				printf(",%d", data[i]);
			printf("]\n");
		}
		else if(!error && reverse){
			printf("[%d", data[back--]);
			for(int i = back; i >= front; --i)
				printf(",%d", data[i]);
			printf("]\n");
		}
	}
	return 0;
}
