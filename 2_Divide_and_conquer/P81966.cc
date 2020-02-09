#include <iostream>
#include <vector>
using namespace std;


int position(double x, const vector<double>& v, int esq, int dre) {
                if (esq > dre) return -1;
                int mid = (esq+dre)/2;
                if (x < v[mid]) return position(x, v, esq, mid-1);
                if (x > v[mid]) return position(x, v, mid+1, dre);
                return mid;
}

// int position(double x, const vector<double>& v, int left, int right){
//     if(right<left){
//         return -1;
//     }
//     else{
//         int m=(left+right)/2;
//         if(x>v[m]) return position(x,v,m+1,right);
//         if(x<v[m]) return position(x,v,left,m-1);
//         return m;
//     }
// }


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            int left, right;
            cin >> x >> left >> right;
            cout << position(x, V, left, right) << endl;
        }
    }
}
