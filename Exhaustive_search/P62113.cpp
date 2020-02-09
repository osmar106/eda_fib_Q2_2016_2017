#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void salida(int& x, vector<int>& coins, vector<bool>& t, int& n){
	cout << x << " = ";
	bool entry1 = true;
	for(int i=0; i < 2*n; i++){
		if(t[i]){
			if(entry1){
				entry1 = false;
			}
			else{
				cout << " + ";
			}

			if(i%2 == 0){
				cout << coins[i];
			}
			else{
				cout << coins[i] << "p";
			}
		}
	}
	cout << endl;
}

void func(int& x, vector<int>& coins, vector<bool>& t, int value, int& n, int i){
	if(value == x){
		salida(x,coins,t,n);
	}
	else{
		for(int j=i; j < 2*n; j++){
			if((value + coins[j]) <= x){
				t[j] = true;
				func(x, coins, t, value + coins[j], n, i+1);
				i++;
				t[j] = false;
			}
		}
	}
}

int main(){
	int x;
	int n;
	while(cin >> x){
		cin >> n;
		vector<int> coins(2*n);
		vector<bool> t(2*n, false);
		for(int i=0; i < 2*n; i+=2){
			cin >> coins[i];
			coins[i+1] = coins[i];
		}
		sort(coins.begin(), coins.end());
		func(x, coins, t, 0, n, 0);
		cout << "----------" << endl;
	}
}