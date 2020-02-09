#include <iostream>
#include <vector>

using namespace std;

void genera(int k, int s, const vector<int>& x, vector<int>& v) {
  int n = v.size();
  if (k == n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
      if (v[i] == 1)
	sum += x[i];

    if (sum == s){
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
  }
  else {
    v[k] = 0; genera(k+1, s, x, v);
    v[k] = 1; genera(k+1, s, x, v);
  }
} 

int main() {
  int s, n;
  cin >> s >> n;
  
  vector<int> x(n);
  for (int k = 0; k < n; ++k)
    cin >> x[k];

  vector<int> v(n);  
  genera(0, s, x, v);
}
