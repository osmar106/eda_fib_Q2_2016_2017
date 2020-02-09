#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int> > Row;
typedef vector< vector< pair<double, int> > > Graph;

int func(Graph& G){
	vector<bool> used(G.size(), false);
	priority_queue<Row> Q;
	Q.push(make_pair(0, make_pair(0, 0)));
	int value = 0;

	while(not Q.empty()){
		int p = -(Q.top().first);
		int v = Q.top().second.second;
		Q.pop();
		if(not used[v]){
			used[v] = true;
			value += p;
			for (int i = 0; i < G[v].size(); ++i)
			{
				int x = G[v][i].first; //peso del vértice
				//cout << G[v][i].first << endl; //prueba
				int y = G[v][i].second; //vértice al que está conectado v
				//cout << G[v][i].second << endl; //prueba
				Q.push(make_pair(-x, make_pair(v, y))); //Q.first=peso, Q.second.second=vértice siguiente
			}
		}
	}
	return value;
}

int main(){
	int n, m, u, v, w;
	while(cin >> n >> m){
		Graph G(n);
		for(int i=0; i<m; ++i){
			cin >> u >> v >> w;
			G[u-1].push_back(make_pair(w, v-1));
			G[v-1].push_back(make_pair(w, u-1));
		}
		int result =  func(G);
		cout << result << endl;
	}

}