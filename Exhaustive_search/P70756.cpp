#include <iostream>
#include <vector>

using namespace std;


void func(vector<string>& words, vector<vector<string> >& subwords, vector<bool>& t, int i){
	if(i == words.size()){
		for(int j=0; j<subwords.size(); ++j){
			cout << "subset " << j+1 << ": {";
			for(int k=0; k<subwords[j].size(); ++k){
				cout << subwords[j][k];
				if(k != subwords[j].size()-1){
					cout << ",";
				}
			}
			cout << "}" << endl;
		}
		cout << endl;
	}
	else{
		for(int j=0; j<subwords.size(); ++j){
			if(not t[i]){
				t[i] = true;
				subwords[j].push_back(words[i]);
			}
			func(words, subwords, t, i+1);
			t[i] = false;
			subwords[j].pop_back();
		}
	}
}

int main(){
	int n, p;
	cin >> n;
	vector<string> words(n);
	vector<bool> t(n, false);
	for(int i = 0; i<n; ++i){
		cin >> words[i];
	}
	cin >> p;
	vector<vector<string> > subwords(p);
	func(words, subwords, t, 0);
}