//start 처리 아직 안했음 !!! 

#include <iostream>
#include <vector>

using namespace std;

int N, L;
int input[101][101];

int fun(int _case) {
  int i,j, possible, road=0, prev_level, now_level, flag, same_cnt, low_cnting; 
  for (i=0; i<N; i++) {
    flag = 0; possible=1; same_cnt =0;
    if (_case) prev_level = input[i][0];
    else prev_level = input[0][i];
    
    for (j=0; j<N; j++) {
      //cout<<"now_i: "<<i<<"now_j:"<<j<<endl;
      if (_case) now_level = input[i][j];
      else now_level = input[j][i];
      if (flag == 0) { //경사 시작 전
        if (prev_level == now_level) same_cnt++;
        else { //처음으로 다른숫자 만남
          int tmp_cnt = same_cnt;
          same_cnt = 1;
          if ((prev_level-now_level) == -1) { //오르막길
            if (tmp_cnt < L ) {//경사로 놓을 수 없음
              //cout << "tmp_cnt < L case" << endl;
              possible = 0; break;
            } //else cout<<"올라왔음"<<endl;
          } else if ((prev_level-now_level) == 1) { //내리막길
            if (L == 1) {
              prev_level = now_level; same_cnt=0; continue;
            }
            low_cnting = 1;
            flag=1;
          } else { //갑자기 점프
            possible = 0; break;
          }
        }
      } else {//flag==1, 내리막 상태
        if (prev_level == now_level) { //내리막 상태 유지?
          low_cnting++;
          if (low_cnting == L) { //L만큼 내려온거 확인했을 때
            //cout << "L만큼 내려옴" << endl;
            flag=0; low_cnting=0; same_cnt = 0;
          } //else 아직일때 처리할필요X
        }
       else { //내리막 상태 깨짐
         //cout << "내리막 상태 깨짐" <<endl;
         possible=0; break;
       }
      }
      prev_level = now_level;
    }
    if (possible && !flag) {
      //cout<<"possible in "<<i<<endl;
      road++;
    }
  }
  //cout << "case"<<_case<<": "<<road<<"\n\n\n";
  return road;
}

int main() {
  cin >> N >> L;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> input[i][j];
  }
  
  cout<<fun(1)+fun(0);
  return 0;
}
