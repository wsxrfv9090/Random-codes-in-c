#include "included lib & define.h"

void show_managing_repos() {
	printf("\n\nHere are the currently managing repos' paths:\n");
	FILE* file = fopen(MANAGING_REPO_TXT, "r");
	if (!check_if_fopen_successful(file)) {
		printf("****Error openning file at %s.", MANAGING_REPO_TXT);
		return -1;
	}
	char buffer[BUFFER_SIZE];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
		printf("%s", buffer);
	printf("\n");
	printf("If want to change saved repos' directories, please go to %s to change manually.\n\n", MANAGING_REPO_TXT);
	fclose(file);
}