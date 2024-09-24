#include <windows.h>
#include <stdio.h>

void WatchDirectory(LPCWSTR directory) {
    DWORD bytesReturned;
    char buffer[1024];
    BOOL result;
    HANDLE dirHandle = CreateFileW(directory, FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);

    if (dirHandle == INVALID_HANDLE_VALUE) {
        printf("Error: Unable to open directory.\n");
        return;
    }

    OVERLAPPED overlapped = { 0 };
    overlapped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

    while (TRUE) {
        result = ReadDirectoryChangesW(
            dirHandle, buffer, sizeof(buffer), FALSE,
            FILE_NOTIFY_CHANGE_CREATION,
            &bytesReturned, &overlapped, NULL);

        if (result == 0) {
            printf("Error: Failed to monitor directory changes.\n");
            break;
        }

        WaitForSingleObject(overlapped.hEvent, INFINITE);

        FILE_NOTIFY_INFORMATION* pNotify;
        int offset = 0;
        do {
            pNotify = (FILE_NOTIFY_INFORMATION*)((char*)buffer + offset);
            printf("File created: %ws\n", pNotify->FileName);
            offset += pNotify->NextEntryOffset;
        } while (pNotify->NextEntryOffset != 0);
    }

    CloseHandle(dirHandle);
}

int main() {
    WatchDirectory(L"C:\\path\\to\\watch");

    return 0;
}
