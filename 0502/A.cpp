#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  int K, A, B;
  cin >> K;
  cin >> A >> B;

  rep(i,A,B){
    if(i%K==0){
      cout << "OK" << endl;
      return 0;
    }
  }
  cout << "NG" <<endl;
  return 0;
}
