#include<iostream>

typedef long long ll;

ll A, B, C;

ll power(ll a, ll b, ll c){
	ll temp;
	if(b == 0)
		return 1;
	else if(b == 1)
		return a % c;
	else if(b & 1)
		return (power(a, b - 1, c) * a) % c;
	temp = power(a, b / 2, c) % c;
	return (temp * temp) % c;
}

int main () {
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", power(A, B, C));		
}
