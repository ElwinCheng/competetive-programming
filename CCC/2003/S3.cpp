#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
char graph[maxN][maxN];
bool visited[maxN][maxN];

int rows, cols;
int tiles_in_room = 0;

void dfs(int y, int x){
  if (y < 0 || x < 0 || y >= rows || x >= cols || visited[y][x] || graph[y][x] == 'I') return;
  visited[y][x] = true;
  tiles_in_room++;
  dfs(y - 1, x);
  dfs(y + 1, x);
  dfs(y, x + 1);
  dfs(y, x - 1);
}

int main() {
  int num_tiles;
  cin >> num_tiles;
  cin >> rows >> cols;
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      cin >> graph[i][j];
    }
  }

  vector<int> rooms_tiles;
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      if (visited[i][j] || graph[i][j] == 'I') continue;
      tiles_in_room = 0;
      dfs(i, j);
      rooms_tiles.push_back(tiles_in_room);
    }
  }
  sort(rooms_tiles.begin(), rooms_tiles.end(), greater<int>());
  int i = 0;
  for (; i < rooms_tiles.size() && num_tiles - rooms_tiles[i] >= 0; i++){
    num_tiles -= rooms_tiles[i];
  }
  cout << i; 
  if (i == 1){
    cout << " room, ";
  } else {
    cout << " rooms, ";
  }
  cout << num_tiles << " square metre(s) left over";

}