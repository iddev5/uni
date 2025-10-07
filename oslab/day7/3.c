#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid1 = fork();
	if (pid1 == 0) {
		printf("child process 1 pid: %d\n", getpid());
		_exit(0);
	}
	
	pid_t pid2 = fork();
	if (pid2 == 0) {
		printf("child process 2 pid: %d\n", getpid());
		_exit(0);
	}

	return 0;
}
