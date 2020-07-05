#include<iostream>
#include<queue>

std::priority_queue<int> maxHeap;

int main () {
	int N, inp;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &inp);
		if(!inp && maxHeap.empty())
			printf("0\n");
		else if(!inp && !maxHeap.empty()){
			printf("%d\n", maxHeap.top());
			maxHeap.pop();
		}
		else 
			maxHeap.push(inp);
	}
	return 0;
}
