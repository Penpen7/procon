#include <bits/stdc++.h>
#define REPZ(i, z, n) for(decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for(decltype(n) i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) (*max_element(all(v)))
#define MIN(v) (*min_element(all(v)))
#define INF 1000000000000 //1E+12
#define MOD 1000000007    //合同式の法

// 略
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define READ cin >>
#define PRINT cout <<

typedef long long ll;
typedef unsigned long long ul;
// 1s間で可能なループ回数2E+8回
// intの最大値2147483647~2E+9
// long longの最大値9223372036854775807〜9E+18
// 総和accumulate
// 単純リストvector<> push_back
// 連想配列map<key,value> insert,
// pair キーとバリューを格納 firstとsecondでアクセス
// 小数点指定 setprecision()
// to_string<->stoi
// stoll(longlong)
// stod(double)
// 大文字65-90(-32)
// 小文字97-122(+32)
using namespace std;
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s; cin >> s;
  int q; cin >> q;
  vector<char> l,r;
  bool parity = false;
  rep(i, q){
    int mode; cin >> mode;
    if(mode==1){
      parity = !parity; 
    }else{
      int b_e;char c; cin >> b_e >> c;
      bool lr = (b_e==1);
      if(parity){
        // RL
        if(lr) r.push_back(c);
        else l.push_back(c);
      }else{
        if(!lr) r.push_back(c);
        else l.push_back(c);
      }
    }
  }
  if(parity){
      reverse(ALL(r)); reverse(ALL(s));
  }
  else reverse(ALL(l));
  
  if(parity) for(char i:r) cout << i;
  else for(char i:l) cout << i;
  cout << s;
  if(parity) for(char i:l) cout << i;
  else for(char i:r) cout << i;
  cout << endl;
  return 0;
}
