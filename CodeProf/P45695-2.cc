#include <iostream>
#include <vector>

using namespace std;

void binari(int k, int u, int nu, vector<int>& v) {
  int n = v.size();
  if (nu > u or k-nu > n-u) return;
  if (k == n) {
    cout << v[0];
    for (int i = 1; i < n; ++i)
      cout << ' ' << v[i];
    cout << endl;
  }
  else {
    v[k] = 0; binari(k+1, u, nu, v);
    v[k] = 1; binari(k+1, u, nu+1, v);
  }
} 

int main() {
  int n, u;
  cin >> n >> u;
  
  vector<int> v(n);
  binari(0, u, 0, v);
}
