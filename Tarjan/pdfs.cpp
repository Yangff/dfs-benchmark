#define STACK_MAX 5000000 * 5

#include "../common.h"

#include "tarjan_common.h"

#include <algorithm>
#include <cassert>

using namespace std;

int S[MaxN], dfn[MaxN], low[MaxN], cnt, top;
bool InStack[MaxN];
int colors, color[MaxN];

struct Stack_Node{
	int u; edge *e; int S;
} Stk[MaxN + 10];

void tarjan(int x){
	int tail = 0;
	++tail;
	Stk[tail].u = x;
	Stk[tail].e = NULL;
	Stk[tail].S = 0;
	while (tail){
		bool flag = 0;
		int u = Stk[tail].u;
		edge* e = Stk[tail].e;
		#define v e->v
		switch (Stk[tail].S){
		case 0:
			dfn[u] = low[u] = ++cnt;
			InStack[u] = true;
			S[top++] = u;
			e = P[u];
			Stk[tail].S = 1;
			flag = 0;
			for (; e; e = e->next){
				if (dfn[v] == 0){
					Stk[tail].e = e;
					++tail;
					Stk[tail].u = v;
					Stk[tail].e = NULL;
					Stk[tail].S = 0;
				flag = true;
					break;
		case 1:
				flag = false;
					low[u] = min(low[v], low[u]);
				} else if (InStack[v]){
					low[u] = min(low[u], dfn[v]);
				}

			}
			if (flag) break;
			if (dfn[u] == low[u]){
				++colors;
				do {
					int j = S[--top];
					color[j] = colors;
					InStack[j] = false;
					if (j == u) break;
				} while(1);
			}
			tail--;
		}
	}
}
int main(){
	Init();
	START_TIME
	tarjan(0);
	END_TIME
}