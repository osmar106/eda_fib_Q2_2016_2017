#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Adj;
typedef vector<Adj> Graph;


void func(Graph& G, vector<int>& v){
	int n = G.size();
	vector<int> sorted;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<n; ++i){
		if(v[i] == 0){
			pq.push(i);
		}
	}
	//cout << pq.top() << "prueba";
	while(!pq.empty()){
		int node = pq.top();
		pq.pop();
		sorted.push_back(node);
		for(int i=0; i<G[node].size(); ++i){
			//cout << G[node].size() << "prueba";
			if(--v[G[node][i]] == 0){
				pq.push(G[node][i]);
			}
		}
	}
	cout << sorted[0];
	for(int i=1; i<n; ++i){
		cout << " " << sorted[i];
	}
	cout << endl;
}

int main(){
	int n, m, x, y;
	while (cin >> n >> m){
		Graph G(n);
		vector<int> v(n);
		for(int i=0; i<m; ++i){
			cin >> x >> y;
			G[x].push_back(y);
			++v[y];
		}
		func(G, v);
	}

}