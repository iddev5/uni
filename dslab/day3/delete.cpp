
#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node {
  int data;
  struct node* next;
} node;

node* createNode(int new_data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = new_data;
  new_node->next = NULL;
  return new_node; // Return the newly created node
}

node *delete_beginning(node* head)
{
  if (!head) {
    cout << "Underflow: List is empty";
    exit(0);
  }
  node *t = head->next;
  free(head);
  return t;
}


node *delete_end(node* head)
{
  if (!head) {
    cout << "Underflow: List is empty";
    exit(0);
  }
  node *t = head, *save;
  while (t->next) {
    save = t;
    t = t->next;
  }

  save->next = NULL;
  free(t);
  return head;
}


node *delete_middle(node* head, int pos)
{
  if (!head) {
    cout << "Underflow: List is empty";
    exit(0);
  }

  int p = 0;
  node *t = head, *save;
  while (t->next && p < pos) {
    save = t;
    t = t->next; p++;
  }

  save->next = t->next;
  free(t);
  return head;
}

void printList(node* head)
{
node* curr = head;
while (curr != NULL) {
printf(" %d", curr->data);
curr = curr->next; }
printf("\n");
}

int main()
{
// // Create the linked list 2->3->4->5
// node* head = createNode(2);
// head->next = createNode(3);
// head->next->next = createNode(4);
// head->next->next->next = createNode(5);
// printf("Original Linked List:");
// printList(head);
// printf("After inserting Nodes at the front:");
// int data = 1;
// head = insertAtFront(head, data);
// head = append(head, 10);
// head = middle(head, 2, 90);
// printList(head);
// return 0;
  int data;
  node *head = NULL, *curr;

  int num;
  cout << "Enter num of elements: ";
  cin >> num;
  for (int i = 0; i < num; i++) {
    cout << "Enter data: ";
    cin >> data;
    if (!head) { head = createNode(data); curr = head; }
    else {
      curr->next = createNode(data);
      curr = curr->next;
    }
    
  }

  head = delete_beginning(head);
  printList(head);
  head = delete_end(head);
  printList(head);
  head = delete_middle(head, 2);

  printList(head);
}
