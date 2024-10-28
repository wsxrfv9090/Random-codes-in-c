#include "included lib & define.h"

int check_if_fopen_successful(FILE* file) {
	if (!file) {
		printf("****Error opening file.\n");
		return 0;
	}
	return 1;
}

int ping_github()
{
	printf("Pinging \"github.com\".\n");
	char cmd[BUFFER_SIZE];
	char Ping_Result_File[BUFFER_SIZE];
	snprintf(Ping_Result_File, sizeof(Ping_Result_File), "%s\\Ping_Result.txt", WORKING_DIRECTORY);
	strcpy_s(cmd, sizeof(cmd), "ping github.com");
	cmdoutput_to_path(cmd, Ping_Result_File);

	FILE* file = fopen(Ping_Result_File, "r");
	if (!check_if_fopen_successful(file)) {
		perror("****Error openning file at %s", Ping_Result_File);
		return -1;
	}
	char buffer[BUFFER_SIZE];
	const char* ping_success = "Received = 4";
	const char* average_latency_prefix = "Average =";
	int ping_successful = 0;
	int average_latency = 0;

	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		if (strstr(buffer, ping_success) != NULL) {
			ping_successful = 1;
		}
		if (strstr(buffer, average_latency_prefix) != NULL && ping_successful == 1) {
			char latency_value_line[BUFFER_SIZE];
			if (strncpy_s(latency_value_line, sizeof(latency_value_line), buffer, _TRUNCATE) != 0) {
				printf("****Failed to copy latency value line.\n");
			}
			char* ptr = latency_value_line;
			while (*ptr && !isdigit(*ptr))
				ptr++;
			char* latency_value = ptr;
			while (*ptr && isdigit(*ptr))
				ptr++;
			*ptr = '\0';
			if (sscanf_s(latency_value, "%d", &average_latency) != 1) {
				printf("****Failed to parse average latency.\n");
			}
		}
	}
	if (ping_successful)
		printf("Ping was successful.\n");
	else
		printf("****Ping was not successful.\n");
	if (average_latency > 0) {
		printf("Average latency: %d ms\n\n", average_latency);
		fclose(file);
		if (remove(Ping_Result_File) != 0)
			printf("****Unable to remove tmp ping result file from %s\n", Ping_Result_File);
		return 0;
	}
	else {
		printf("****Average latency not found.\n\n");
		fclose(file);
		if (remove(Ping_Result_File) != 0)
			printf("****Unable to remove tmp ping result file from %s\n", Ping_Result_File);
		return -1;
	}
}

int is_directory_or_file(const char* path) {
	DWORD attributes = GetFileAttributesA(path);
	if (attributes == INVALID_FILE_ATTRIBUTES) {
		printf("\n****Invalid Path\n");
		return 0;
	}
	else if (attributes & FILE_ATTRIBUTE_DIRECTORY)
		return 1;
	else if (attributes & FILE_ATTRIBUTE_NORMAL)
		return 2;
	else {
		printf("****The path passed into is_directory_or_file function is neither a file or a directory.\n");
		return 3;
	}
}

void remove_newline_in_input(char* input) {
	input[strcspn(input, "\n")] = '\0';
}

int add_repository_path_to_file() {
	printf("Do you want to add repository to manage?(Y/n): ");
	char input1[BUFFER_SIZE];
	fgets(input1, sizeof(input1), stdin);
	remove_newline_in_input(input1);

	while (strcmp(input1, "Y") != 0 && strcmp(input1, "n") != 0) {
		printf("\n****Invalid input.\n");
		printf("****Please input again: ");
		fgets(input1, sizeof(input1), stdin);
		remove_newline_in_input(input1);
	}

	FILE* file = fopen(MANAGING_REPO_TXT, "a");
	if (!check_if_fopen_successful(file)) {
		perror("****Error openning file at %s", MANAGING_REPO_TXT);
		return -1;
	}

	while (strcmp(input1, "Y") == 0) {
		printf("\nPlease input an absolute path: ");
		char input2_repopath[BUFFER_SIZE];
		if (fgets(input2_repopath, sizeof(input2_repopath), stdin) != NULL) {
			remove_newline_in_input(input2_repopath);
			if (is_directory_or_file(input2_repopath) == 1) {
				fprintf(file, "%s\n", input2_repopath);
				printf("Path add successful.\n\n\n");
			}
			else
				printf("****Input is not a directory.\n");
		}
		else
			printf("****fgets get repopath failed.\n");
		printf("\nWould you like to add another path?(Y/n): ");
		fgets(input1, sizeof(input1), stdin);
		remove_newline_in_input(input1);
		while (strcmp(input1, "Y") != 0 && strcmp(input1, "n") != 0) {
			printf("\n****Invalid input.\n");
			printf("****Please input again: ");
			fgets(input1, sizeof(input1), stdin);
			remove_newline_in_input(input1);
		}
		remove_newline_in_input(input1);
	}
	fclose(file);
	system("cls");
	return 0;
}

void cmdoutput_to_path(char* cmd, char* path) {
	char augcmd[BUFFER_SIZE];
	snprintf(augcmd, sizeof(augcmd), "%s > \"%s\"", cmd, path);
	system(augcmd);
}

//get message from output and store in file
//check file and grab using delimeter 
//
//
