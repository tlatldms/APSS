#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int input[51][51];
int M, N;
int _move[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<pair<int, int>> two_vec;

int bfs(vector<int> nums, int zero) {
  queue<vector<int>> q;
  bool visited[51][51]={false,};
  int i, now_x, now_y, next_x, next_y, cnt=0, max=-1;
  for (i=0; i<nums.size(); i++) {
    q.push({two_vec[nums[i]].first, two_vec[nums[i]].second, 0});
    //q.push({two_vec[i].first, two_vec[i].second, 0});
    visited[two_vec[nums[i]].first][two_vec[nums[i]].second] = true;
  }

  while(!q.empty()) {
    now_x = q.front()[0];
    now_y = q.front()[1];
    cnt = q.front()[2];
    if (cnt > max) max=cnt;
    q.pop(); 
    //cout<<"now_x: "<<now_x<<" now_y: "<<now_y<<" cnt: "<<cnt<<" zero: "<<zero<<endl;
    if (!input[now_x][now_y]) zero--;
    if (!zero) {
      return max;
      //cout<<"returning max";
    }
    for (i=0; i<4; i++) {
      next_x = now_x + _move[i][0];
      next_y = now_y + _move[i][1];

      if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N &&
          !visited[next_x][next_y]) {
        if (input[next_x][next_y]==2 || input[next_x][next_y]==0) {
          q.push({next_x, next_y, cnt+1});
        }
        visited[next_x][next_y] = true;
      }
    }
  }

  if (zero) return -1;
}


int main() {
  int i,j, max=100, a, zero=0;
  cin>>N>>M;
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      cin>>input[i][j];
      if (input[i][j] == 0) {
        zero++;
      }
      if (input[i][j] == 2) two_vec.push_back(make_pair(i,j));
    }
  }
  vector<int> cb;
  vector<int> nums;
  vector<int> answers;

  for (int i=0; i<M; i++) cb.push_back(1);
  for (int i=0; i<two_vec.size() - M; i++) cb.push_back(0);
  sort(cb.begin(), cb.end());
  do {
   //cout<<"trying"<<endl;
      for (i=0; i<cb.size(); i++) {
        if (cb[i]) nums.push_back(i);
      }
    a = bfs(nums, zero);
    //cout<<"answer:"<<a<<endl;
      answers.push_back(a);
      nums.clear();
  } while(next_permutation(cb.begin(), cb.end()));
  sort(answers.begin(), answers.end());
  //for (auto a: answers) cout<<a;
  
  if (answers.back() == -1) cout<< answers.back();
  else {
    for (auto a: answers) {
      if (a!= -1) {
        cout<<a;
        break;
      }
    }
  }
  
  
  return 0;
}


