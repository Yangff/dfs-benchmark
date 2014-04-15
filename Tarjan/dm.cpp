// Author: Yangff
// it's not a perfect algorithm for generating a directed graph.
#include <set>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MaxN = 500000;
const int MaxE = 3500000;
const int CTL = 50;

set<int> G[MaxN];

int main(){
	srand(time(NULL));
	int n = MaxN, e = MaxE;
	for (int p = 0; p < CTL; p++){
		for (int i = p * (MaxN / CTL); i < (p + 1) * (MaxN / CTL) - 1; i++){
			e--;
			G[i].insert(i + 1);
		}
	}
	while (e){
		int u = rand() % MaxN, v = rand() % MaxN;
		if (G[u].find(v) == G[u].end()){
			G[u].insert(v);
			e--;
		}
	}

	FILE *f = fopen("in", "w");

	fprintf(f, "%d %d\n", n, MaxE);

	for (int i = 0; i < MaxN; i++){
		for (set<int>::iterator it = G[i].begin(); it != G[i].end(); it++){
			fprintf(f, "%d %d\n", i, *it);
		}
	}

	fclose(f);

}
