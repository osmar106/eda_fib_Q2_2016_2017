#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > sudoku;
vector<vector<bool> > row, col;
vector<vector< vector<bool> > > sq;


void write(){
	cout << endl;
	for(int i=0; i<9; ++i){
		cout << sudoku[i][0] + 1;
		for(int j=1; j < 9; ++j)
			cout << ' ' << sudoku[i][j] + 1;
		
		cout << endl;
	}
}


bool fill(int i, int j){
	if(i==9)
		return true;
	
	if(j==9)
		return fill(i+1, 0);
	
	if(sudoku[i][j] != -1)
		return fill(i, j+1);
	
	for(int v=0; v<9; ++v)
		if(not row[i][v] and not col[j][v] and not sq[i/3][i/3][v]){
			row[i][v] = col[j][v] = sq[i/3][j/3][v] = true;
			sudoku[i][j] = v;
			if(fill(i, j+1))
				return true;
			
			row[i][v] = col[j][v] = sq[i/3][j/3][v] = false;
		}
	
	sudoku[i][j] = -1;
	return false;
}


int main(){
	sudoku = vector<vector<int> >(9, vector<int>(9));
	int n;
	cin >> n;
	cout << n << endl;
	while(n--){
		row = col = vector<vector<bool> >(9, vector<bool>(9, false));
		sq = vector<vector<vector<bool> > >(3, vector<vector<bool> >(3, vector<bool>(9, false)));
		for(int i= 0; i < 9; ++i)
			for(int j=0; j < 9; ++j){
				char c;
				cin >> c;
				if(c == '.')
					sudoku[i][j] = -1;
				
				else{
					int v = c - '1';
					row[i][v] = col[j][v] = sq[i/3][j/3][v] = true;
					sudoku[i][j] = v;
				}
			}
		
		if(fill(0, 0))
			write();
		
	}
}