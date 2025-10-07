#include <stdio.h>
#include <unistd.h>

int main() {
	int amt, old = nice(0);
	printf("current process priority: %d\n", old);

	printf("enter amount to increment: ");
	scanf("%d", &amt);

	int new = nice(amt);
	printf("new nice value: %d\n", new);
	return 0;
}
