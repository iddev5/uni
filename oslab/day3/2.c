#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
  int idx, AT, BT;
  struct node *next;
};

struct node *append_node(struct node *head, int idx, int AT, int BT) {
  struct node *temp = head, *new = (struct node *)malloc(sizeof(struct node));
  new->idx = idx;
  new->AT = AT;
  new->BT = BT;
  new->next = NULL;
  
  if (head == NULL)
    return new;

  while (temp->next)
    temp = temp->next;
  temp->next = new; 
  return head;
}

struct node *get_next_process(struct node *Q, int time) {
  struct node *temp = Q, *prev = Q, *selected = Q, *selected_prev = Q;
  int idx = 0, min_BT = temp->BT;
  while (temp) {
    if (time >= temp->AT && temp->BT < min_BT) {
      selected_prev = prev;
      selected = temp;
      min_BT = temp->BT;
    }
    prev = temp;
    temp = temp->next;
    idx++;
  }

  // if (!selected)
  //   return NULL;

  selected_prev->next = selected->next;
  if (idx == 0)
    Q = Q->next;
  return selected;
}

void schedule_fcfs(struct node *Q) {
  int time = 0;
  for (int i = 0; i < 5; i++) {
    struct node *proc = get_next_process(Q, time);
    if (!proc) {
      time++;
      continue;
    }
    if (time < proc->AT)
      time = proc->AT;

    printf("P%d\t%d\t%d\t%d\n", proc->idx, time, time - proc->AT, time + proc->BT);
    time += proc->BT;
  }
}

int main() {
  int AT[] = {0, 4, 2, 1, 3};
  int BT[] = {4, 3, 1, 2, 5};

  struct node *head = append_node(NULL, 1, 0, 4);
  head = append_node(head, 2, 4, 3);
  head = append_node(head, 3, 2, 1);
  head = append_node(head, 4, 1, 2);
  head = append_node(head, 5, 3, 5);

  printf("P#\tST\tWT\tTAT\n");
  for (int i = 0; i < 32; i++)
    putchar('-');
  putchar('\n');
  schedule_fcfs(head);

  return 0;
}
