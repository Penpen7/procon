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
// llの最大値2147483647~2E+9
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

  ll n,k; cin >> n >>k;
  vector<string> a=vector<ll>(n);
  vector<ll> time=vector<ll>(n+1,-1);
  vector<ll> mitisuzi;
  REP(i,n) cin >> a[i];
  ll v=0;
  mitisuzi.PB(0);
  do{
    time[v]=SIZE(mitisuzi); 
    mitisuzi.PB(a[v]);
    v=a[v]-1;
  }while(time[v]==-1); 
  ll c=SIZE(mitisuzi)-time[v];
  ll l=time[v];
  //cout << c << l;
  //for(int i:mitisuzi) cout << i << endl;
  if(k<=l) cout << mitisuzi[k] << endl;
  else{
    k=k-l;
    k%=c;
    cout << mitisuzi[l+k]<< endl;
  }
  

  return 0;
}
