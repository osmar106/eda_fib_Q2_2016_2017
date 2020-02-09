#include <iostream>
#include <vector>
#include <map>

using namespace std;

void salida(vector<char>& result){
	for(int i=0; i < result.size(); ++i){
		cout << result[i];
	}
	cout << endl;
}

void func(vector<char>& letters, vector<char>& result, int i){
	int n = result.size();
	if(i == n){
		salida(result);
	}
	else{
		for(int j=0; j < letters.size(); ++j){
			result[i] = letters[j];
			func(letters, result, i+1);
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<char> letters(4);
	letters[0] = 'A';
	letters[1] = 'C';
	letters[2] = 'G';
	letters[3] = 'T';
	vector<char> result(n);
	func(letters, result, 0);
}