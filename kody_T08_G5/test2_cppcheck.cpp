#include <iostream>
int main() {
    int i = 0;
    while (i < 10) {  // infinite loop (brak ++i)
        std::cout << i << std::endl;
    }
    int a = INT_MAX;
    a = a + 1;  // integerOverflow
    return 0;
}
