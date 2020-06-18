#include <bits/stdc++.h>
#define REPZ(i, z, n) for(int i = (z); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
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
ll res=0LL;
using namespace std;
void dfs(ll d, ll v, int flag,ll n){ 
  if(v>n) return;
  if(flag==(1<<3 | 1<<5 | 1<<7)){
    res++;
  }
  
  dfs(d+1, 10*v+3, flag | 1<<3, n);
  dfs(d+1, 10*v+5, flag | 1<<5, n);
  dfs(d+1, 10*v+7, flag | 1<<7, n);
  return;
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n; cin >> n;
  dfs(0,0,0, n);
  cout << res << endl;
  
  
  return 0;
}
