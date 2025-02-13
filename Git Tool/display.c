#include "included lib & define.h"

void show_managing_repos() {
	printf("\n\nHere are the currently managing repos' paths:\n");
	FILE* file = fopen(MANAGING_REPO_TXT, "r");
	if (!check_if_fopen_successful(file)) {
		printf("****Error openning file at %s in show_managing_repos function.", MANAGING_REPO_TXT);
	}
	char buffer[BUFFER_SIZE];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
		printf("%s", buffer);
	printf("\n");
	printf("If want to change saved repos' directories, please go to %s to change manually.\n\n", MANAGING_REPO_TXT);
	fclose(file);
}

void show_menu() {
	printf("\n----1. Run `git add .` on chosen repositories.\n");
	printf("----2. Run `git commit -m \"\"` on chosen repositories.\n");
	printf("----3. Run `git push` on chosen repositories.\n");
	printf("----4. Run `git status` on all repositories.\n");
	printf("----5. Manage repositories\n");
	printf("----6. Exit program.\n");
}

int show_existing_git_status_output(const char* gitStatusOutputPath) {
	FILE* temp = fopen(gitStatusOutputPath, "r");
	if (!check_if_fopen_successful(temp)) {
		printf("****Error: Unable to open the git status output file at %s. Ensure that it exists and is accessible.\n", gitStatusOutputPath);
		return -1;
	}

	char output[BUFFER_SIZE];
	while (fgets(output, sizeof(output), temp) != NULL)
		printf("%s", output);

	fclose(temp);
	return 0;
}
