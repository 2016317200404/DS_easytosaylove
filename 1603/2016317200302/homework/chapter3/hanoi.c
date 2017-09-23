#include<stdio.h>
int counter = 0;
void hanoi(int n, char a, char b, char c) {
  if (n <= 1)
    printf("%d.%c--->%c\n", ++counter, a, c);
  else {
    hanoi(n - 1, a, c, b);
    printf("%d.%c--->%c\n", ++counter, a, c);
    hanoi(n - 1, b, a, c);

  }
}

int main() {
  int n;

  scanf("%d", &n);
  hanoi(n, 'a', 'b', 'c');
  return 0;

}