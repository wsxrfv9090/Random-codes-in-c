#include "included lib & define.h"

int main() 
{
	int flag_for_successfully_ping = ping_github();
	if (flag_for_successfully_ping == -1) {
		printf("Exe ended due to unsuccessful pinging.\n");
		return 0;
	}
	show_managing_repos();
	int flag_for_successfully_openning_file = add_repository_path_to_file();
	if (flag_for_successfully_openning_file != 1) {
		printf("****Error openning file in \"add_repository_path_to_file\" function.\n");
		printf("****Could be somethnig wrong with %s", MANAGING_REPO_TXT);
	}
	if (git_status() != 0)
		printf("****There's a problem while running git status function.\n");

	int managing_repo_number = current_managing_repo_number();
	printf("\n\nAvailable options: \n");
	show_menu();
	printf("Please enter an option: ");
	char input1[BUFFER_SIZE];
	fgets(input1, BUFFER_SIZE, stdin);
	remove_newline_in_input(input1);
	while (strcmp(input1, "6") != 0) {
		if (strcmp(input1, "1") == 0) {
			system("cls");
			if (show_existing_git_status_output(GIT_STATUS_OUTPUT_TXT) != 0)
				printf("****Error reading git status output file in main.\n");
			printf("\nGit add all option for each repository.\n");
			printf("Please enter repositories' serial numbers seperated by space witch you want to do this operation: ");

			int result_flag = -1;
			int chosen_index[BUFFER_SIZE] = { 0 };
			while (result_flag == -1) {
				char input_add_choice[BUFFER_SIZE];
				fgets(input_add_choice, BUFFER_SIZE, stdin);
				remove_newline_in_input(input_add_choice);
				result_flag = validate_input_by_strtok_and_space(input_add_choice, managing_repo_number, chosen_index);
				if (result_flag == -1) {
					printf("****Input invalid.\n");
					printf("****Please enter again.\n");
				}
			}
			
			FILE* managing_repo_file = fopen(MANAGING_REPO_TXT, "r");
			if (managing_repo_file == NULL) {
				printf("****Openning file(%s) filed in main.\n", MANAGING_REPO_TXT);
				break;
			}
			char buffer[BUFFER_SIZE];
			for (size_t i = 0; fgets(buffer, BUFFER_SIZE, managing_repo_file) != NULL && i < managing_repo_number; i++) {
				for (size_t j = 0; j < managing_repo_number; j++) {
					if (chosen_index[j] == i + 1) {
						remove_newline_in_input(buffer);
						char cmd[BUFFER_SIZE];
						snprintf(cmd, BUFFER_SIZE, "git -C \"%s\" add .", buffer);
						system(cmd);
					}
				}
			}
			fclose(managing_repo_file);
		}
		else if (strcmp(input1, "2") == 0) {
			system("cls");
			if (show_existing_git_status_output(GIT_STATUS_OUTPUT_TXT) != 0)
				printf("****Error reading git status output file in main.\n");
			printf("\nGit commit option for each repository.\n");
			printf("Please enter the index of the repo and the comment you want to add on this commit with quetes \"\" seperated with a space: (e.g: `1 \"nice job\") ");

			int validation_flag = -1;
			long repo_num;
			char input_add_choice_and_comment[BUFFER_SIZE];
			char* ptr_strtok = NULL;
			char* token1 = NULL;
			char* token2 = NULL;
			while (validation_flag == -1) {
				fgets(input_add_choice_and_comment, BUFFER_SIZE, stdin);
				remove_newline_in_input(input_add_choice_and_comment);
				
				char inputcpy[BUFFER_SIZE];
				strcpy_s(inputcpy, BUFFER_SIZE, input_add_choice_and_comment);
				token1 = strtok_s(inputcpy, " ", &ptr_strtok);
				printf("The token is %s\n", token1);

				token2 = strtok_s(NULL, "\"", &ptr_strtok);
				printf("The comment is %s\n", token2);

				if (token1 == NULL || token2 == NULL) {
					printf("****Invalid input, please try again.\n");
					continue;
				}

				char* endptr;
				repo_num = strtol(token1, &endptr, 10);
				printf("The number is %ld\n", repo_num);

				if (*endptr != '\0') {
					printf("****The repo index isn't a pure interger.\n");
					continue;
				}
				if (repo_num < 1 || repo_num > managing_repo_number) {
					printf("****The repo index isn't in valid range.\n");
					continue;
				}
				validation_flag = 2;
				if (validation_flag == -1)
					printf("Please try again: ");
			}
			FILE* managing_repo_file = fopen(MANAGING_REPO_TXT, "r");
			if (managing_repo_file == NULL) {
				printf("****Openning file(%s) filed in main.\n", MANAGING_REPO_TXT);
				break;
			}
			char buffer[BUFFER_SIZE];
			for (size_t i = 0; fgets(buffer, BUFFER_SIZE, managing_repo_file) != NULL && i < managing_repo_number; i++) {
				if (repo_num == i + 1) {
					remove_newline_in_input(buffer);
					char cmd[BUFFER_SIZE];
					snprintf(cmd, BUFFER_SIZE, "git -C \"%s\" commit -m \"%s\"", buffer, token2);
					system(cmd);
				}
			}
			fclose(managing_repo_file);

		}
		else if (strcmp(input1, "3") == 0) {
			printf("Choose repositories to push option.\n");
		}
		else if (strcmp(input1, "4") == 0) {
			printf("Git status option.\n");
			if (git_status() != 0)
				printf("****There's a problem while running git status function.\n");
		}
		else if (strcmp(input1, "5") == 0) {
			printf("Option 5\n");
		}
		else {
			system("cls");
			printf("Invalid input.\n");
			printf("Please try again.\n");
		}
		system("cls");
		printf("\n-----Operation completed.-----\n");
		show_menu();
		printf("-----Would you like to choose other operations to do? : ");
		fgets(input1, BUFFER_SIZE, stdin);
		remove_newline_in_input(input1);
	}
	//int option;
	//fgets(option, sizeof(option), stdin);
	//remove_newline_in_input(option);
	//while (option != 6) {
	//	if (option == 1)
	//		show_managing_repos();
	//	else if (option == 2)
	//		git_status();
	//	else if (option == 3)
	//		git_add();
	//	else if (option == 4)
	//		git_commit();
	//	else if (option == 5)
	//		git_push();
	//	else
	//		printf("error inputting.");
	//}
	return 0;
}