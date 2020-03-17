#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct tree {
	int x; int y; int age;
	tree(int x, int y, int age) : x(x), y(y), age(age) {};
};

deque<int> trees[11][11];

int dxy[8][2] = { {-1,-1}, {-1,0}, {-1,1},
{0,-1}, {0,1},
{1,-1}, {1,0}, {1,1} };



int N, M, K;
int board[11][11];
int feed[11][11];
int dead[11][11];

/*
bool comp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}
*/

void print_arr(int x[][11]) {
	//cout << "feed: " << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Trees" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << trees[i][j].size() << " ";
		}
		cout << endl;
	}

}

/*
void print_trees() {
	for (int i = 0; i < trees.size(); i++) {
		cout << "i: " << i << ", age: " << trees[i][2] << "x: " << trees[i][0] << "y: " << trees[i][1] << endl;
	}
	
}
*/
void spring_and_summer() {
	
	
	for (int q = 1; q <= N; q++) {
		for (int w = 1; w <= N; w++) {

			deque<int> t = trees[q][w];
			int tsize=t.size();
			for (int i = 0; i < tsize; i++) {
				if (feed[q][w] < t[i]) {
					//cout << "die?" << endl;
					for (int v = tsize - 1; v >= i; v--) {
						dead[q][w] += t[v] / 2;
						trees[q][w].pop_back();
						
					}
					break;
				}else if (feed[q][w] >= t[i]) {
					//cout << "x : " << t.x <<  "firstage: " << t.age << "and" << &t << endl;
					feed[q][w] -= t[i];
					trees[q][w][i] += 1;
				}		
			}
		
		}
	}



	//여름: 양분 더하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			if (dead[i][j] != 0 ) {
				feed[i][j] += dead[i][j];
				dead[i][j] = 0;
			}		
		}
	}

}


void fall_and_winter() {
	vector<vector<int>> new_trees;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			deque<int> t = trees[i][j];
			for (int q = 0; q < t.size(); q++) {
				if (t[q] % 5 == 0) {
				//	cout << "pos : " << i << ", " << j << ", age: " << t[q] << endl;
					for (int k = 0; k < 8; k++) {
						int nx = i + dxy[k][0];
						int ny = j + dxy[k][1];
						if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
						trees[nx][ny].push_front(1);
					}
				}
			}

		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			feed[i][j] += board[i][j];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	fill(&feed[0][0], &feed[0][0] + 11 * 11, 5);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		trees[a][b].push_back(c);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(trees[i][j].begin(), trees[i][j].end());
		}
	}

	for (int i = 1; i <= K; i++) {
		//cout << "i: " << i << endl;
		spring_and_summer();
		//print_arr(feed);
		fall_and_winter();
		//print_arr(feed);
	}
	int tree_sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) tree_sum += trees[i][j].size();
	}
	cout << tree_sum;
	return 0;
}