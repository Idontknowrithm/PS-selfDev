#include<iostream>

int max, LCStable[1001][1001];
std::string s1, s2;
int main () {
	std::cin >> s1 >> s2;
	for(int i = 1; i <= s1.size(); ++i)
	for(int u = 1; u <= s2.size(); ++u)
		LCStable[i][u] = (s1[i - 1] == s2[u - 1]) ? LCStable[i - 1][u - 1] + 1 : (LCStable[i - 1][u]  > LCStable[i][u - 1]) ? LCStable[i - 1][u] : LCStable[i][u - 1];
		
	for(int i = 1; i <= s1.size(); ++i)
	for(int u = 1; u <= s2.size(); ++u)
		max = (LCStable[i][u] > max) ? LCStable[i][u] : max;
	
	std::cout << max;

	return 0;
}
