#include "included lib & define.h"

int generate_git_status_output() {
	// Attempt to remove the old git status output file
	if (remove(GIT_STATUS_OUTPUT_TXT) != 0) {
		printf("****Warning: Could not remove previous git status output file: %s (This may be normal if file doesn't exist)\n", GIT_STATUS_OUTPUT_TXT);
	}

	FILE* repofile = fopen(MANAGING_REPO_TXT, "r");
	if (!check_if_fopen_successful(repofile)) {
		printf("****Error: Unable to open the managing repository file at %s. Please ensure the file exists and is accessible.\n", MANAGING_REPO_TXT);
		return -1;
	}

	char repo[BUFFER_SIZE];
	size_t repocount = 0;
	while (fgets(repo, sizeof(repo), repofile) != NULL) {
		repocount++;
		remove_newline_in_input(repo);

		char cmd_buffer[BUFFER_SIZE];
		// Using -C option with git so no manual directory switching needed
		snprintf(cmd_buffer, sizeof(cmd_buffer), "git -C \"%s\" status", repo);

		// Run the command and redirect output to a temp file
		cmdoutput_to_path(cmd_buffer, GIT_STATUS_TEMP_TXT);

		FILE* resultfile = fopen(GIT_STATUS_TEMP_TXT, "r");
		if (!check_if_fopen_successful(resultfile)) {
			printf("****Error: Unable to open the temporary git status file at %s.\n", GIT_STATUS_TEMP_TXT);
			fclose(repofile);
			return -1;
		}

		const char* not_a_git_repo = "not a git repository";
		const char* untracked1 = "Untracked files";
		const char* untracked2 = "Changes not staged for commit";
		const char* uncommitted1 = "Changes to be committed";
		const char* uncommitted2 = "Your branch is ahead of";
		const char* to_be_pushed1 = "Your branch is ahead of";
		const char* to_be_pushed2 = "nothing to commit, working tree clean";
		const char* up_to_date1 = "Your branch is up to date with";
		const char* up_to_date2 = "nothing to commit, working tree clean";

		char temp_buffer[BUFFER_SIZE];
		BOOL found_not_a_repo = FALSE;
		BOOL found_untracked = FALSE;
		BOOL found_uncommitted = FALSE;
		BOOL found_ahead = FALSE;
		BOOL found_clean = FALSE;
		BOOL found_up_to_date = FALSE;

		while (fgets(temp_buffer, sizeof(temp_buffer), resultfile) != NULL) {
			if (strstr(temp_buffer, not_a_git_repo))
				found_not_a_repo = TRUE;
			if (strstr(temp_buffer, untracked1) || strstr(temp_buffer, untracked2))
				found_untracked = TRUE;
			if (strstr(temp_buffer, uncommitted1) || strstr(temp_buffer, uncommitted2))
				found_uncommitted = TRUE;
			if (strstr(temp_buffer, to_be_pushed1))
				found_ahead = TRUE;
			if (strstr(temp_buffer, to_be_pushed2) || strstr(temp_buffer, up_to_date2))
				found_clean = TRUE;
			if (strstr(temp_buffer, up_to_date1))
				found_up_to_date = TRUE;
		}
		fclose(resultfile);

		// Append status result to GIT_STATUS_OUTPUT_TXT
		FILE* git_status_output = fopen(GIT_STATUS_OUTPUT_TXT, "a");
		if (!check_if_fopen_successful(git_status_output)) {
			printf("****Error: Unable to open or create the git status output file at %s.\n", GIT_STATUS_OUTPUT_TXT);
			fclose(repofile);
			return -1;
		}

		char status[BUFFER_SIZE] = "";
		char* repo_name = strrchr(repo, '\\');
		if (repo_name != NULL)
			repo_name++; // Move past the backslash
		else
			repo_name = repo; // No backslash found, use the entire string


		if (found_not_a_repo)
			strcpy_s(status, sizeof(status), "is NOT a git repository.");
		else if (found_untracked)
			strcpy_s(status, sizeof(status), "is waiting TO BE ADDED and tracked.");
		else if (found_uncommitted)
			strcpy_s(status, sizeof(status), "is waiting TO BE COMMITTED with comments.");
		else if (found_ahead && found_clean)
			strcpy_s(status, sizeof(status), "is waiting TO BE PUSHED.");
		else if (found_up_to_date && found_clean)
			strcpy_s(status, sizeof(status), "is UP TO DATE.");
		else
			strcpy_s(status, sizeof(status), "status could not be determined.");

		fprintf(git_status_output, "--%zu. \"%s\" %s\n", repocount, repo_name, status);
		fclose(git_status_output);

		if (remove(GIT_STATUS_TEMP_TXT) != 0)
			printf("****Warning: Unable to remove temporary git status file at %s\n", GIT_STATUS_TEMP_TXT);
	}

	fclose(repofile);
	return 0;
}

int git_status() {
	// Generate the output file with statuses
	if (generate_git_status_output() != 0)
		return -1;

	// Display the generated output
	if (show_existing_git_status_output(GIT_STATUS_OUTPUT_TXT) != 0)
		return -1;

	return 0;
}