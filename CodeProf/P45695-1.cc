#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void binari(int k, int u, int nu, int z, int nz, vector<int>& v) {
  if (k == v.size()) {
    if (nu == u) {
      cout << v[0];
      for (int i = 1; i < v.size(); ++i)
	cout << ' ' << v[i];
      cout << endl;
    }
  }
  else {
    if (nz < z) {v[k] = 0; binari(k+1, u, nu, z, nz+1, v);}
    if (nu < u) {v[k] = 1; binari(k+1, u, nu+1, z, nz, v);}
  }
} 

int main() {
  int n, u;
  cin >> n >> u;
  
  vector<int> v(n);
  binari(0, u, 0, n-u, 0, v);
}
