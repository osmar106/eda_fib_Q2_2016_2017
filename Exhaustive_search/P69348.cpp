#include <iostream>
#include <vector>

using namespace std;

void salida(vector<int>& s){
    cout << "(" << s[0];
    for(int w = 1; w < (int)s.size(); ++w){
        if(w != (int)s.size()){
            cout << "," << s[w] ;
        }
    }    
    cout << ")" << endl;
}

void func(vector<int>& s, vector<bool>& t, int i){
    if(i == (int)s.size()){
        salida(s);
    }
    else{
        for(int j = 0; j < (int)s.size(); ++j){
            if(!t[j]){
                t[j] = true;
                s[i] = j+1;
                func(s,t,i+1);
                t[j] = false;
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    vector<bool> t(n, false);
    func(s, t, 0);
}
