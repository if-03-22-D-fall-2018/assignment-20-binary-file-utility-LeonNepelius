#include <stdio.h>

#define MAX_SIZE 64
#define FILE_NAME "persons.dat"

struct Person {
  int id;
};

int main(int argc, char const *argv[]) {

  FILE* fd = fopen(FILE_NAME, "w");
  struct Person p;
  p.id = 1;
  fwrite(&p, sizeof(struct Person), 1, fd);
  fclose(fd);
  return 0;
}
