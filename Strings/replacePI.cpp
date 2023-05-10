#include<bits/stdc++.h>
using namespace std;

void replacepi(string &s, int ind) {

	if (ind == s.size()) {
		return;
	}
	if (s[ind] == 'p' && s[ind + 1] == 'i') {
		s.replace(ind, 2, "3.14");
		replacepi(s, ind + 2);
	}
	else {
		replacepi(s, ind + 1);
	}
}


int main() {
	string s;
	cin >> s;
	replacepi(s, 0);
	cout << s;
	return 0;
}