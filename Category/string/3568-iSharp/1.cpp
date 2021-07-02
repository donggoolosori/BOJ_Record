#include <iostream>
#include <string>

using namespace std;

string getDeclaration(string base, string rear) {
  string ret = base;
  string var = "", addVar = "";

  for (int i = 0; i < rear.length(); i++) {
    if ((rear[i] >= 'a' && rear[i] <= 'z') ||
        (rear[i] >= 'A' && rear[i] <= 'Z')) {
      var += rear[i];
    } else {
      addVar = rear.substr(i);
      break;
    }
  }

  if (!addVar.empty()) {
    for (int i = addVar.length() - 1; i >= 0; i--) {
      if (addVar[i] == '[')
        ret += ']';
      else if (addVar[i] == ']')
        ret += '[';
      else
        ret += addVar[i];
    }
  }
  ret += " " + var + ';';

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, base = "";
  getline(cin, s);

  // get base
  int i;
  for (i = 0; s[i] != ' '; i++) base += s[i];
  i++;

  string temp = "";
  for (; i < s.length(); i++) {
    if (s[i] == ';' || s[i] == ',') {
      cout << getDeclaration(base, temp) << '\n';
      temp = "";
      i++;
    } else
      temp += s[i];
  }

  return 0;
}