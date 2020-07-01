#include <stdio.h>

//ユーグリッドの互除法を用いて2つの正の整数の最大公約数を求める関数
int gcd(int x, int y)
{
  int temp = 0;
  while (y != 0) {
    x = x % y;
    temp = x;
    x = y;
    y = temp;
  }
  return x;
}

int main(void)
{
  int x, y;
  int n = 0;

  //1が入力されたらループを抜ける
  while (1) {
    printf("2つの正整数x,yを入力 ");
    scanf("%d", &x);
    scanf("%d", &y);
    if (gcd(x, y) == 1) {
      printf("%dと%dの最大公約数は1なので互いに素である\n", x, y);
    } else {
      printf("%dと%dの最大公約数は%dなので互いに素ではない\n", x, y, gcd(x, y));
    }
    printf("終了しますか? ");
    scanf("%d", &n);
    if (n == 1) {
      break;
    }
  }
  return 0;
}
