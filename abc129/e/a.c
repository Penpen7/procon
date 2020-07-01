#include <stdio.h>

int main()
{
  char str1[32], str2[32], str3[32], txt[96];
  printf("str1: ");
  scanf("%s", str1);
  printf("str2: ");
  scanf("%s", str2);
  printf("str3: ");
  scanf("%s", str3);

  {
    int i;
    char c;
    for (i = 0, c = str1[0]; c != '\0'; i++, c = str1[i]) {
      txt[3 * i + 0] = str1[i];
      txt[3 * i + 1] = str2[i];
      txt[3 * i + 2] = str3[i];
    }
  }

  printf("%s\n", txt);
  return 0;
}
