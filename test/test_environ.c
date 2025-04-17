#include <stdio.h>


int main() {
  extern char **environ;
  char **s = environ;

  for (; *s; s++) {
    printf("%s\n", *s);
  }

  return 0;
}
