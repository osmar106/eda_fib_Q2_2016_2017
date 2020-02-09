#include <iostream>
#include <vector>
using namespace std;


int first_occurrence_i(double z, const vector<double>& v, int left, int right){
    if(left>right) return -1;
    else{
        int m=(left+right)/2;
        if(z<v[m]) return first_occurrence_i(z,v,left,m-1);
        if(z>v[m]) return first_occurrence_i(z,v,m+1,right);
        if(m==0 or z>v[m-1]) return m;
        return first_occurrence_i(z,v,left,m-1);
    }
}


int first_occurrence(double x, const vector<double>& v){
    return first_occurrence_i(x,v,0,v.size()-1);
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
            cout << first_occurrence(x, V) << endl;
        }
    }
}
