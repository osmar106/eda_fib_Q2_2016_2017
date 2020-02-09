#include <iostream>
#include <vector>
using namespace std;


bool resistant_search_i(double x, const vector<double>& v, int l, int r){
    if(l>=r) return false;
    int m = (r+l)/2;
    if(x==v[m]) return true;
    if(m-1 >= 0 and v[m-1]==x) return true;
    if(m+1 < v.size() and v[m+1] == x) return true;
    if(x < v[m]) return resistant_search_i(x, v, l, m);
    return resistant_search_i(x, v, m+1, r);
}



bool resistant_search(double x, const vector<double>& v){
    return resistant_search_i(x, v, 0, v.size());
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
