#include <stdio.h>
#include <stdint.h>

void preemptive_priority(int n, int *AT, int *BT, int *P) {
    int completed_count = 0;

    while (completed_count < n) {

    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], P[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT and P for P%d: ", i+1);
        scanf("%d %d %d", &AT[i], &BT[i], &P[i]);
    }

    printf("\nP#\tAT\tBT\tST\tCT\tTAT\tWT\n");
    preemptive_priority(n, AT, BT, n);

    return 0;
}