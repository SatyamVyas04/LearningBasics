// Assume that there is a set of data consisting of records representing people. For each person,
// there is a name (20 characters), sex (M or F) and age (an integer in the range 0 to 100). Write
// a program which processes these records and outputs the number of men and the number of
// women.
#include <stdio.h>
#include <string.h>
typedef struct{
    char name;
    char sex;
    int age;
}person;

int main(){
    person arr = {'a', 'm', 18};
    printf("%c\t", arr.name);
    printf("%d\t", arr.age);
    printf("%c\n", arr.sex);

}