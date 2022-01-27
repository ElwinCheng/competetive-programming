#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int r, c;

map<char,vector<pair<int,int>>> vpaths = {{'+', {{-1,0},{1,0},{0,-1},{0,1}}}, {'-', {{0,-1},{0,1}}}, {'|', {{-1,0},{1,0}}}};


int bfs(int ey, int ex, int r, int c){
	
	char grid[20][20];
	for (int i = 0; i < r; i ++){
		for (int j = 0; j < c; j++){
			cin >> grid[i][j];
			
			}
			
		}
	if (grid[0][0] == '*') return -1;
	if(r == 1 && c == 1) return 1;
	int y, x, ny, nx;
	bool visited[20][20] = {0};
	int dist[20][20] = {0};
	dist[ey-1][ex-1] = -1;
	dist[0][0] = 1;
	queue<pair<int, int>> q;
	q.push(mp(0,0));
	visited[0][0] = 1;
	while(!q.empty()){
		pair<int,int> s = q.front();
		q.pop();
		y = s.first;
		x = s.second;
		//cout << y << " " << x << "\n";
		for (auto u : vpaths[grid[y][x]]){
			ny = y + u.first;
			nx = x + u.second;
			//cout << ny << " " << nx << "\n";
			if (grid[ny][nx] == '*' || visited[ny][nx] || ny >= r || ny < 0 || nx >= c || nx <0) continue;
			dist[ny][nx] = dist[y][x] +1;
			if (ny == ey && nx == ex) return dist[ey][ex];
			visited[ny][nx] = 1;
			q.push(mp(ny,nx));
			}
			
	}
	return -1;
	}

void solve(){
	int t;
	cin >> t;
	while(t--){
		cin >> r >> c;
		cout << bfs(r-1, c-1, r,c) << "\n";
		
		}
	}
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
	}