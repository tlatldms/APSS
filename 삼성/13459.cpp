#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M, answer;
char board[11][11];
pair<int, int > R, B, O;
int dxy[4][2] = { {-1,0}, {0,1}, {1,0}, {0, -1} };
bool visit[101][101];
vector<int> move(int rx, int ry, int bx, int by, int dir) {
	bool red_in = false, blue_in = false;
	bool red_first = false;
	if (dir == 0 && rx <= bx) red_first = true;
	else if (dir == 1 && ry >= by) red_first = true;
	else if (dir == 2 && rx >= bx) red_first = true;
	else if (dir == 3 && ry <= by) red_first = true;
	int nrx = rx, nry = ry, nbx = bx, nby = by;
	bool red_safe = true, blue_safe = true;
	if (red_first) {
		while (1) {
			nrx += dxy[dir][0]; nry += dxy[dir][1];
			//met wall
			if (board[nrx][nry] == '#') {
				nrx -= dxy[dir][0]; nry -= dxy[dir][1];
				break;
			}
			//met hole
			if (nrx == O.first && nry == O.second) {
				//return { -3, 0,0,0 }; //success
				nrx++; nry++;
				red_in = true;
				break;
			}
		}
		pair<int, int> new_R = {nrx, nry};
		while (1) {
		
			nbx += dxy[dir][0]; nby += dxy[dir][1];
			//met wall or R
			if (board[nbx][nby] == '#' || (nbx==new_R.first && nby == new_R.second)) {
				nbx -= dxy[dir][0]; nby -= dxy[dir][1];
				break;
			}
			//met hole
			if (nbx == O.first && nby == O.second) {
				return { -1,0,0,0 };
			}
		}
		if (red_in) return { -3,0,0,0 };
	}
	else { // if blue first
		while (1) {
			nbx += dxy[dir][0]; nby += dxy[dir][1];
			//met wall
			if (board[nbx][nby] == '#') {
				nbx -= dxy[dir][0]; nby -= dxy[dir][1];
				break;
			}
			//met hole
			if (nbx == O.first && nby == O.second) {
				return { -1,0,0,0 };
			}
		}
		pair<int, int> new_B = {nbx, nby};
		while (1) {
			nrx += dxy[dir][0]; nry += dxy[dir][1];
			//met wall or B
			if (board[nrx][nry] == '#' || (nrx == new_B.first && nry == new_B.second)) {
				nrx -= dxy[dir][0]; nry -= dxy[dir][1];
				break;
			}
			//met hole
			if (nrx == O.first && nry == O.second) {
				return { -3, 0,0,0 }; //success
			}
		}
	}

	return { nrx, nry, nbx, nby };

}

void dfs(pair<int,int> RR, pair<int,int> BB, int depth ) {
	if (depth == 10) return;
	for (int i = 0; i < 4; i++) {
		vector<int> res = move(RR.first, RR.second,BB.first,BB.second, i);
		/*cout <<"depth: " << depth <<  ", i: " << i << ", xyxy: ";
		for (int k = 0; k < 4; k++) cout << res[k] << " ";
		cout << endl;*/
		int rx = res[0], ry = res[1], bx = res[2], by = res[3];
		
		//success
		if (rx == -3) {
			answer = 1;
			cout << 1;
			exit(0);
		}
		
		//met hole
		if (rx == -1) continue;
		
		else if (visit[rx*M+ry][bx*M+by]) continue;
		visit[rx * M + ry][bx * M + by] = 1;
		dfs({ rx,ry }, { bx,by }, depth+1);
		visit[rx * M + ry][bx * M + by] = 0;
		
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			board[i][j] = str[j];
			if (str[j] == 'R') {
				R = { i,j };
			}
			else if (str[j] == 'B') {
				B = { i,j };
			}
			else if (str[j] == 'O') {
				O = { i,j };
			}
		}
	}

	dfs(R, B, 0);
	cout << 0;
	return 0;
}