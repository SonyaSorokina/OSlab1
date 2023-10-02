#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hStdIn;
    HANDLE hStdOut;
    char inputBuffer[30];
    DWORD soLen;

    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("stdin = %d\n", hStdIn);
    printf("stdout = %d\n", hStdOut);

    if (hStdIn == INVALID_HANDLE_VALUE) return 254;
    if (hStdOut == INVALID_HANDLE_VALUE) return 253;

    WriteFile(hStdOut, "Enter text\n", 11, &soLen, NULL);
    ReadFile(hStdIn, inputBuffer, 30, &soLen, NULL);
    WriteFile(hStdOut, inputBuffer, 30, &soLen, NULL);

    _getch();
    return 0;
}
