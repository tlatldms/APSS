#include <iostream>
#include <vector>

using namespace std;
int R, C, M;
vector<vector<int>> shark(10020, vector<int>(5));
vector < vector<pair<int, int>>> location(102, vector<pair<int, int>>(102, {-1,-1}));

void move_shark(int n) {
	if (shark[n][3] == -1) return;
	int i;
	pair<int, int> now_loc;


	for (i = 0; i < shark[n][2]; i++) {

		//�� && 1
		if (shark[n][3] == 1) {
			if (shark[n][0] == 1) {
				shark[n][3] = 2;
				shark[n][0] += 1;
			}
			//�� && not 1
			else shark[n][0] -= 1;
		}
		//�Ʒ� && R
		else if (shark[n][3] == 2) {
			if (shark[n][0] == R) {
				shark[n][3] = 1;
				shark[n][0] -= 1;
			}
			//�Ʒ� && not R
			else shark[n][0] += 1;
		}			 
		else if (shark[n][3] == 3) {
			if (shark[n][1] == C) {
				shark[n][3] = 4;
				shark[n][1] -= 1;
			}		 
			else shark[n][1] += 1;
		}			 
		else if (shark[n][3] == 4) {
			if (shark[n][1] == 1) {
				shark[n][3] = 3;
				shark[n][1] += 1;
			}
			else shark[n][1] -= 1;
		}
		//cout << n << "���� ���, moving shark i: " << i << "r:" << shark[n][0] << " c:" << shark[n][1] <<endl;
	}
	//���� �ִ� �ְ� ������ ���ؼ� ���Կ� ��ȣ ��������
	if ((now_loc = location[shark[n][0]][shark[n][1]]).first != -1) {
		//���� �ִ¾ְ� ��Ƹ�����
		if (now_loc.second < shark[n][4]) {
			shark[now_loc.first][3] = -1;
			shark[now_loc.first][4] = 0;
			location[shark[n][0]][shark[n][1]] = make_pair(n, shark[n][4]);
		}
		//���� ������ ��Ƹ��� ��
		else {
			shark[n][3] = -1;
			shark[n][4] = 0;
		}
	}
	else {
		location[shark[n][0]][shark[n][1]] = make_pair(n, shark[n][4]);
	}

}
int main() {
	int i, j, k, x,y, sum = 0, cat=0;
	cin >> R >> C >> M;

	for (i = 0; i < M; i++) {
		for (j = 0; j < 5; j++) cin >> shark[i][j];
	}

	for (i = 0; i < M; i++) {
		location[shark[i][0]][shark[i][1]] = make_pair(i, shark[i][4]);
	}

	for (i = 1; i <= C; i++) {
		if (cat == M) break;
		for (j = 1; j <= R; j++) {
			if (location[j][i].first != -1) {
				//cout << "catch location[j][i]: " << location[j][i].second << endl;;
				sum += location[j][i].second;
				cat++;
				shark[location[j][i].first][4] = 0;
				shark[location[j][i].first][3] = -1;
				break;
			}
		}

		fill(location.begin(), location.end(),
			vector<pair<int, int>>(102, { -1,-1 }));

		//��� ������ �ѹ� �����̱�
		for (k = 0; k < M; k++) {
			move_shark(k);
		}
	}
	cout <<sum;
	return 0;
}
