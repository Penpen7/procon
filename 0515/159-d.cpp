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
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll n; cin >> n;

  vector<ll> a(n,0);
  vector<ll> v(n+1,0);
  vector<ll> adjust(n+1,0);

  REP(i,n){
    cin >> a[i];
    v[a[i]]++;
  }
  //for(ll i:a) cout << "a" << i << endl;
  ll sum=0;
  REPZ(i,1,n+1){
    ll temp=v[i]*(v[i]-1)/2;
    sum+=temp;
    adjust[i]=(-temp);
    if(v[i]>2) adjust[i]+=(v[i]-1)*(v[i]-2)/2;
    //cout << i << " " << temp << " " << adjust[i] << endl;
  }
  REP(i,n){
    cout << sum+adjust[a[i]] << endl;
  }

  
  return 0;
}
