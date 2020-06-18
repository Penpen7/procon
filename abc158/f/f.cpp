#include <bits/stdc++.h>
#define repz(i, z, n) for(decltype(n) i = (z); i < (n); i++)
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
// mod:1E+9 + 7
const ll mod = 1000000000+7;
using namespace std;
ll modpow(ll a, ll n){
  ll res=1;
  while(n>0){
    if(n & 1) res = res*a%mod;
    a = a*a%mod;
    n >>= 1;
  }
  return res;
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n, k; cin >> n >> k;

  vector<ll> dp(k+1,0);
  for(ll i=k;i>=1;i--){
    dp[i]=modpow(k/i,n);
    for(ll j=2*i;j<=k;j+=i) dp[i]-=dp[j];
    dp[i]%=mod;
  }
  ll res = 0;
  for(ll i=1;i<=k;i++){
    res+=i%mod*dp[i];
    res%=mod;
  }
  cout << res << endl;
  return 0;
}
