#include <bits/stdc++.h>
#define rep(i, z, n) for(ll i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  ll N;
  cin >> N;
  map<ll,ll> A,B;
  
  rep(i, 0, N-1){
    ll temp;
    cin >> temp;
    ll R=i+temp;
    ll L=i-temp;
    if(A.count(R)!=0){
      A[R]++;
    }else{
      A[R]=1;
    }
    if(B.count(L)!=0){
      B[L]++;
    }else{
      B[L]=1;
    }
  }
  ll sum=0;
  int
  for(pair<ll,ll> i:A){
    if(B.count(i.first)>0){
      sum+=B[i.first]*i.second;
    }
  }
  cout << sum << endl;
  return 0;
}
