#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  set<int> sunuke;
  int n,k;
  cin >> n >> k;
  rep(i, 1, k){
    int d;
    cin >> d;
    rep(j,1,d){
      int temp;
      cin >> temp;
      sunuke.insert(temp); 
    }
  }
  cout << n-sunuke.size() << endl;
  return 0;
}
