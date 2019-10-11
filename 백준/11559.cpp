#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

char input[12][6];
bool visit[12][6];

bool puyo[18][12][6];

queue<vector<int>> q;

int dxy[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void print() {
	int i, j;
	cout << endl;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 6; j++) {
			cout << input[i][j];
		}
		cout << endl;
	}
}


int sol() {
	int i, j, k, l, now_x, now_y, next_x, next_y, now_cnt, now_set;
	char now;
	int cont=0;
	do  {
		print();
		now_set = 0;
		
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 6; j++) {
				if (visit[i][j]) continue;
				
				if ((input[i][j]) != '.') {
					//cout << "now: "<<now<<"i: " << i << ", j: " << j << endl;
					visit[i][j] = true;
					puyo[now_set][i][j] = true;
					//cout << "now char: " << input[i][j] << endl;
					q.push({ i,j});
					now_cnt = 0;
					while (!q.empty()) {
						//cout << "now: " << now << "i: " << i << ", j: " << j << endl;
						now_x = q.front()[0];
						now_y = q.front()[1];
						//cout << "now_x: " << now_x << ", now_y: " << now_y << endl;
						q.pop();

						for (k = 0; k < 4; k++) {
							next_x = now_x + dxy[k][0];
							next_y = now_y + dxy[k][1];

							if (next_x >= 0 && next_x < 12 && next_y >= 0 &&
								next_y < 6 && !visit[next_x][next_y]
								&& input[next_x][next_y] == input[i][j]) {
								q.push({ next_x, next_y});
								now_cnt++;
								puyo[now_set][next_x][next_y] = true;
								visit[next_x][next_y] = true;
							}
						}
					}
					//cout <<"now_cnt: " << now_cnt << endl;
					if (now_cnt >= 3) {
						now_set++;
					}
					else {
						memset(puyo[now_set], 0, sizeof(puyo[now_set]));
					}
				}
			}
		}

		if (now_set == 0) return cont;
		cont++;
		for (i = 0; i < now_set; i++) {
			for (j = 0; j < 6; j++) {
				for (k = 0; k < 12; k++) {
					if (puyo[i][k][j]) {
						for (l = k; l >= 0; l--) {
							if (l == 0) input[l][j] = '.';
							else input[l][j] = input[l - 1][j];
						}
					}
				}
			}
		}
		memset(puyo, 0, sizeof(puyo));
		memset(visit, 0, sizeof(visit));
		
		//cout << "now_set: " << now_set << endl;
	} while (now_set != 0);

	return -9;
}

int main() {
	int i, j;
	for (i = 0; i < 12; i++) {
		cin >> input[i];
	}
	
	cout << sol() << endl;
	//print();
	return 0;
}