
#include <iostream>
#include <stdio.h>

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

node* insertAtFront(node* head, int new_data)
{
  node* new_node = createNode(new_data);
  new_node->next = head;
  return new_node;
}

node* append(node* head, int new_data) {
  node* new_node = createNode(new_data);
  if (head == NULL) {
    return new_node;
  }
  node* last = head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
  return head; 
}

node* middle(node* head, int pos, int new_data) {
  node* new_node = createNode(new_data);
  if (head == NULL) {
    return new_node;
  }
  if (pos == 0) {
    new_node->next = head;
    return new_node;
  }
  
  int p = 0;
  node* last = head;
  while (last->next != NULL && p < pos - 1) {
    last = last->next;
    p++;
  }
  new_node->next = last->next;
  last->next = new_node;
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
// Create the linked list 2->3->4->5
node* head = createNode(2);
head->next = createNode(3);
head->next->next = createNode(4);
head->next->next->next = createNode(5);
printf("Original Linked List:");
printList(head);
printf("After inserting Nodes at the front:");
int data = 1;
head = insertAtFront(head, data);
head = append(head, 10);
head = middle(head, 2, 90);
printList(head);
return 0;
}
