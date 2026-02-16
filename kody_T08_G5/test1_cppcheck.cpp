#include <stdio.h>
int main() {
    int arr[5];
    arr[5] = 10;  // arrayIndexOutOfBounds
    int *ptr = NULL;
    *ptr = 42;    // nullPointer
    int x; printf("%d\n", x);  // uninitializedVariable
    return 0;
}