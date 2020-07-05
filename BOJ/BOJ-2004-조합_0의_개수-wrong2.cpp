// runtime error && wrong

#include<iostream>

int zeroOfFac(int n){
	int numOfTwo = 0, numOfFive = 0;
	
	for(int i = 2; i <= n; i <<= 1)
		numOfTwo += n / i;
	for(int i = 5; i <= n; i *= 5)
		numOfFive += n / i;
	return (numOfFive < numOfTwo) ? numOfFive : numOfTwo;
}

int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", zeroOfFac(n) - zeroOfFac(m) - zeroOfFac(n - m));
	return 0;
}
