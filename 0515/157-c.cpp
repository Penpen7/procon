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
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n,m; cin >> n >> m;
  // 右から数字を入れる
  int d[]={-1,-1,-1};
  REP(i,m){
    int digit, value; cin >> digit >> value; 
    if((d[n-digit]!=-1 and d[n-digit]!=value) or (n!=1 and digit==1 and value==0)){
      cout << -1 << endl;
      return 0;
    }
    d[n-digit]=value;
  }
  if(d[n-1]==-1) d[n-1]=1;
  int res=0;
  int temp=1;
  REP(i,n){
    if(d[i]!=-1)res+=d[i]*temp;
    temp*=10;
  }
  cout << res << endl;
  return 0;
}
