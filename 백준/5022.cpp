#include <memory.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct St {
	int x, y;
	vector<pair<int, int>> history;
};
bool visited[101][101] = { false, };

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int n, m;
int A[2][2], B[2][2];
bool path_A[101][101];

int bfs() {
	int now_x, now_y, next_x, next_y, i,j,cnt=0, B_cnt=-1;
	queue<St> q;
  queue<vector<int>> bq;
	vector<pair<int, int>> hist;
  vector<pair<int, int>> shortest_A;
	struct St first;
  hist.push_back(make_pair(A[0][0], A[0][1]));
	first.x = A[0][0]; first.y = A[0][1]; first.history=hist; 	
  q.push(first);

	while (!q.empty()) {

		now_x = q.front().x;
		now_y = q.front().y;
		hist = q.front().history;
		q.pop();
		for (i = 0; i < 4; i++) {
			next_x = now_x + dir[i][0];
			next_y = now_y + dir[i][1];
			
			if (next_x >= 0 && next_x < n+1 && next_y >= 0 && next_y < m+1 && !visited[next_x][next_y]
          && !(next_x == B[0][0] && next_y == B[0][1]) && !(next_x == B[1][0] && next_y == B[1][1])) {
				
				visited[next_x][next_y] = true;
        hist.push_back(make_pair(next_x, next_y));
        if (next_x == A[1][0] && next_y == A[1][1]) {
          shortest_A = hist; 
          break;
        }
        struct St ne;
        vector <pair<int, int>> new_h = hist;
				ne.x = next_x; ne.y = next_y; ne.history=new_h;
				q.push(ne);
			}
		}
	}
    for (auto a: shortest_A) cout<<"first: "<<a.first<<" second: "<<a.second<<endl;
  for (auto a: shortest_A) path_A[a.first][a.second] = true;
  memset(visited, false, sizeof(visited));
  bq.push({B[0][0], B[0][1], 0});
  while (!q.empty()) {
    now_x = bq.front()[0];
    now_y = bq.front()[1];
    cnt = bq.front()[2];
    
    for (i=0; i<4; i++) {
      next_x = now_x + dir[i][0];
      next_y = now_y + dir[i][1];

      if (next_x >= 0 && next_x < n+1 && next_y >= 0 && next_y < m+1 && !visited[next_x][next_y]
          && !path_A[next_x][next_y]) {
        visited[next_x][next_y] = true;
        if (next_x == B[1][0] && next_y == B[1][1]) {
          B_cnt = cnt+1;
          break;
        }
        bq.push({next_x, next_y, cnt+1});
      }
  }
  }
  cout<<"B_cnt: "<<B_cnt<<" A size: "<<shortest_A.size()<<endl;
  if (B_cnt == -1) return -1;
  else return shortest_A.size()-1 + B_cnt;
}


int main() {
	int i, j, cnt = 0;
	cin >> n >> m;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) cin >> A[i][j];
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) cin >> B[i][j];
	}


	cout<< bfs();
	return 0;
}
