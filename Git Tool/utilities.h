#pragma once
#include <stdio.h>

int check_if_fopen_successful(FILE* file);

int ping_github();

int is_directory_or_file(const char* path);

void remove_newline_in_input(char* input);

int add_repository_path_to_file();

void cmdoutput_to_path(char* cmd, char* path);