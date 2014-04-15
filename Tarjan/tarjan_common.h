const int MaxN = 500000, MaxE = 3500000;
int n, m;
struct edge{
	int v; edge* next;
}E[MaxE], *P[MaxN], *buf = E;

void insert(int u, int v){
	edge *e = buf++;
	e->v = v; e->next = P[u];
	P[u] = e;
}

void Init(){
	freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		insert(u, v);
	}
}