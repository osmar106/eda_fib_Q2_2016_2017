#include <iostream>
#include <vector>
#include <queue>

using namespace std;


typedef pair<int, int> node;
typedef vector< vector<node> > Graph;
//typedef int boolean;



int func(Graph& G, int x, int y){
	vector<bool> visit(G.size(), false);
	vector<int> dist(G.size(), -1);
	priority_queue<node, vector<node>, greater<node> > pq;
	pq.push({0, x});
	dist[x]=0;
	while(!pq.empty()){
		int current = pq.top().second;
		pq.pop();
		if(!visit[current]){
			visit[current] = true;
			for(int i=0; i<G[current].size(); ++i){
				node aux = G[current][i];
				if(dist[aux.second] == -1 || dist[aux.second]>dist[current]+aux.first){
					dist[aux.second] = dist[current]+aux.first;
					pq.push({dist[aux.second], aux.second});
				}
			}
		}
	}
	return dist[y];
}


int main(){
	int n, m, u, v, c, x, y;
	while(cin >> n >> m){
		Graph G(n);
		for(int i=0; i<m; ++i){
			cin >> u >> v >> c;
			G[u].push_back({c, v});
		}
		cin >> x >> y;
		int result = func(G, x, y);
		if(result == -1){
			cout << "no path from " << x << " to " << y << endl;
		}
		else{
			cout << result << endl;
		}
	}
}