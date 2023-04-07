#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int Fib_dnc(int n);  // Divide and Conquer
int Fib_dp(int n);   // Dynamic Programming
int Fib_dp_m(int n); // Dynamic Programming with Memoization
int GetCurrentUsec();
int *fibTable;
int *list;

int main(void) {

  int n = 30;

  // table initialization
  fibTable = (int *)malloc(sizeof(int) * (n + 1));
  list = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    list[i] = -1;

  int t1, t2, result;

  // Divide and Conquer
  t1 = GetCurrentUsec();
  result = Fib_dnc(n);
  t2 = GetCurrentUsec();
  printf("Fibonacci number for %d is: %d\n", n, result);
  printf("Divide and Conqure took %d usec.\n\n", t2 - t1);

  // Dynamic Programming
  t1 = GetCurrentUsec();
  result = Fib_dp(n);
  t2 = GetCurrentUsec();
  printf("Fibonacci number for %d is: %d\n", n, result);
  printf("Dynamic Programming took %d usec.\n\n", t2 - t1);

  // Dynamic Programming with memoization
  t1 = GetCurrentUsec();
  result = Fib_dp_m(n);
  t2 = GetCurrentUsec();
  printf("Fibonacci number for %d is: %d\n", n, result);
  printf("Dynamic Programming with memoization took %d usec.\n\n", t2 - t1);

  return 0;
}

//////////////////////////////
//  write your answer below //
//////////////////////////////
/*

for n = 1
Fibonacci number is : [1].
Divide and Conquer took : [0] usec.
Dynamic Programming took : [0] usec.
Dynamic Programming with Memoization took : [0] usec.

for n = 10
Fibonacci number is : [55]
Divide and Conquer took : [1] usec.
Dynamic Programming took : [0] usec.
Dynamic Programming with Memoization took : [0] usec.

for n = 20
Fibonacci number is : [6765]
Divide and Conquer took : [28] usec.
Dynamic Programming took : [0] usec.
Dynamic Programming with Memoization took : [0] usec.

for n = 30
Fibonacci number is : [832040]
Divide and Conquer took : [3820] usec.
Dynamic Programming took : [0] usec.
Dynamic Programming with Memoization took : [1] usec.

*/
//////////////////////////////

// Deivide and Conquer
int Fib_dnc(int n) {
  if (n < 2)
    return n;
  else

    // Your code here
    return Fib_dnc(n - 1) + Fib_dnc(n - 2);
}

// Dynamic Programming
int Fib_dp(int n) {
  int i;
  fibTable[0] = 0;
  fibTable[1] = 1;
  // Your code here
  for (int i = 2; i <= n; i++) {
    fibTable[i] = fibTable[i - 1] + fibTable[i - 2];
  }
  return fibTable[n];
}

// Dynamic Programming with Memoization
int Fib_dp_m(int n) {
  int fib, f1, f2;
  if (n < 2)
    fib = n;
  else {

    // Your code here
    // n-1
    if (list[n - 1] != -1) {
      f1 = list[n - 1];
    }

    else {
      f1 = Fib_dp_m(n - 1);
      list[n - 1] = f1;
    }

    // n-2
    if (list[n - 2] != -1) {
      f2 = list[n - 2];
    }

    else {
      f2 = Fib_dp_m(n - 2);
      list[n - 2] = f2;
    }

    // (n-1) + (n-2)
    fib = f1 + f2;
  }
  return fib;
}

int GetCurrentUsec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_usec;
}
