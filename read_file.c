#include <stdio.h>

#define MAX_SIZE 64
#define FILE_NAME "persons.dat"
#define CACHE_SIZE 6

struct Person {
  int id;
  char first_name[MAX_SIZE];
  char last_name[MAX_SIZE];
  int age;
};

int main(int argc, char const *argv[]) {
  FILE* fd = fopen(FILE_NAME, "r");
  struct Person p[CACHE_SIZE];

  int n = fread(p, sizeof(struct Person), CACHE_SIZE, fd);
  printf("%d items read\n", n);

  for (int i = 0; i < CACHE_SIZE; i++) {
    printf("%s %s %d\n", p[i].first_name, p[i].last_name, p[i].age);
  }
  // while (n > 0) {
  //   printf("%s %s %d\n", p.first_name, p.last_name, p.age);
  //   n = fread(&p, sizeof(struct Person), 1, fd);
  // }
  return 0;
}
