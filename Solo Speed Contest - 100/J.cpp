#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define N 200005
#define MAXLOG 20
#define INF (1<<30)
#define cout2(x, y)cout << x << " " << y << endl
#define cout3(x, y, z)cout << x << " " << y << " "<< z << endl
using namespace std;

long long w[N], c[N];
int P[N];

int Find(int x){
	
	if(P[x] == x)return x;
	return P[x] = Find(P[x]);	
}
void Union(int x, int y){	
	x = Find(x);
	y = Find(y);
	P[x] = y;	
}
struct edge{
	int u, v, cost, id;
	edge(){}
	edge(int _u, int _v, int _cost, int _id){ u = _u; v = _v; cost = _cost; id = _id; }	
};
bool operator <(const edge &e1, const edge &e2){ return e1.cost < e2.cost; }
vector<edge>E;
vector<int>res1;
bool vis[N];
int S, mini_edge = INF, py;
vector<int>G[N], L[N], W[N];
long long make_st(){
	long long ans = 0;
	sort(all(E));
	int u, v, id;
	for(int i = 0; i < E.size(); i++){	
		u = E[i].u;
		v = E[i].v;
		id = E[i].id;	
		if(Find(u) != Find(v)){		
			Union(u, v);
			ans += E[i].cost;		
			res1.pb(E[i].id);
			vis[id] = true;		
			G[u].pb(v);
			G[v].pb(u);		
			W[u].pb(id);
			W[v].pb(id);
			if(mini_edge > int(c[id]))mini_edge = c[id], py = id;
		}
	}
	return ans - S/mini_edge;
}
int PD[MAXLOG][N], ID[MAXLOG][N], H[N];
void DFS(int u, int pd, int level, int id){
	if(H[u] != -1)return;
	H[u] = level;
	PD[0][u] = pd;
	ID[0][u] = id;
	for(int i = 1; (1<<i) <= level; i++){
		PD[i][u] = PD[i - 1][PD[i - 1][u]];
		if(w[ID[i - 1][u]] > w[ID[i - 1][PD[i - 1][u]]]){
			ID[i][u] = ID[i - 1][u];
		}
		else ID[i][u] = ID[i - 1][PD[i - 1][u]];
	}
	int v, id_to;
	for(int i = 0; i < G[u].size(); i++){
		v = G[u][i];
		id_to = W[u][i];
		if(H[v] != -1)continue;
		DFS(v, u, level + 1, id_to);
	}
}
void getMaxi(int &maxi, int &pos, int w1, int id1){
	if(maxi < w1)maxi = w1, pos = id1;
}
void getMini(long long &mini, int &pos, long long w1, int id1){
	if(mini > w1)mini = w1, pos = id1;
}
int getLCA(int u, int v){
    if(H[u] < H[v])swap(u, v);// u es el de mayor altura
    int bit = 31 - __builtin_clz(H[u]);
    int pos = -1, maxi = 0;
    
    for(int i = bit; i >= 0; i--){
        if(H[PD[i][u]] > H[v]){
			
			getMaxi(maxi, pos, w[ID[i][u]], ID[i][u]);
			u = PD[i][u];
		}
	}
	
	if(H[u] > H[v]){
		
		getMaxi(maxi, pos, w[ID[0][u]], ID[0][u]);
		u = PD[0][u];
	}
	
	if(u == v)return pos; 
	
    bit = 31 - __builtin_clz(H[u]);
    
    for(int i = bit; i >= 0; i--){
        if(PD[i][u] != PD[i][v]){
			
			getMaxi(maxi, pos, w[ID[i][u]], ID[i][u]);
			getMaxi(maxi, pos, w[ID[i][v]], ID[i][v]);
			u = PD[i][u], v = PD[i][v];
		}
	}
    
    getMaxi(maxi, pos, w[ID[0][u]], ID[0][u]);
	getMaxi(maxi, pos, w[ID[0][v]], ID[0][v]);
			
    return pos;
}

int main(){

	int n, m;
	cin >> n >> m;
	
	memset(H, -1, sizeof H);
	for(int i = 0; i < m; i++)scanf("%I64d", &w[i]);
	for(int i = 0; i < m; i++)scanf("%I64d", &c[i]);
	
	int u, v, id;
	for(int i = 0; i < n; i++)P[i] = i;
	vector<pair<int, int > >edges;
	
	for(int i = 0; i < m; i++){
		
		scanf("%d%d", &u, &v);
		u--; v--;
		
		L[u].pb(v);
		L[v].pb(u);
		
		E.pb(edge(u, v, w[i], i));
		edges.pb(make_pair(u, v));	
	}
	
	cin >> S;
	
	for(int i = 0; i < n; i++)P[i] = i;
	long long ans1 = make_st();

	w[m] = -1;
	DFS(0, 0, 0, m);

	long long ans2 = (1LL<<62), aux;
	int pos2, idx;
	pair<int,int>par;
	
	for(int i = 0; i < m; i++){
		
		id = E[i].id;
		if(vis[id])continue;
		
		u = E[i].u;
		v = E[i].v;

		idx = getLCA(u, v);
		
		aux = ans1 + S/mini_edge + w[id] - w[idx] - S/c[id];
		getMini(ans2, pos2, aux, id);
	}
	
	if(ans2 < ans1){
		
		idx = getLCA(edges[pos2].first, edges[pos2].second);
		printf("%I64d\n", ans2);
		
		for(int i = 0; i < res1.size(); i++){
			
			if(res1[i] == idx)continue;
			printf("%d %d\n", res1[i] + 1, w[res1[i]]);	
		}
		
		printf("%d %d\n", pos2 + 1, w[pos2] - S/c[pos2]);	
	}
	else{
		printf("%I64d\n", ans1);
		for(int i = 0; i < res1.size(); i++){
			
			if(res1[i] == py)printf("%d %d\n", res1[i] + 1, w[res1[i]] - S/mini_edge);	
			else printf("%d %d\n", res1[i] + 1, w[res1[i]]);
		}
		
	}
	
	
}
