#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;


void salida(vector<int>& v, int n){
	for(int i=0; i<n; ++i){
		if(i==0){
			cout << v[i];
		}
		else{
			cout << " " << v[i];
		}
	}
	cout << endl;
}


void func(Matrix& M, vector<int>& v, vector<int>& t, int n, int i){
	if(i == n){
		salida(v, n);
	}
	else{
		for(int j=0; j < n; ++j){
			if(t[j] == 0){
				v[i] = j;
				--t[j];
				for(int k=0; k<M[j].size(); ++k){
					--t[M[j][k]];
				}
				func(M, v, t, n, i+1);
				++t[j];
				for(int k=0; k<M[j].size(); ++k){
					++t[M[j][k]];
				}
			}
		}
	}
}


int main(){
	int n, m;
	cin >> n >> m;
	Matrix M(n);
	vector<int> t(n, 0);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		M[a].push_back(b);
		++t[b];
	}
	vector<int> v(n);
	func(M, v, t, n, 0);
}


