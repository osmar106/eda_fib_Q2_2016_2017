#include <iostream>
#include <vector>

using namespace std;

void salida(vector<string>& change){
    cout << "(" << change[0];
    for(int z = 1; z < (int)change.size(); ++z){
        if(z != (int)change.size()){
            cout << "," << change[z];
        }
    }    
    cout << ")" << endl;
}

void func(vector<string>& words, vector<string>& change, vector<bool>& t, int i){
    if(i == (int)change.size()){
        salida(change);
    }
    else{
        for(int j = 0; j < (int)change.size(); ++j){
            if(!t[j]){
                t[j] = true;
                change[i] = words[j];
                func(words,change,t,i+1);
                t[j] = false;
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    vector<string> change(n);
    vector<bool> t(n, false);
    for(int i=0; i < n; ++i){
        cin >> words[i];
    }
    func(words, change, t, 0);
}
