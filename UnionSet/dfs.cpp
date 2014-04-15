#define STACK_MAX 20000000 * 5

#include <common.h>

const int MaxN = 20000000;

int fa[MaxN];

int getFather(int x){
	if (fa[x] == x)
		return x;
	return fa[x] = getFather(fa[x]);
}

int main(){
	_STACK_BEGIN
	for (int i = 1; i < MaxN; i++)
		fa[i] = i - 1;
	fa[1] = 1;
	START_TIME
	getFather(MaxN - 1);
	END_TIME
	_STACK_END
}
