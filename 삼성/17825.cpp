#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> dice;
int mid_idx;
bool is_full[50];
bool ended[4];
vector<int> locations(4);
int m = -1;
struct Node{
	int idx;
	int score;
	Node* blue;
	Node* next;
};
Node * board[50];

void dfs(int depth, int sum) {
	//cout << "depth: " << depth << endl;
	if (depth == 10) {
		//action
		//cout << " depth 10, sum: " << sum << endl;

		m = max(sum, m);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (ended[i]) continue;
		int now_idx = locations[i];
		
		Node* now = board[now_idx];
		if (now->score == -1) continue;

		int time = dice[depth];
		//cout << "now idx: " << now_idx << ", now location : " << i << ", dice: " << dice[depth] << ", now score: " << now->score  << ", now sum: " << sum <<endl;

		//파란색이면
		if (now_idx == 5 || now_idx == 10 || now_idx == 15) {
			//cout << "in blue" << endl;
			now = now->blue;
			time--;
		}
		bool is_ended= false;
		while (time--) {

			now = now->next;
			if (now->score == -1) {
				//cout << "ended" << endl;
				is_ended = true;
				
				break;
			}
		}

		if (is_ended) {
			is_full[now_idx] = false;
			ended[i] = true;
			dfs(depth + 1, sum);
			is_full[now_idx] = true;
			ended[i] = false;
		}

		else if (!is_full[now->idx] ) {
			locations[i] = now->idx;
			is_full[now_idx] = false;
			is_full[now->idx] = true;
			dfs(depth + 1, sum + now->score); // 도착 안갔으면
			is_full[now_idx] = true;
			is_full[now->idx] = false;
			locations[i] = now_idx;
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		dice.push_back(a);
	}
	int idx = 0;
	Node * root = new Node();
	board[idx] = root;
	root->idx = idx;
	Node* end = new Node();
	end->idx = 45;
	end->score = -1;
	//start: board[0]
	// 40: board[20]
	Node* now = root;

	for (int i = 1; i <= 20; i++) {
		idx++;
		Node* nd = new Node();
		nd->score = i * 2;
		nd->idx = idx;
		now->next = nd;
		board[idx] = nd;
		now = now->next;
	}
	now->next = end;

	// 10: board[5]
	now = board[5];
	idx++;
	Node* first = new Node();
	first->score = 13;
	first->idx = idx;
	board[idx] = first;
	now->blue = first;
	now = first;
	for (int i = 2; i <= 3; i++) {
		idx++;
		Node* nd = new Node();
		nd->score = 10+i*3;
		nd->idx = idx;
		now->next = nd;
		board[idx] = nd;
		now = now->next;
	}
	idx++;
	Node* mid = new Node();
	mid_idx = idx;
	mid->score = 25;
	mid->idx = mid_idx;
	board[idx] = mid;
	now->next = mid;
	
	now = board[10];
	
	idx++;
	Node* second = new Node();
	second->score = 22;
	second->idx = idx;
	board[idx] = second;
	now->blue = second;
	now = second;
	
	for (int i = 2; i <= 2; i++) {
		idx++;
		Node* nd = new Node();
		nd->score = 20 + i * 2;
		nd->idx = idx;
		now->next = nd;
		board[idx] = nd;
		now = now->next;
	}
	now->next = board[mid_idx];
	
	now = board[15];
	// 30 : board[15]
	
	idx++;
	Node* third = new Node();
	third->score = 28;
	third->idx = idx;
	now->blue = third;
	board[idx] = third;
	now = third;
	for (int i = 1; i <= 2; i++) {
		idx++;
		Node* nd = new Node();
		nd->score = 28 - i;
		nd->idx = idx;
		now->next = nd;
		board[idx] = nd;
		now = now->next;
	}
	now->next = board[mid_idx];
	now = board[mid_idx];
	for (int i = 1; i <= 2; i++) {
		idx++;
		Node* nd = new Node();
		nd->score = 25 + 5*i;
		nd->idx = idx;
		now->next = nd;
		board[idx] = nd;
		now = now->next;
	}
	now->next = board[20];
	
	dfs(0, 0);

	cout << m << endl;
	
	return 0;
}