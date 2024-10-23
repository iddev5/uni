#include <stdio.h>
#include <string.h>
#include <ctype.h>

void dec2base(int dec, int base, char *res) {
  int i = 0;
  while (dec > 0) {
    int rem = dec % base;
    if (rem > 9)
      res[i] = 'A' + (rem - 10);
    else
      res[i] = '0' + rem;
    dec /= base;
    i++;
  }

  int new_len = i;
  char rev[new_len + 1];

  for (i = 0; i < new_len; i++)
    rev[i] = res[new_len - i - 1];
  rev[i] = 0;

  strcpy(res, rev);
}

int base2dec(char num[], int base) {
  int b = 1, res = 0, len = strlen(num);
  for (int i = len - 1; i >= 0; i--) {
    int temp;
    if (isalpha(num[i])) temp = (num[i] - 'A') + 10;
    else temp = num[i] - '0';
    res += temp * b;
    b *= base;
  }
  return res;
}

int main() {  
  int inpb, outb;
  printf("Enter input base (2, 8, 10, 16): ");
  scanf("%d", &inpb);
  
  printf("Enter output base (2, 8, 10, 16): ");
  scanf("%d", &outb);

  if (inpb == outb) {
    printf("Input base cannot be same as output base\n");
    return 0;
  } else if (inpb == 10) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    char res[32];
    dec2base(num, outb, res);
    printf("%d converted to base %d = %s\n", num, outb, res);
  } else {
    char num[32];
    printf("Enter number: ");
    scanf("%s", num);

    if (outb == 10) {
      int res = base2dec(num, inpb);
      printf("%s converted to base %d = %d\n", num, outb, res);
    } else {
      char res[32];
      dec2base(base2dec(num, inpb), outb, res);
      printf("%s converted to base %d = %s\n", num, outb, res);
    }
  }
  return 0;
}
