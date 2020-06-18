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
vector<ll> dres;
vector<vector<ll>> a;
vector<ll> c;
ll res=INF;
ll n,m,x;
void dfs(vector<bool> isused, ll d){ 
  if(d>n){
    dres = vector<ll>(m,0);
    ll cost=0;
    REP(i,n){
      if(isused[i+1]){
        REP(j,m){
          dres[j]=dres[j]+a[i][j];
        } 
        cost+=c[i];
      }
    }
    REP(i,m){
      if(dres[i]<x) return;
    }
    res = min(res,cost);
    return;
  }
  isused.push_back(false);
  dfs(isused,d+1);
  isused.back()=true;
  dfs(isused,d+1);
  
  return;
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m >> x;
  a = vector<vector<ll>>(n,vector<ll>(m));
  c = vector<ll>(n);
  REP(i,n){
    ll temp2; cin >> temp2;
    c[i]=temp2;
    REP(k,m){
      ll temp; cin >> temp;
      a[i][k] =temp;
    }
  }
  dfs(vector<bool>(1,false), 0);
  if(res==INF){
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;
  
  return 0;
}
