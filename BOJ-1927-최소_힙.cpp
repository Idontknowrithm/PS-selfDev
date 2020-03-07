#include<iostream>
#include<queue>

int main () {
	int N, inp;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &inp);
		if(inp)
			minHeap.push(inp);
		else if(!inp && minHeap.empty())
			printf("0\n");
		else {
			printf("%d\n", minHeap.top());
			minHeap.pop();
		}
	}
	return 0;
}
