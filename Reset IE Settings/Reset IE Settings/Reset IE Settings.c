#include <stdlib.h>
#include <stdio.h>

int main() {
    int result = system("RunDll32.exe InetCpl.cpl,ResetIEtoDefaults");
    if (result == 0) {
        printf("Internet Explorer settings reset successfully.\n");
    }
    else {
        printf("Failed to reset Internet Explorer settings.\n");
    }
    Sleep(1000);
    return result;
}