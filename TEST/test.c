#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define BUFFERSIZE 256

//int generateRandomInt() {
//    int rand1 = rand();
//    int rand2 = rand();
//    int randomInt = rand1 | (rand2 << 16);
//    // Combine two values to potentially cover a wider range
//    //Shifting rand2 to the left for 16 bits, and then use OR operator to combine them together, so potentiaolly
//    return randomInt;
//}

int cmdouput_to_txt(char *cmd, char *path) {
    char augcmd[BUFFERSIZE];
    snprintf(augcmd, sizeof(augcmd), "%s > %s", cmd, path);
    printf("%s",augcmd);
    return 1;
}

int main() {
    char cmd[] = "ping";
    char path[] = "cool\\nice";
    cmdouput_to_txt(cmd, path);
    return 0;
}
