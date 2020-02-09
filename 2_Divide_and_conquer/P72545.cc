#include <iostream>
#include <vector>
using namespace std;


int select(int k, const vector<int>& A, const vector<int>& B){
    int a = A.size();
    int b = B.size();
    if(a + b == k){
        return max(A[a], B[b]);
    }
//    if(a + b < n){
//
//    }

}

//Select from two sorted arrays
int main() {
    int n;
    while (cin >> n) {//Select from two sorted arrays
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        int m;
        cin >> m;
        vector<int> B(m);
        for (int i = 0; i < m; ++i) cin >> B[i];

        int t;
        cin >> t;
        while (t--) {
            int k;
            cin >> k;
            cout << select(k, A, B) << endl;
        }
    }
}
