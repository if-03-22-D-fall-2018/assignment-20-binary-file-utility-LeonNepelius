#include <stdio.h>

#define MAX_SIZE 64
#define FILE_NAME "persons.dat"

struct Person {
  int id;
  char first_name[MAX_SIZE];
  char last_name[MAX_SIZE];
  int age;
};



int main(int argc, char const *argv[]) {
  struct Person p;

  printf("Enter your name: ");
  scanf("%s", p.first_name);
  printf("Enter your last name: ");
  scanf("%s", p.last_name);
  printf("Enter age: ");
  scanf("%d", &(p.age));
  FILE* fd = fopen(FILE_NAME, "w");
  fwrite(&p, sizeof(struct Person), 1, fd);
  fclose(fd);
  return 0;
}
