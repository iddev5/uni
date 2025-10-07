#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("child process exit\n");
		_exit(0);
	} else if (pid > 0) {
		sleep(20);
		printf("parent process exit\n");
	}
	return 0;
}
