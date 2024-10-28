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
	git_status();
	//show_menu();
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