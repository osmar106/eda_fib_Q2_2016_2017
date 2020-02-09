#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

typedef vector<vector<char> > Matrix;
typedef pair<int,int> intpair;

void work (int i, int j,
			const Matrix& M,
			const Matrix& vis,
			stack<intpair>& S)
{
	int n = M.size();
	int m = M[0].size();
	if (i >= 0 and i < n and j >= 0 and j < m) {
		if (M[i][j] != 'X' and not vis[i][j]) {
			S.push({i, j});
		}
	}
}

bool can_reach_treasure(const Matrix& M, int si, int sj) {
	stack<intpair> S;
	int n = M.size();
	int m = M[0].size();
	Matrix vis(n, vector<char>(m, false));

	S.push({si, sj});
	while (not S.empty()) {
		intpair v = S.top(); S.pop();
		if (not vis[v.first][v.second]) {
			vis[v.first][v.second] = true;
			if (M[v.first][v.second] == 't') return true;
			work(v.first+1, v.second, M, vis, S);
			work(v.first-1, v.second, M, vis, S);
			work(v.first, v.second+1, M, vis, S);
			work(v.first, v.second-1, M, vis, S);
		}
	}
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	Matrix M(n, vector<char>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> M[i][j];
		}
	}
	int si, sj;
	cin >> si >> sj;
	--si; --sj;
	if (can_reach_treasure(M, si, sj)) cout << "yes" << endl;
	else cout << "no" << endl;
}
