#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int generateRandomInt() {
//    int rand1 = rand();
//    int rand2 = rand();
//    int randomInt = rand1 | (rand2 << 16);
//    // Combine two values to potentially cover a wider range
//    //Shifting rand2 to the left for 16 bits, and then use OR operator to combine them together, so potentiaolly
//    return randomInt;
//}

int main() {
    printf("%d", RAND_MAX);
    return 0;
}
