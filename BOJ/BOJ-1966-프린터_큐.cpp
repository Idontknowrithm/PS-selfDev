#include<iostream>
#include<vector>

typedef struct{
	int importance;
	int name;
}document;

int main () {
	int T, N, M, count;
	bool priority;
	std::vector<document> printer;
	document temp;
	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; ++i){
			temp.name = i;
			scanf("%d", &temp.importance);
			printer.push_back(temp);
		}
		count = 0;
		while(printer.size() != 0){
			priority = true;
			for(int i = 1; i < printer.size(); ++i)
				priority = (printer[0].importance < printer[i].importance) ? false : priority;
			if(priority && printer[0].name == M){
				++count;
				break;
			}
			else if(priority){
				printer.erase(printer.begin());
				++count;
			}
			else{
				printer.push_back(printer[0]);
				printer.erase(printer.begin());
			}
		}
		printf("%d\n", count);
		printer.clear();
	}
	return 0;
}
