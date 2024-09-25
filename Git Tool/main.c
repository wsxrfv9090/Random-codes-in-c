#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REPOS 10
char* repos[MAX_REPOS] = {
    "path/to/repo1",
    "path/to/repo2",
    // Add more repositories as needed
};

void run_command_in_repo(const char* repo, const char* command) {
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "cd %s && %s", repo, command);
    system(cmd);
}


int main() {
    char input[256];

    while (1) {
        printf("Enter command (git status, git add, git commit, git push, exit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline

        if (strcmp(input, "exit") == 0) break;

        for (int i = 0; i < MAX_REPOS && repos[i] != NULL; i++) {
            if (strncmp(input, "git status", 10) == 0) {
                printf("Status for %s:\n", repos[i]);
                run_command_in_repo(repos[i], "git status");
            }
            else if (strncmp(input, "git add", 8) == 0) {
                run_command_in_repo(repos[i], "git add .");
            }
            else if (strncmp(input, "git commit", 10) == 0) {
                char commit_message[256];
                printf("Enter commit message: ");
                fgets(commit_message, sizeof(commit_message), stdin);
                commit_message[strcspn(commit_message, "\n")] = 0; // Remove newline
                run_command_in_repo(repos[i], commit_message);
            }
            else if (strncmp(input, "git push", 8) == 0) {
                int result = run_command_in_repo(repos[i], "git push");
                if (result != 0) {
                    FILE* file = fopen("push_failed.txt", "a");
                    fprintf(file, "%s push failed\n", repos[i]);
                    fclose(file);
                }
            }
        }
    }
    return 0;
}
