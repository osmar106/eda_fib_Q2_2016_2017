#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void genera(int k, int s, int sum, int undef, const vector<int>& x, vector<int>& v) {
  if (sum > s or sum + undef < s) return;
  int n = v.size();
  if (k == n) {
    cout << "{";
    bool primer = true;
    for (int i = 0; i < n; ++i) {
      if (v[i] == 1) {
	if (primer) {
	  primer = false;
	}
	else {
	  cout << ",";
	}
	cout << x[i];	
      }    
    }
    cout << "}" << endl;
  }
  else {
    v[k] = 0; genera(k+1, s, sum,      undef - x[k], x, v);
    v[k] = 1; genera(k+1, s, sum+x[k], undef - x[k], x, v);
  }
} 

int main() {
  int s, n;
  cin >> s >> n;
  
  vector<int> x(n);
  for (int k = 0; k < n; ++k)
    cin >> x[k];

  vector<int> v(n);
  genera(0, s, 0, accumulate(x.begin(), x.end(), 0), x, v);
}
