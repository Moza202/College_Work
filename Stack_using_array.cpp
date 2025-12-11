/*
 * FILE SUMMARY:
 * This code implements a Stack data structure using a fixed-size array.
 * It also includes several practical applications of the Stack data structure, such as:
 * checking balanced parentheses, reversing strings, palindrome checking, decimal to binary conversion,
 * and infix to postfix expression conversion and evaluation.
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define vi vector<int>
#define sp " "
#define all(x) (x).begin(), (x).end()
#define MAXSIZE 1000

class Stack
{
public:
  int top;
  int arr[MAXSIZE];

  // Constructor: Initializes the stack with 'top' set to -1 (indicating empty).
  Stack()
  {
    top = -1;
  }

  // Checks if the stack is empty (top is -1).
  bool isEmpty()
  {
    return top == -1;
  }

  // Checks if the stack is full by comparing top with MAXSIZE.
  bool isFull()
  {
    return top == MAXSIZE - 1;
  }

  // Pushes a value onto the stack.
  // Increments 'top' and stores the value at the new index, checking for overflow.
  void push(int val)
  {
    if (isFull())
    {
      cout << "Stack is full" << nl;
      return;
    }
    else
    {
      top++;
      arr[top] = val;
    }
  }

  // Removes and returns the top element of the stack.
  // Returns the value at 'top' and decrements 'top'. Throws error if empty.
  int pop()
  {
    if (isEmpty())
    {
      throw "Stack is empty";
    }
    else
    {
      int val = arr[top];
      top--;
      return val;
    }
  }

  // Returns the value of the top element without removing it.
  int peek()
  {
    if (isEmpty())
    {
      throw "Stack is empty";
    }

    else
    {
      return arr[top];
    }
  }

  // Prints all elements in the stack from top to bottom.
  void display()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << nl;
      return;
    }
    else
    {
      for (int i = top; i >= 0; i--)
      {
        cout << arr[i] << sp;
      }
      cout << nl;
    }
  }

  // Searches for a value in the stack.
  // Returns the 0-based index from the top if found.
  int search(int val)
  {
    if (isEmpty())
    {
      throw "Stack is empty";
    }

    int idx = 0;
    for (int i = top; i >= 0; i--)
    {
      if (arr[i] == val)
      {
        return idx;
      }
      idx++;
    }
    return INT_MIN;
  }
};

// Checks if the parentheses in a string are balanced.
// Uses a stack to push opening brackets and pop them when a matching closing bracket is found.
bool check_Balance(string str)
{
  Stack s;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[')
    {
      s.push(str[i]);
    }
    else
    {
      if (s.isEmpty())
      {
        return false;
      }
      else if ((str[i] == ')' && s.peek() == '(') || (str[i] == '}' && s.peek() == '{') || (str[i] == ']' && s.peek() == '['))
      {
        s.pop();
      }
      else
      {
        return false;
      }
    }
  }
  return s.isEmpty();
};

// Reverses a string using a stack.
// Pushes all characters onto the stack and then pops them off to form the reversed string.
string reverse_sentence(string s)
{
  Stack st;
  string reversed = "";
  for (int i = 0; i < s.length(); i++)
  {
    st.push(s[i]);
  }
  while (!st.isEmpty())
  {
    reversed += st.pop();
  }
  return reversed;
}

// Checks if a string is a palindrome.
// Pushes characters to a stack, then pops them to compare with original characters order.
bool is_palindrome(string s)
{
  Stack st;
  for (int i = 0; i < s.length(); i++)
  {
    st.push(s[i]);
  }
  for (int i = 0; i < s.length(); i++)
  {
    if (st.pop() != s[i])
    {
      return false;
    }
  }
  return true;
}

// Converts a decimal number to binary using a stack.
// Repeatedly divides by 2 and pushes remainders onto the stack, then pops them to get binary digits.
string dectobin(int dec)
{

  if (dec == 0)
  {
    return "0";
  }
  Stack st;
  int n = dec;

  while (dec > 0)
  {
    int rem = dec % 2;
    st.push(rem);
    dec = dec / 2;
  }

  string bins = "";
  while (!st.isEmpty())
  {
    bins += to_string(st.pop());
  }
  return bins;
}

// Helper function to return the precedence of mathematical operators.
// Used to determine the order of operations in infix to postfix conversion.
int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  else if (op == '*' || op == '/' || op == '%')
    return 2;
  else if (op == '^')
    return 3;
  else
    return 0;
}

// Converts an infix expression (e.g., A+B) to postfix notation (e.g., AB+).
// Uses a stack to hold operators and ensures correct precedence and associativity.
string infix_to_postfix(string s)
{
  Stack st;
  string postfix = "";

  for (int i = 0; i < s.length(); i++)
  {

    if (s[i] == ' ')
    {
      continue;
    }

    if (isdigit(s[i]))
    {
      while (i < s.length() && (isdigit(s[i]) || s[i] == '.'))
      {
        postfix += s[i];
        i++;
      }
      postfix += ' ';
      i--;
    }
    else if (s[i] == '(')
    {
      st.push(s[i]);
    }
    else if (s[i] == ')')
    {
      while (!st.isEmpty() && st.peek() != '(')
      {
        postfix += st.pop();
        postfix += ' ';
      }
      if (!st.isEmpty())
      {
        st.pop();
      }
    }
    else
    {
      while (!st.isEmpty() && precedence(s[i]) <= precedence(st.peek()))
      {
        postfix += st.pop();
        postfix += ' ';
      }
      st.push(s[i]);
    }
  }

  while (!st.isEmpty())
  {
    postfix += st.pop();
    postfix += ' ';
  }

  if (!postfix.empty() && postfix.back() == ' ')
  {
    postfix.pop_back();
  }

  return postfix;
}

// Evaluates a postfix expression.
// Iterates through the expression, pushing numbers to the stack and performing operations when operators are encountered.
int eval_postfix(string s)
{
  Stack st;
  for (int i = 0; i < s.length(); i++)
  {
    if (isspace(s[i]))
    {
      continue;
    }
    else if (isdigit(s[i]))
    {
      int num = 0;
      while (i < s.length() && isdigit(s[i]))
      {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      i--;
      st.push(num);
    }
    else
    {
      int second = st.pop();
      int first = st.pop();
      if (s[i] == '+')
      {
        st.push(first + second);
      }
      else if (s[i] == '-')
      {
        st.push(first - second);
      }
      else if (s[i] == '*')
      {
        st.push(first * second);
      }
      else if (s[i] == '/')
      {
        st.push(first / second);
      }
    }
  }
  return st.peek();
}

int main()
{

  string s;
  cin >> s;
  if (check_Balance(s))
  {
    cout << "YES" << nl;
  }
  else
  {
    cout << "NO" << nl;
  }
  string y;
  cin >> y;
  cout << reverse_sentence(y) << nl;
  is_palindrome(y) ? cout << "YES\n" : cout << "NO\n";
  dectobin(10);
  cout << dectobin(10) << nl;

  string test1 = "12 + 34";
  string test2 = "(100 + 200) * 30";
  cout << infix_to_postfix(test1) << nl;
  cout << infix_to_postfix(test2) << nl;
  cout << eval_postfix(infix_to_postfix(test1)) << nl;
  cout << eval_postfix(infix_to_postfix(test2)) << nl;

  return 0;
}