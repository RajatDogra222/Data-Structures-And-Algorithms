#include<bits/stdc++.h>
using namespace std;

void reverse(string s, int ind) {

	if (ind == s.size() - 1) {
		cout << s[ind];
		return;
	}

	reverse(s, ind + 1);
	cout << s[ind];
}

int main() {

	string s;
	cin >> s;

	reverse(s, 0);
	return 0;
}