#include <bits/stdc++.h>
#define rep(i, z, n) for(ll i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  vector<ll> H;
  set<ll> good;
  ll n,m;
  cin >> n >> m;
  H=vector<ll>(n);
  rep(i, 0, n-1){
    cin >> H[i];
    good.insert(i);
  }
  rep(i, 1, m){
    ll a,b;
    cin >> a;
    cin >> b;
    if(H[a-1]>H[b-1]){
      good.erase(b-1); 
    }else if(H[a-1]==H[b-1]){
      good.erase(b-1);
      good.erase(a-1);
    }else{
      good.erase(a-1);
    }
  }
  
  cout << good.size() << endl;
  return 0;
}
