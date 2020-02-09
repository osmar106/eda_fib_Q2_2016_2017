#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef vector<vector<char> > Matrix;
typedef pair<int,int> intpair;

void work(int i, int j, const Matrix& M, Matrix& enq, queue<intpair>& Q){
	int n = M.size();
	int m = M[0].size();
	if (i >= 0 and i < n and j >= 0 and j < m) {
		if (M[i][j] != 'X' and not enq[i][j]) {
			Q.push({i, j}); enq[i][j] = true;
		}
	}
}

bool can_reach_treasure(const Matrix& M, int si, int sj) {
	queue<intpair> Q;
	int n = M.size();
	int m = M[0].size();
	Matrix enq(n, vector<char>(m, false));

	Q.push({si, sj}); 
	enq[si][sj] = true;
	while (not Q.empty()) {
		intpair v = Q.front(); Q.pop();
		if (M[v.first][v.second] == 't') return true;
		work(v.first+1, v.second, M, enq, Q);
		work(v.first-1, v.second, M, enq, Q);
		work(v.first, v.second+1, M, enq, Q);
		work(v.first, v.second-1, M, enq, Q);
	}
	return false;
}


int main(){
	int n, m;
	cin >> n >> m;
	Matrix M(n, vector<char>(m));
	for(int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			cin >> M[i][j];
		}
	}
	int si, sj;
	cin >> si >> sj;
	--si; --sj;
	if(can_reach_treasure(M, si, sj)) cout << "yes" << endl;
	else cout << "no" << endl;
}
