#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == 0)
		printf("child process pid: %d ppid: %d\n", getpid(), getppid());
	else if (pid > 0)
		printf("parent process pid: %d ppid: %d\n", getpid(), getppid());
	else
		perror("fork failed\n");
	return 0;
}
