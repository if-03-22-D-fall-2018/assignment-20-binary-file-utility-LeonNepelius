//make list_all_students

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

    FILE* fd=fopen(FILE_NAME,"r");
    struct Person p;

    fseek(fd,sizeof(int),SEEK_SET);
    printf("%10s %-32s %-32s %-3s\n", "Id","First Name","Last Name","Age");
    int count = fread(&(p.id),sizeof(int),1,fd);
    while (count > 0) {
        fread(p.first_name,sizeof(p.first_name),1,fd);
        fread(p.last_name,sizeof(p.last_name),1,fd);
        fread(&(p.age),sizeof(int),1,fd);
        printf("%010d %-32s %-32s %-3d\n", p.id,p.first_name,p.last_name,p.age);
        count = fread(&(p.id),sizeof(int),1,fd);
    }
    fclose(fd);
  return 0;
}
