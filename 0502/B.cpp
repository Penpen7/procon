#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  ll X;
  ll price;
  ll year;
  cin >> X;

  price = 100;
  year=0;
  while(1){
   if(price>=X){
     break;
   }
   price=price*1.01;
   year++;
  }
  cout << year << endl;
  return 0;
}
