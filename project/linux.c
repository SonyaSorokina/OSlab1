#include <unistd.h>

int main() {
	char inputBuffer[30];
	int soLen;
	if (isatty(0)) {
		write(1, "Enter text:\n", 12);
	}
	soLen = read(0, inputBuffer, 30);
	write(1, inputBuffer, soLen);
	return 0;
}
