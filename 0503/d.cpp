#include <bits/stdc++.h>
#define rep(i, z, n) for(ll i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  ll x;
  cin >> x;

  rep(i, 0, 1000){
    for(ll j=-1000;j<=1000;j++){
      ll sum = i*i*i*i*i-j*j*j*j*j;
      if(sum ==x){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}
