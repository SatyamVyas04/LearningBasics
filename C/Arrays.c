#include <stdio.h>
#include <conio.h>

int main(){
    // there are no strings in C. Only character array
    // just change the datatype below to make an array
    // of one type values/elements
    int array[5] = {0, 0, 0, 0, 0};
    array[0] = inp(0);
    array[1] = inp(1);
    array[2] = inp(2);
    array[3] = inp(3);
    array[4] = inp(4);
    printf("[%d, ", array[0]);
    printf("%d, ", array[1]);
    printf("%d, ", array[2]);
    printf("%d, ", array[3]);
    printf("%d]", array[4]);
    return 0;
}

int inp(int index){
    int val;
    printf("Enter %d number in the array: ", index);
    scanf("%d", &val);
    return val;

}