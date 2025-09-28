#include <stdio.h>
void hanoi(int n, char a, char c, char b) {
    if (n==0) {
        return;
    }
    //move n-1 disks from a to b using c as auxiliary 
    hanoi(n-1,a,b,c);
    //move nth disk from a to c 
    printf("%d disks moved from %c to %c\n",n,a,c);
        //move n-1 disks from b to c using a as auxiliary 
    hanoi(n-1,b,c,a);
}
int main() {
    // Write C code here
    int num = 6;
    hanoi(num,'A','C','B');
    return 0;
}