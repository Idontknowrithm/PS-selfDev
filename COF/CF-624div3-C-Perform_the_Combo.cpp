#include<iostream>
#include<cstring>
#include<algorithm>

int n, m, mistake[200000], nested[200000], ans[26];
char str[200001];

int main () {
	int T;
	scanf("%d\n", &T);
	while(T--){
		scanf("%d %d\n%s", &n, &m, str);
		for(int i = 0; i < m; ++i)
			scanf("%d", &mistake[i]);
		for(int i = 0; i < 26; ++i)
			ans[i] = 0;
		for(int i = 0; i < 200000; ++i)
			nested[i] = 0;
		std::sort(mistake, mistake + m);
		for(int i = 0; i < mistake[0]; ++i)
			nested[i] = m;
		for(int i = 1; i < m; ++i){
			if(mistake[i - 1] != mistake[i]){
				for(int u = mistake[i - 1]; u < mistake[i]; ++u)
					nested[u] = m - i;
			}
		}
		for(int i = 0; i < n; ++i){
			ans[str[i] - 'a'] += nested[i] + 1;
		}
		for(int i = 0; i < 26; ++i)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}
