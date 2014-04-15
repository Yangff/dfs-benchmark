#include "../common.h"
const int MaxN = 20000000;
int fa[MaxN];
int S[MaxN];

int getFather(int x){
	int tail = 0;
	for (; fa[x] != x; x = fa[x])
		S[tail++] = x;
	while (tail--){
		fa[S[tail]] = x;
	}
	return x;
}

int main(){
	for (int i = 1; i < MaxN; i++)
		fa[i] = i - 1;
	fa[1] = 1;
	START_TIME
	getFather(MaxN - 1);
	END_TIME
}
