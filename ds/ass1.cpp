#include <iostream>
using namespace std;

typedef struct node {
  int data;
  node *next;
} node;

node *create_node(int data) {
  node *n = (node *)malloc(sizeof(node));
  n->data = data;
  n->next = NULL;
  return n;
}

node *append_node(node *n, int data) {
  if (!n) {
    return create_node(data);
  }

  node *tmp = n;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = create_node(data);
  return n;
}

node *merge_sorted(node *n1, node *n2) {
  node *root = n1->data > n2->data ? n2 : n1;
  if (root == n1) n1 = n1->next;
  else n2 = n2->next;

  node *t = root, *dat;
  while (n1 && n2) {
    if (n1->data < n2->data) {
      dat = n1;
      n1 = n1->next;
    } else {
      dat = n2;
      n2 = n2->next;
    }
    if (t->data != dat->data) {
      t->next = dat;
      t = t->next;
    }
  }

  if (n2 && n2->data != t->data) t->next = n2;
  if (n1 && n1->data != t->data) t->next = n1;
  
  return root;
}

int main() {
  int n, m, data;
  cout << "Enter size of first linked list: ";
  cin >> n;

  cout << "Enter size of second linked list: ";
  cin >> m;

  node *n1 = NULL, *n2 = NULL;

  cout << "Enter elements of first linked list: ";
  for (int i = 0; i < n; i++) {
    cin >> data;
    n1 = append_node(n1, data);
  }
  
  cout << "Enter elements of second linked list: ";
  for (int i = 0; i < m; i++) {
    cin >> data;
    n2 = append_node(n2, data);
  }

  cout << "Merge linked list: ";
  node *merged = merge_sorted(n1, n2);
  node *temp = merged;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}