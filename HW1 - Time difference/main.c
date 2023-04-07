#include <stdio.h>
#include <sys/time.h>

int main(void) {
  struct timeval tv;

  // get the current time (moment 1)
  gettimeofday(&tv, NULL);
  int start = tv.tv_usec;

  // a task that takes time
  int cnt = 0;
  for (int i = 0; i < 1000; i++) {
    cnt++;
  }
  printf("cnt: %d\n", cnt);

  // get the current time (moment 2)
  // sleep(1);
  gettimeofday(&tv, NULL);
  int end = tv.tv_usec;

  // calculate the time difference bewteen the two moments in micro seconds
  int diff = end - start;

  // print the result (the time difference)
  printf("the time difference: %d usec\n", diff);

  return 0;
}
