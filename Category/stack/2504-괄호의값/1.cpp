#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;

  int answer = 0;
  stack<string> stk;

  for (const auto &ch : s) {
    if (ch == '(' || ch == '[') {
      stk.push(string(1, ch));
    } else {
      if (stk.empty()) {
        cout << 0;
        return 0;
      }
      int score = ch == ')' ? 2 : 3;
      int sum = 0;
      while (stk.top() != "(" && stk.top() != "[") {
        sum += stoi(stk.top());
        stk.pop();
      }

      if ((stk.top() + ch == "(]" || stk.top() + ch == "[)")) {
        cout << 0;
        return 0;
      }
      stk.pop();
      int num = sum == 0 ? score : score * sum;
      if (stk.empty())
        answer += num;
      else
        stk.push(to_string(num));
    }
  }

  cout << answer;

  return 0;
}