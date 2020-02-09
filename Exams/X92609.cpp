#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int func(vector<int>& coins, int& x, int value, int sp, int mu){
	if(sp > x or sp + mu < x){
		return 0;
	}
	if(value == coins.size()){
		return 1;
	}
	int counter = 0;
	for(int j=0; j <= 2; ++j){
		counter += func(coins, x, value+1, sp+j*coins[value], mu-2*coins[value]);
	}
	return counter;
}

int main(){
	int x;
	int n;
	while(cin >> x){
		cin >> n;
		vector<int> coins(n);
		int a = 0;
		for(int i=0; i < n; ++i){
			cin >> coins[i];
			a += coins[i];
		}
		cout << func(coins, x, 0, 0, 2*a) << endl;
	}
}