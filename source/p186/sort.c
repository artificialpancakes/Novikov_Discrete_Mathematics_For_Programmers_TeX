#include<stdio.h>

int main(){
        int n;
        scanf("%d", &n);
        int A[n];
        for(int i = 0; i < n; i++){
                scanf("%d", &A[i]);
        }
        for(int i = 1; i < n; i++)
                for(int j = n - 1; j >= i; j--)
                        if(A[j] < A[j - 1]){
                                A[j - 1] += A[j];
                                A[j] = A[j - 1] - A[j];
                                A[j - 1] -= A[j];
                        }
        for(int i = 0; i < n; i++)
                printf("%d", A[i]);
        return 0;
}
