#include <stdio.h>

void sort(int n, int *AT, int *BT) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (AT[i] > AT[j]) {
                int temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;
            }
        }
    }
}

void fcfs(int n, int *AT, int *BT) {
    int current_time = 0;
    float total_WT = 0, total_TAT = 0;

    sort(n, AT, BT);
    for (int i = 0; i < n; i++) {
        int ST = (current_time > AT[i]) ? current_time : AT[i];
        int CT = ST + BT[i];
        int TAT = CT - AT[i];
        int WT = TAT - BT[i];

        total_WT += WT;
        total_TAT += TAT;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], BT[i], ST, CT, TAT, WT);

        current_time = CT;
    }

    printf("\nAverage TAT = %.2f", total_TAT / n);
    printf("\nAverage WT  = %.2f\n", total_WT / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n];

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    printf("\nP#\tAT\tBT\tST\tCT\tTAT\tWT\n");
    fcfs(n, AT, BT);

    return 0;
}
