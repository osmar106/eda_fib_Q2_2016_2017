#include <iostream>
#include <vector>

using namespace std;

void binari(int k, vector<int>& v) {
  if (k == v.size()) {
    cout << v[0];
    for (int i = 1; i < v.size(); ++i)
      cout << ' ' << v[i];
    cout << endl;
  }
  else {
    v[k] = 1; binari(k+1, v);
    v[k] = 0; binari(k+1, v);
  }
} 

int main() {
  int n;
  cin >> n;
  
  vector<int> v(n);
  binari(0, v);
}
