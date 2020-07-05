// timeout && wrong

#include<iostream>

int zeroOfFac(int n){
	int numOfTwo = 0, numOfFive = 0;
	
	for(int index = 2; index <= n; index <<= 1)
		for(int i = 1; i * index <= n; ++i)
			++numOfTwo;
	for(int index = 5; index <= n; index *= 5)
		for(int i = 1; i * index <= n; ++i)
			++numOfFive;
	return (numOfFive < numOfTwo) ? numOfFive : numOfTwo;
}

int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", zeroOfFac(n) - zeroOfFac(m) - zeroOfFac(n - m));
	return 0;
}
