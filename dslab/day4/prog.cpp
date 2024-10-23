#include <iostream>
using namespace std;

int get_precedence(char c) {
  switch (c) {
    case '*': case '/': return 10;
    case '+': case '-': return 5;
    default: return -1;
  }
}

class stack {
  int t;
  int *data;
public:
  stack(int size) {
    t = -1;
    data = new int[size];
  }
  
  void push(int d) {
    data[++t] = d;  
  }

  int pop() {
    return data[t--];
  }

  int peek() {
    return data[t];
  }

  int top() {
    return t;
  }
};

string infix_to_postfix(string infix) {
  string postfix;
  stack s(infix.size());

  for (int i = 0; i < infix.size(); i++) {
    if (isdigit(infix[i]))
      postfix += infix[i];
    else if (infix[i] == '(')
      s.push(infix[i]);
    else if (infix[i] == ')') {
      while (s.top() >= 0 && s.peek() != '(') 
        postfix += s.pop();
      s.pop();
    } else {
      while (s.top() >= 0 && get_precedence(s.peek()) > get_precedence(infix[i])) 
        postfix += s.pop();
      s.push(infix[i]);
    }
  }

  while (s.top() >= 0)
    postfix += s.pop();

  return postfix;
}

int evaluate_postfix(string postfix) {
  stack s(postfix.size());

  for (int i = 0; i < postfix.size(); i++) {
    if (isdigit(postfix[i]))
      s.push(postfix[i] - '0');
    else {
      int n1 = s.pop();
      int n2 = s.pop();
      switch (postfix[i]) {
        case '+': s.push(n2+n1); break;
        case '-': s.push(n2-n1); break;
        case '*': s.push(n2*n1); break;
        case '/': s.push(n2/n1); break;
      }
    }
  }

  return s.pop();
}

int main() {
  string expr;
  cout << "Infix -> Postfix converter & evaluator" << endl;
  cout << "Enter an infix expression: ";
  cin >> expr;

  string postfix = infix_to_postfix(expr);
  cout << "Equivalent postfix expression is: " << postfix << endl;

  int result = evaluate_postfix(postfix);
  cout << "Result of evaluation is: " << result << endl;

  cout << "Exiting program" << endl;
  return 0;
}
