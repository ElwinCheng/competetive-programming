#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

int n, m;
int x, y;
bool see[100][100] = {0};
char grid[100][100];
int dist[100][100] = {0};
vector<pair<int,int>> exits;
void bfs(){
	int nx, ny;
	pair<int,int> s;
	queue<pair<int,int>> q;
	pair<int,int> cord[4] = {mp(0,1), mp(0,-1), mp(1,0), mp(-1,0)};
	
	bool visited[n][m] = {0};
	
	dist[y][x] = 0;
	visited[y][x] = true;
	if (see[y][x]) return;
	q.push(mp(y,x));
	while(!q.empty()){
		
		  s = q.front();
		  q.pop();
		  for (pair<int,int> c : cord){
			  ny = s.first + c.first;
			  nx = s.second + c.second;
			  while((grid[ny][nx] == 'U'||grid[ny][nx] == 'D'||grid[ny][nx] == 'R'||grid[ny][nx] == 'L') && !visited[ny][nx]){
				  visited[ny][nx] = 1;
				  if (grid[ny][nx] == 'U'){
					  //cout << "u" << "\n";
					  ny--;
					  if (grid[ny-1][nx] == 'D') break;
					  }
				  else if (grid[ny][nx] == 'D'){
					  if (grid[ny+1][nx] == 'U') break;
					  ny++;
					  }
				  else if (grid[ny][nx] == 'R'){
					  nx++;
					  }
				  else {
					  nx--;
					  }
				  
				  }
			  
			  if (visited[ny][nx] || see[ny][nx] || ny == 0 || ny == n || nx == 0 || nx == m || grid[ny][nx] == 'W') continue;
			  //cout << ny << " " << nx << "\n";
			  visited[ny][nx] = 1;
			  dist[ny][nx] = dist[s.first][s.second] +1;
			  q.push(mp(ny,nx));
			  }
		 
		
		}
	
	}


void solve(){
	
	cin >> n >> m;
	char node;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> node;
			if (node == 'S') {
				y = i;
				x = j;
				}
			else if (node == '.'){
				exits.pb(mp(i,j));
				}
			grid[i][j] = node;
				
				
			}
		
		}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 'C'){
				see[i][j] = 1;
				for (int u = i-1; u > 0; u--){
					if (grid[u][j] == 'W') break;
					else if (grid[u][j] == 'U' || grid[u][j] == 'D' || grid[u][j] == 'R' || grid[u][j] == 'L') continue;
					else see[u][j] = 1;
					
					}
				for (int d = i+1; d < n; d++){
					if (grid[d][j] == 'W') break;
					else if (grid[d][j] == 'U' || grid[d][j] == 'D' || grid[d][j] == 'R' || grid[d][j] == 'L') continue;
					else see[d][j] = 1;
					
					}
				for (int r = j+1; r < m ; r++){
					if (grid[i][r] == 'W') break;
					else if (grid[i][r] == 'U' || grid[i][r] == 'D' || grid[i][r] == 'R' || grid[i][r] == 'L') continue;
					else see[i][r] = 1;
					
					}
				for (int l = j-1; l > 0; l--){
					if (grid[i][l] == 'W') break;
					else if (grid[i][l] == 'U' || grid[i][l] == 'D' || grid[i][l] == 'R' || grid[i][l] == 'L') continue;
					else see[i][l] = 1;
					
					}
				}
			
			}
		}
	
	}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
	bfs();
	for(auto c : exits){
		int d = (dist[c.first][c.second]) ? dist[c.first][c.second] : -1;
		cout << d << "\n";
		}
	/*for (int i = 0; i < n; i++){
		for (int j = 0; j< m; j++){
			cout << see[i][j] << " ";
			}
			cout << "\n";
		}*/
	
}