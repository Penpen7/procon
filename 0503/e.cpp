#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  vector<int> A;
  cin >> N;
  int res= 0;
  rep(i, 0, N-1){
    int temp;
    cin >> temp;
    A.push_back(i);
  }
  rep(i, 0, N-1){
    rep(i,0,N-1){
      if(A[i]+A[j]=abs(i-j)) res++;
    }
  }
  cout << res;
  return 0;
}
