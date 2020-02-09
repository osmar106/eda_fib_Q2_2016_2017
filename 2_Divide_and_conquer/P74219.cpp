#include <iostream>
#include <vector>
using namespace std;

typedef int M[2][2];


void product(int m, const M&a, const M&b, M&c){
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            c[i][j]=0;
            for(int k=0; k<2; ++k){
                c[i][j] = (c[i][j]+ a[i][k]*b[k][j]) % m;
            }
        }
    }
}

void identity(M&b){
    b[0][1] = b[1][0] = 0;
    b[0][0] = b[1][1] = 1;
}

void power(int n, int m, const M&a, M&b){
    if(n == 0){
        identity(b);
    }
    else{
        if(n%2 == 0){
            M c;
            power(n/2, m, a, c);
            product(m, c, c, b);
        }
        else{
            M c,d;
            power(n/2, m, a, c );
            product(m, c , c , d );
            product(m, a, d, b );
        }
    }
}

int main(){
    M a;
    a[0][0] = a[0][1] = a[1][0] = 1;
    a[1][1] = 0;
    int n, m;
    while(cin >> n >> m){
        M b;
        power(n,m,a,b);
        cout << b[1][0] << endl;
    }
}
