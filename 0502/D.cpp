#include <bits/stdc++.h>
#define rep(i, z, n) for(ll i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;
ll res(ll A,ll B,ll x){
    return  floor(double(A)/double(B)*double(x))-A*floor(double(x)/double(B));

}
int main(){
  ll A,B,N;
  ll x;
  cin >> A >> B >> N;
  ll max_res=0;
  if(N<B){
    cout << res(A,B,N) << endl;
    return 0;
  }else{
    cout << max(res(A,B,B-1),res(A,B,B)) << endl;
    return 0;
  }
  return 0;
}

