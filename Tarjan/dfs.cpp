#define STACK_MAX 5000000 * 5

#include "../common.h"

#include "tarjan_common.h"

#include <algorithm>

using namespace std;

int S[MaxN], dfn[MaxN], low[MaxN], cnt, top;
bool InStack[MaxN];
int colors, color[MaxN];
void tarjan(int u){
	dfn[u] = low[u] = ++cnt;
	InStack[u] = true;
	S[top++] = u;
	for (edge *e = P[u]; e != NULL; e = e->next){
		int &v = e->v;
		if (dfn[v] == 0){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (InStack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]){
		++colors;
		do{
			int j = S[--top];
			color[j] = colors;
			InStack[j] = false;
			if (j == u) break;
		} while(1);
	}
}

int main(){
	_STACK_BEGIN
	Init();
	START_TIME
	tarjan(0);
	END_TIME
	exit(0);
	_STACK_END
}