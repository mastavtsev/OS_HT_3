#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fibonacci(int range) {
  int a = 0;
  int b = 1;
  int c;
  printf("Fibonacci:  ");
  while (a <= range) {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }
  printf("%d\n", a);
}

void factorial(int factor) {
  int res = 1;

  for (int i = 2; i <= factor; ++i) {
    res *= i;
  }
  printf("Factorial: %d\n", res);
}

int main(int argc, char **argv) {
  int num;
  if (argc == 2) { // [foo.exe, seed]
    num = atoi(argv[1]);
  } else { // exit with error
    return 1;
  }


  pid_t chpid = fork();
  if (chpid == -1) {
    printf("Incorrect fork syscall\n");
  } else if (chpid == 0) {
    factorial(num);
  } else {
    fibonacci(num);
  }
}
