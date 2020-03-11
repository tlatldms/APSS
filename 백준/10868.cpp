#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define endl "\n"
using namespace std;

int N, M;
int *tree;
vector<int> nums;

int init(int idx, int start, int end) {
	if (start == end) tree[idx] = nums[start-1];
	else tree[idx] = min(init(idx * 2 + 1, start, (start + end) / 2), init(idx * 2 + 2, (start + end) / 2 + 1, end));
	return tree[idx];
}


int findit(int idx, int start, int end,int a, int b) {
	if (b < start || a > end) return 1000000001;
	else if (a <= start && b >= end) return tree[idx];
	else {
		return min(findit(idx * 2 + 1, start, (start + end) / 2, a, b), findit(idx * 2 + 2, (start + end) / 2 + 1, end, a, b));
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int s;
	for (int i = 0; i < N; i++) {	
		cin >> s;
		nums.push_back(s);
	}
	int h = ceil(log2(N+1));
	int tree_size = 1 << (h + 1);
	tree = new int[tree_size];
	
	init(0, 1, N);
	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		printf("%d\n", findit(0, 1, N, a, b));
		//cout << findit(0, 1, N, a, b) << endl;
	}
	


	return 0;
}