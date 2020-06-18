#include <bits/stdc++.h>
#define REPZ(i, z, n) for(decltype(n) i = (z); i < (n); i++)
#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
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
void dfs(){ 
  return;
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,x,y; cin >> n >> x >> y;
  vector<int> res(n, 0);
  REPZ(i, 1, n){
    REPZ(j,i+1, n+1){
      int dis;
      // i<=x y<=j A-C
      if(i<=x and y<=j) dis=min(j-i,x-y+j-(i-1));
      // i<=x<j<y A-B
      else if(i<=x and x<j and j<y) dis=min(j-i, x+y+1-i-j);
      // x<i<y x<j<y B-B
      else if(x<i and i<y and x<j and j<y) dis=min(j-i,i-x+y-j+1 );
      // x<i<y y<=j B-C
      else if(x < i and i < y and y<=j) dis=min(j-i, i+j+1-x-y);
      else dis=j-i;
//cout << i <<"-"<< j << " "<< dis << endl;
      res[dis]++;
    }
  }
  REPZ(i, 1, n){
    cout << res[i] << endl;
  }
  return 0;
}

