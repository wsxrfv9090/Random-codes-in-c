#include "included lib & define.h"

int git_status() {
	const char* not_a_git_repo = "not a git repository";
	const char* untracked = "Untracked files";
	const char* uncommitted1 = "Changes to be committed";
	const char* uncommitted2 = "ahead of";

	FILE* repofile = fopen(MANAGING_REPO_TXT, "r");
	if (!check_if_fopen_successful(repofile)) {
		printf("****Error openning file at %s", MANAGING_REPO_TXT);
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
			printf("****Disk letter not found in the path: %s\n", repo);
			break;
		}
		char cmd_buffer[BUFFER_SIZE];
		char output_temp_status[BUFFER_SIZE];
		system("cls");
		printf("\nCurrent Directory: %s\n", repo);
		snprintf(cmd_buffer, sizeof(cmd_buffer), "%s: && cd %s && git status", disk_letter, repo);
		cmdoutput_to_path(cmd_buffer, GIT_STATUS_OUTPUT_TXT);
		FILE* resultfile = fopen(GIT_STATUS_OUTPUT_TXT, "r");
		if (!check_if_fopen_successful(resultfile)) {
			printf("****Error openning file at %s", GIT_STATUS_OUTPUT_TXT);
			return -1;
		}
		char test_buffer[BUFFER_SIZE];
		while (fgets(test_buffer,sizeof(test_buffer),resultfile) != NULL) {
			if (strstr(test_buffer, not_a_git_repo)) {

			}
		}
		fclose(resultfile);
		if (remove(GIT_STATUS_OUTPUT_TXT) != 0)
			printf("****Unable to remove tmp ping result file from %s\n", GIT_STATUS_OUTPUT_TXT);
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
		char input1[BUFFER_SIZE];
		while (1) {
			printf("Press enter to check the next repository.\n");
			fgets(input1, sizeof(input1), stdin);
			if (strcmp(input1, "\n") == 0) {
				system("cls");
				break;
			}
		}
	}
// Add changes to the managing repo file.
// loop and iterate through the file and printf, then remove temp file here.
// show a message of which ones are which.
//
	return 0;
}