#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include "git command.h"
#include "display.h"
#include "utilities.h"

#define WORKING_DIRECTORY "C:\\Users\\Administrator\\Desktop\\opt\\Git management tool"
#define BUFFER_SIZE 256
#define MAXIMUM_REPO_PATH 50
#define MANAGING_REPO_TXT "C:\\Users\\Administrator\\Desktop\\opt\\Git management tool\\managing_repo.txt"
#define GIT_STATUS_TEMP_TXT "C:\\Users\\Administrator\\Desktop\\opt\\Git management tool\\git_status_output_temp.txt"
#define GIT_STATUS_OUTPUT_TXT  "C:\\Users\\Administrator\\Desktop\\opt\\Git management tool\\git_status_output.txt"