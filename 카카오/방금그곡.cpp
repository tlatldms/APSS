#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
struct PP  {
    PP(int x, int y, string rr, string ss) : A(x), B(y), result(rr), oo(ss) {}
    int A;
    int B;
    string result;
    string oo;
};

vector<string> sharps = {"C#","D#","F#","G#", "A#"};
vector<string> rp = {"Y","U","I","O","P"};
vector<PP> info;
bool comp(PP a, PP b) {
    if (a.A == b.A) return a.B < b.B;
    return a.A > b.A;
}
std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to){
    size_t start_pos = 0; //string처음부터 검사
    while((start_pos = str.find(from, start_pos)) != std::string::npos)  //from을 찾을 수 없을 때까지
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    for (int i=0; i<musicinfos.size(); i++) {
        
        string str = musicinfos[i];
        stringstream ss(str);
        string temp;

        vector<string> internal;
       
        
        while (getline(ss, temp,',')) {
            internal.push_back(temp);
        }
         for (int j=0; j<5; j++) {
            internal[3] = ReplaceAll(internal[3], sharps[j], rp[j]);
        }
        int f_h, f_m, b_h, b_m;
        f_h= stoi(internal[0].substr(0,2));
        f_m = stoi(internal[0].substr(3,2));       
        
        b_h= stoi(internal[1].substr(0,2));
        b_m = stoi(internal[1].substr(3,2));       
        int music_len = (b_h-f_h)*60 + (b_m-f_m);
        
        
        int mq = music_len / internal[3].size();
        int mr = music_len % internal[3].size();
        string origin="";
        for (int j=0; j<mq; j++) {
            origin += internal[3];
        }
        origin += internal[3].substr(0, mr);
        PP ppp = {music_len, i, origin, internal[2]};
        info.push_back(ppp);
      
        
    }
   for (int j=0; j<5; j++) {
        m = ReplaceAll(m, sharps[j], rp[j]);
    }
    
    sort(info.begin(), info.end(), comp);
    
    for (int j=0; j<info.size(); j++) {
        if ((info[j].result).find(m) != -1) {
            answer = info[j].oo;
            break;
        }
    }
    
    //if (origin.find(m) != string::npos)
    
    
    return answer;
}