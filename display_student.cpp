//make display_student 0
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

    FILE* fd=fopen(FILE_NAME,"r");
    struct Person p;

    fseek(fd,sizeof(int)+atoi(argv[1])*(sizeof(p.first_name)+sizeof(p.last_name)+sizeof(p.age)+sizeof(int)),SEEK_SET);
    fseek(fd,sizeof(int),SEEK_CUR);
    fread(p.first_name,sizeof(p.first_name),1,fd);
    fread(p.last_name,sizeof(p.last_name),1,fd);
    fread(&(p.age),sizeof(int),1,fd);

    printf("First Name: %s\n",p.first_name);

    printf("Last Name: %s\n",p.last_name);

    printf("Age: %d\n",p.age);
    fclose(fd);
}


