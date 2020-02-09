#include <iostream>
#include <vector>

using namespace std;

void salida(vector<char>& word){
	for(int i=0; i < int(word.size()); ++i){
		cout << word[i];
	}
	cout << endl;
}

void func(vector<char>& cons, vector<char>& vol, vector<char>& word, vector<bool>& v1, vector<bool>& v2, int i){
	int w = word.size();
	if(i == w){
		salida(word);
	}
	else{
		for(int j=0; j < w; ++j){
			if(j%2 == 0){
				word[i] = cons[j/2];
				if(not v1[j/2] and i%2 == 0){
					v1[j/2] = true;
					func(cons, vol, word, v1, v2, i+1);
					v1[j/2] = false; 
				}
			}
			else{
				word[i] = vol[j/2];
				if(not v2[j/2] and i%2 != 0){
					v2[j/2] = true;
					func(cons, vol, word, v1, v2, i+1);
					v2[j/2] = false; 
				}
			}
		}
	}
}



int main(){
	int n;
	cin >> n;
	vector<char> cons(n);
	vector<char> vol(n);
	vector<char> word(2*n);
	for(int i=0; i < n; ++i){
		cin >> cons[i];
	}
	for(int j=0; j<n; ++j){
		cin >> vol[j];
	}
	vector<bool> v1(n, false);
	vector<bool> v2(n, false);
	func(cons, vol, word, v1, v2, 0); 
}