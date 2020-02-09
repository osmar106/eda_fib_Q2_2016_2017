#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
 
typedef vector<char> Row;
typedef vector<Row> Graph;
 
 
int func(Graph &G, int xx, int yy){
  Graph visited(G.size(), Row(G[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  int max = -1;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(0);
  visited[xx][yy] = 'T';
  
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dist = dQ.front() + 1;
    
    //Above
    if (y > 0 && visited[x][y-1] == 'F' && G[x][y-1] != 'X') {
      if (G[x][y-1] == 't') max = dist;
      Q.push(make_pair(x, y-1));
      dQ.push(dist);
      visited[x][y-1] = 'T';
    }
    
    //Below
    if (y < G[0].size() - 1 && visited[x][y+1] == 'F' && G[x][y+1] != 'X') {
      if (G[x][y+1] == 't') max = dist;
      Q.push(make_pair(x, y+1));
      dQ.push(dist);
      visited[x][y+1] = 'T';
    }
    
    //Left
    if (x > 0 && visited[x-1][y] == 'F' && G[x-1][y] != 'X') {
      if (G[x-1][y] == 't') max = dist;
      Q.push(make_pair(x-1, y));
      dQ.push(dist);
      visited[x-1][y] = 'T';
    }
    
    //Right
    if (x < G.size() - 1 && visited[x+1][y] == 'F' && G[x+1][y] != 'X') {
      if (G[x+1][y] == 't') max = dist;
      Q.push(make_pair(x+1, y));
      dQ.push(dist);
      visited[x+1][y] = 'T';
    }
    Q.pop();
    dQ.pop();
  }
  return max;
}


int main(){
  int n, m, r, c;
  cin >> n >> m;
  Graph G(n, Row(m));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> G[i][j];
    }
  }
  cin >> r >> c;
  int res = func(G, r-1, c-1);
  if (res < 0){
    cout << "no treasure can be reached" << endl;
  }
  else{
    cout << "maximum distance: " << res << endl;
  }
}