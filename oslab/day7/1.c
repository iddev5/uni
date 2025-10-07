#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == 0)
		printf("child process\n");
	else if (pid > 0)
		printf("parent process\n");
	else
		perror("fork failed\n");
	return 0;
}
