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
  ll n,p; cin >> n >> p;
  vector<ll> s(n);
  vector<ll> mod(p,0);
  ll time2,time5=0;

  rep(i,n){
    char temp;
    cin >> temp;
    s[i] = temp-'0';
  }

  reverse(ALL(s));

  if(p==2 or p==5){
    ll res25=0;
    rep(i,n){
      if(s[i]%p==0) res25+=n-i;
    }
    cout << res25 << endl;
    return 0;
  }

  ll digit=1;
  ll sum=0;
  rep(i,n){
    sum+=s[i]*digit; 
    sum%=p;
    mod[sum]++;
    digit*=10;
    digit%=p;
  }
  ll res=mod[0];
  for(ll i:mod) res+=i*(i-1L)/2L;
  cout << res << endl;
  return 0;
}
