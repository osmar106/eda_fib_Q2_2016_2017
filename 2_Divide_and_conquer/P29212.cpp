#include <iostream>
#include <vector>
using namespace std;

int expm(int n, int k, int m){
//    if(k==1) return n;
//    if(k==0) return 1;
    if(k>0){
        int i = k/2;
        //cout << i << endl;
        int j = expm(n,i,m);
        //cout << j << endl;
        if(k%2==0){
            return j%m*j%m;
        }
        else return j%m*j%m*n%m;
    }
    else if(k==1) return n;
    else return 1;
}

int main(){
    int n,k,m;
    while(cin >> n >> k >> m){
        cout << expm(n,k,m) << endl;
    }
}
