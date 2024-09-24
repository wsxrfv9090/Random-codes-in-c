#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flushDNS() {
    system("ipconfig /flushdns");
}

float getAverageLatency(const char* address) {
    char command[100];
    snprintf(command, sizeof(command), "ping -n 4 %s", address);
    FILE* pingOutput = _popen(command, "r");
    if (pingOutput == NULL) {
        fprintf(stderr, "Failed to execute command\n");
        return -1;
    }

    char line[256];
    float avgLatency = -1;
    while (fgets(line, sizeof(line), pingOutput) != NULL) {
        // This line format might change based on your locale and ping command version
        if (strstr(line, "Average") != NULL) {
            char* avgStr = strstr(line, "=");
            if (avgStr && sscanf(avgStr + 1, "%fms", &avgLatency)) {
                break;
            }
        }
    }
    _pclose(pingOutput);

    return avgLatency;
}

int main() {
    float googleLatency = getAverageLatency("google.com");
    float baiduLatency = getAverageLatency("baidu.com");

    printf("Google.com Average Latency: %.2fms\n", googleLatency);
    printf("Baidu.com Average Latency: %.2fms\n", baiduLatency);

    if (googleLatency > 60 || baiduLatency > 60) {
        printf("High latency detected, flushing DNS...\n");
        flushDNS();
    } else {
        printf("Latency is normal, no action taken.\n");
    }

    return 0;
}