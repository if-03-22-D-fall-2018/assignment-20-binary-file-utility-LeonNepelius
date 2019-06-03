//make init
#include <stdio.h>
#define FILE_NAME "persons.dat"

int main(int argc, char const *argv[]) {

  FILE* fd = fopen(FILE_NAME, "w");
  int id = 1;
  fwrite(&id, sizeof(int), 1, fd);
  fclose(fd);
  return 0;
}
