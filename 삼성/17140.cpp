#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
vector<vector<int>> arr(101, vector<int>(101));
vector<int> _count(101);



bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else return (a.first < b.first);
}

void sol() {
	int i, j, time=0, tmp, r_max=3, c_max=3;
	vector<pair<int, int>> T;
	while (1) {
		if (arr[r][c] == k) {
			cout<<time;
			break;
		}
		else if (time > 100) {
			cout<<-1;
			break;
		}

		time++;
		//R����
		if (r_max >= c_max) {
			//cout << "in R����" << endl;	
			for (i = 1; i <=r_max; i++) {
				//cout << "print" << endl;
				//�� �ٿ� ���ؼ� ���� ����
				for (j = 1; j <= 100; j++) {
					if (!arr[i][j]) continue;
					//cout << arr[i][j] << " ";
					_count[arr[i][j]]++;
				}
				//count pair vector �ֱ�
				for (j = 1; j <= 100; j++) {
					if (!_count[j]) continue;
					T.push_back(make_pair(j, _count[j]));
				}
				//cout << "T Size: " << T.size() << endl;
				c_max = max(c_max, int(T.size()) * 2);
				//cout << "C_max: " << c_max << endl;

				//�� �� �� �ʱ�ȭ
				fill(arr[i].begin(), arr[i].end(), 0);
				
				//cnt -> i ������ ����
				sort(T.begin(), T.end(), comp);

				tmp = 0;
				for (auto aa: T) {
					arr[i][tmp * 2 + 1] = aa.first;
					arr[i][(tmp + 1) * 2] = aa.second;
					tmp++;
				}

				T.clear();
				fill(_count.begin(), _count.end(), 0);
			}
		}
		//C����
		else {
			//cout << "in C����" << endl;
			for (i = 1; i <= c_max; i++) {
				//�� �ٿ� ���ؼ� ���� ����
				//cout << "print" << endl;
				for (j = 1; j <= 100; j++) {

					if (!arr[j][i]) continue;
				
					//cout << arr[i][j] << " ";
					_count[arr[j][i]]++;
				
				}

				for (j = 1; j <= 100; j++) {
					if (!_count[j]) continue;
					T.push_back(make_pair(j, _count[j]));
				}

				r_max = max(r_max, int(T.size()) * 2);

				//cout << "R_max: " << r_max << endl;

				//�� �� �ʱ�ȭ
				for (j = 1; j <= 100; j++) {
					arr[j][i] = 0;
				}

				//cnt -> i ������ ����
				sort(T.begin(), T.end(), comp);

				tmp = 0;
				for (auto aa : T) {
					arr[tmp * 2 + 1][i] = aa.first;
					arr[(tmp + 1) * 2][i] = aa.second;
					tmp++;
				}

				T.clear();
				fill(_count.begin(), _count.end(), 0);
			}
		}
		
	}
	
	
}

int main() {
	cin >> r >> c >> k;
	int i, j;
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) cin >> arr[i][j];
	}
	//cout << arr.size();
	sol();
	return 0;
}