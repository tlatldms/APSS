#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<vector<int>> cctvs;
int N, M;
int m = 99999999;
int one[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int three[4][2][2] = {
  {{-1,0},{0,1}},
  {{0,1}, {1,0}},
  {{1,0}, {0,-1}},
  {{0,-1}, {-1,0}}
};

int four[4][3][2]={
  {{0,-1}, {-1,0}, {0,1}},
  {{-1,0}, {0,1}, {1,0}},
  {{0,1}, {1,0}, {0,-1}},
  {{1,0}, {0,-1}, {-1,0}}
};
//bool visited[9][9];
int num_of_cctvs = 0;

void print_arr (int arr[9][9]) {
  int i,j;
  for (i=0; i<N; i++) {
    for (j=0; j<M; j++) {

      cout<<arr[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}
void cctv(int arr[9][9], int cur_cnt) {
  if (cur_cnt == num_of_cctvs) {
    int tmp_cnt = 0;
    //cout<<"cur_cnt: "<<cur_cnt<<endl;
    //print_arr(arr);
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (arr[i][j] == 0) tmp_cnt++;
      }
    }

    m = min(m, tmp_cnt);
    return;
  }
  int x, y;
  int tocopy[9][9];
  int cctv_num = cctvs[cur_cnt][0];
  int start_i = cctvs[cur_cnt][1];
  int start_j = cctvs[cur_cnt][2];
 // cout << "cctv_num: "<<cctv_num<<endl;
  switch (cctv_num) {
    case 1:
      for (int i=0; i<4; i++) {
        memset(tocopy, 0, sizeof(tocopy));
        for (int j=0; j<N; j++) {
          for (int k=0; k<M; k++) {
            tocopy[j][k] = arr[j][k];
          }
        }

        x = start_i;
        y = start_j;

        while (1) {
          x += one[i][0];
          y += one[i][1];

          if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == 6) break;
          if (arr[x][y] == 0 ) tocopy[x][y] = 7;
        }
   //     cout << "i: " << i<< endl;
        cctv(tocopy, cur_cnt+1);

      }
      break;
    case 2:
      memset(tocopy, 0, sizeof(tocopy));
      for (int j=0; j<N; j++) {
        for (int k=0; k<M; k++) {
          tocopy[j][k] = arr[j][k];
        }
      }

      x = start_i;
      y = start_j;
      while (1) {
        x += 1;
        if (x >= N || arr[x][y] == 6) break;
        if (arr[x][y] == 0) tocopy[x][y] = 7;
      }

      x = start_i;
      while (1) {
        x -= 1;
        if (x < 0 || arr[x][y] == 6) break;
        if (arr[x][y] == 0) tocopy[x][y] = 7;
      }


      cctv(tocopy, cur_cnt + 1);

      memset(tocopy, 0, sizeof(tocopy));
      for (int j=0; j<N; j++) {
        for (int k=0; k<M; k++) {
          tocopy[j][k] = arr[j][k];
        }
      }

      x = start_i;
      y = start_j;

      while (1) {
        y += 1;
        if (y >= M || arr[x][y] == 6) break;
        if (arr[x][y] == 0) {
          tocopy[x][y] = 7;
        }
      }

      y = start_j;

      while (1) {
        y -= 1;
        if (y < 0 || arr[x][y] == 6) break;
        if (arr[x][y] == 0) tocopy[x][y] = 7;
      }

      cctv(tocopy, cur_cnt + 1);
      break;
    case 3:
      for (int i=0; i<4; i++) {
        memset(tocopy, 0, sizeof(tocopy));
        for (int l=0; l<N; l++) {
          for (int k=0; k<M; k++) {
            tocopy[l][k] = arr[l][k];
          }
        }

        for (int j=0; j<2; j++) {
          x = start_i;
          y = start_j; 
          while (1) {
            x += three[i][j][0];
            y += three[i][j][1];
            if (x < 0 || x >= N || y<0 || y >= M || arr[x][y]==6) break;
            if (arr[x][y]==0) tocopy[x][y] = 7;
          }

        }

        cctv(tocopy, cur_cnt+1);
      }
      break;


    case 4:
     // cout<<"start_i: "<<start_i<<"start_j: "<<start_j<<endl;
      for (int i=0; i<4; i++) {
        memset(tocopy, 0, sizeof(tocopy));
        for (int l=0; l<N; l++) {
          for (int k=0; k<M; k++) {
            tocopy[l][k] = arr[l][k];
          }
        }

        for (int j=0; j<3; j++) {
          x = start_i;
          y = start_j; 
          while (1) {
            x += four[i][j][0];
            y += four[i][j][1];
            if (x < 0 || x >= N || y<0 || y >= M || arr[x][y]==6) break;
            if (arr[x][y]==0) tocopy[x][y] = 7;
          }

        }
     //   print_arr(tocopy);
        cctv(tocopy, cur_cnt+1);
      }
      break;

    case 5:
      memset(tocopy, 0, sizeof(tocopy));
      for (int j=0; j<N; j++) {
        for (int k=0; k<M; k++) {
          tocopy[j][k] = arr[j][k];
        }
      }
      for (int i=0; i<4; i++) {
        x = start_i;
        y = start_j;

        while (1) {
          x += one[i][0];
          y += one[i][1];

          if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == 6) break;
          if (arr[x][y] == 0 ) tocopy[x][y] = 7;
        }

      }
      cctv(tocopy, cur_cnt+1);
      break;
  }


}

int main() {
  cin >> N >> M;
  int i,j;
  int input[9][9];
  for (i=0; i<N; i++) {
    for (j=0; j<M; j++ ) {
      cin >> input[i][j];
      if (input[i][j] >= 1 && input[i][j] <= 5) {
        num_of_cctvs++;
        cctvs.push_back({input[i][j], i, j});
      }

    }
  }
  //cout<<"num of cctvs: "<<num_of_cctvs<<endl;
  cctv(input, 0);
  cout << m;

  return 0;
}
