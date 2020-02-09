#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Binario;

Binario b;
int n;

void func(int i){
    if(i == n){
        bool entra = true;
        for(int j = 0; j < n; ++j){
            if(entra) entra = false;
            else cout << " ";
            cout << b[j];
        }
        cout << endl;
    }
    else{
        b[i] = 0;
        func(i+1);
        b[i] = 1;
        func(i+1);
    }
}


int main(){
    cin >> n;
    b = Binario(n);
    func(0);
}
