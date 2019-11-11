#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
int input[11][31];
int m=10;
bool check() {
  int i;
  for (i=1; i<=N; i++) {
    int now_b = i;
    int now_a;
    for (now_a = 1; now_a <= H; now_a++) {
      if (input[now_b][now_a]== 1 ) {
        now_b++;
        continue;
      }
      if (now_b == 1)  continue;
      if (input[now_b-1][now_a]== 1) {
        now_b--;
      } 
    }
    if (now_b != i) {
      return false;
    }
  }
  return true;
 }


void dfs(int start_i, int start_j, int count) {
  if (check()) {
    m = min(m, count);
    return;
  } else if (count >= 3) return;
  for (int j = start_j; j<=H; j++) {
    if (input[start_i][j]) continue;
    input[start_i][j] = 1;
    dfs(start_i, j+1, count+1);
    input[start_i][j] = 0;
  }
  for (int i=start_i+1; i<=N; i++) {
    for (int j=1; j<=H; j++) {
      if (input[i][j]) continue;
      input[i][j] = 1;
      dfs(i, j+1, count+1);
      input[i][j] = 0;
    }
  }
}

int main() {
  cin >> N >> M >> H;
  int i, a, b;
  for (i=0; i<M; i++) {
    cin >> a >> b;
    input[b][a]=1;
  }

  dfs(1, 1, 0);
  if (m == 10) cout << -1;
  else cout << m;
  return 0;
}


