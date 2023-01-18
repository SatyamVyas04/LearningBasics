#include <stdio.h>
int search(int arr[], int n, int lim){
	n-=lim;
    for(int i=0; i<lim; i++){
        if(n==arr[i]){
            return 0; 
        }
    }
    return 1;
}
 
int recaman(int n, int arr[]){
    if(n==0){
        return 0;
    }else if(recaman(n-1, arr)>n && search(arr, recaman(n-1, arr), n)==1){
        return recaman(n-1, arr)-n;
    }else{
        return recaman(n-1, arr)+n;
    }
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int arr[n];
    printf("First %d terms of Recaman Series are ", n);
    for(int i = 1; i<=n; i++){
        int ans = recaman(i, arr);
        arr[i]=ans;
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}
