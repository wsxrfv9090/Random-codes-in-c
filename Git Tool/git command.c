#include "included lib & define.h"

int git_status() {
	FILE* repofile = fopen(MANAGING_REPO_TXT, "r");
	if (!check_if_fopen_successful(repofile)) {
		perror("****Error openning file at %s", MANAGING_REPO_TXT);
		return -1;
	}
	char repo[BUFFER_SIZE];
	while (fgets(repo, sizeof(repo), repofile) != NULL) {
		remove_newline_in_input(repo);
		char repocp[BUFFER_SIZE];
		strcpy_s(repocp, sizeof(repocp), repo);
		char* disk_letter = NULL;
		char* string_ptr = NULL;
		disk_letter = strtok_s(repocp, ":", &string_ptr);
		if (disk_letter == NULL) {
			printf("Disk letter not found in the path: %s\n", repo);
			break;
		}
		char cmd_buffer[BUFFER_SIZE];
		char output_temp_status[BUFFER_SIZE];
		system("cls");
		printf("\nCurrent Directory: %s\n", repo);
		snprintf(cmd_buffer, sizeof(cmd_buffer), "%s: && cd %s && git status", disk_letter, repo);
		system(cmd_buffer);
		//output to a temp file
		//fopen the temp file for information
		//options:
		// 1. untracked
		// 2. waiting to be committed
		// 3. everything's fine
		// 4. to be pushed.
		// 5. not a git repo
		//fclose
		printf("\n");
		printf("Press enter to check the next repository.");
		char input1[BUFFER_SIZE];
		fgets(input1, sizeof(input1), stdin);
		if (strcmp(input1, "\n") == 0)
			system("cls");
	}
// Add changes to the managing repo file.
// loop and iterate through the file and printf, then remove temp file here.
// show a message of which ones are which.
//
	return 0;
}