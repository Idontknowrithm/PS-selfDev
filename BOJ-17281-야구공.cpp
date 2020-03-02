#include<iostream>
#include<algorithm>

int out, ability[50][9], base[3];

int advance(int num){
	int score = 0;
	switch(num){
		case 1:
			score += base[2];
			base[2] = base[1];
			base[1] = base[0];
			base[0] = 1;
			break;
		case 2:
			score += base[2] + base[1];
			base[2] = base[0];
			base[1] = 1;
			base[0] = 0;
			break;
		case 3:
			score += base[2] + base[1] + base[0];
			base[0] = base[1] = base[2] = 0;
			++base[2];
			break;
		case 4:
			score += base[0] + base[1] + base[2] + 1;
			base[0] = base[1] = base[2] = 0;
			break;
		default:
			++out;
			break;
	}
	return score;
}

int main () {
	int tempScore, index, inning, score = 0, queue[9], combTable[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	scanf("%d", &inning);
	for(int i = 0; i < inning; ++i)
	for(int u = 0; u < 9; ++u)
		scanf("%d", &ability[i][u]);
	do{
		queue[3] = 0;
		for(int i = 0; i < 3; ++i)
			queue[i] = combTable[i];
		for(int i = 4; i < 9; ++i)
			queue[i] = combTable[i - 1];
		tempScore = index = 0;
		for(int i = 0; i < inning; ++i){
			out = 0;
			base[0] = base[1] = base[2] = 0;
			while(out != 3){
				tempScore += advance(ability[i][queue[index % 9]]);
				++index;
			}
		}
		score = (tempScore > score) ? tempScore : score;
	}while(std::next_permutation(combTable, combTable + 8));

	printf("%d", score);
	return 0;
}
