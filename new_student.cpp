//make new_student
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 64
#define FILE_NAME "persons.dat"

struct Person {
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

  FILE* fd=fopen(FILE_NAME,"r+");
  int id;

  fread(&id,sizeof(int),1,fd);

  fseek(fd,0,SEEK_END);
  fwrite(&id,sizeof(int),1,fd);
  fwrite(p.first_name,sizeof(p.first_name),1,fd);
  fwrite(p.last_name,sizeof(p.last_name),1,fd);
  fwrite(&(p.age),sizeof(p.age),1,fd);
  rewind(fd);
  id++;
  fwrite(&id,sizeof(int),1,fd);
  fclose(fd);
  return 0;
}
