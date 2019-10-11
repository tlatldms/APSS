#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
int N, M;
int input_house[51][51];
int m = 99999999;
int dxy[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
vector<pair<int,int>> chickens;
vector<int> for_combination;

bool is_chicken(pair<int,int> p, vector<int> now_chickens) {
  int i;
  for (i=0; i<now_chickens.size(); i++) {
    if (chickens[now_chickens[i]] == p) return true;
  }
  return false;
}

void bfs(vector<int> now_chickens) {
  int i,j,k, now_x, now_y, next_x, next_y, ans=0;
  queue<pair<int,int>> q;
  for (i=0; i<now_chickens.size(); i++) {
    pair<int, int> a = chickens[now_chickens[i]];
    input_house[a.first][a.second] = 2;
  }
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      if (!input_house[i][j]) continue;
      int visited[51][51] = {0, };
      queue<pair<int,int>> t;
      q=t;
      q.push(make_pair(i,j)); // 집이면 푸시
      while(!q.empty()) {
        pair<int,int> now_pair = q.front();
        q.pop();
        now_x = now_pair.first;
        now_y = now_pair.second;
        if (input_house[now_x][now_y] == 2 ) {
          ans+= visited[now_x][now_y];
          break;
        }
        for(k=0; k<4; k++) {
          next_x = now_x + dxy[k][0];
          next_y = now_y + dxy[k][1];

          if (next_x < 1 || next_x > N || next_y < 1 || next_y > N) continue;
          if (visited[next_x][next_y]) continue;
          
           q.push(make_pair(next_x, next_y));
           visited[next_x][next_y] = visited[now_x][now_y]+1;
        }
      }
    }
  }

  m = min(m, ans);
  for (i=0; i<now_chickens.size(); i++) {
    pair<int, int> a = chickens[now_chickens[i]];
    input_house[a.first][a.second] = 0;
  }
 
}

int main() {
  vector<int> now_chickens;
  cin >> N >> M;
  int i,j, a;
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      cin >> a;
      if (a == 2) chickens.push_back(make_pair(i,j));
      else input_house[i][j] = a;
    }
  }
  for(i = 0; i<chickens.size() - M; i++) {
    for_combination.push_back(0);
  }
  for (i=0; i<M; i++) {
    for_combination.push_back(1);
  }


  do {
    now_chickens.clear();
    for (i=0; i<chickens.size(); i++) {
      if (for_combination[i]) now_chickens.push_back(i);
    }
    bfs(now_chickens);
  } while (next_permutation(for_combination.begin(), for_combination.end()));
  cout << m;

  return 0;
}
