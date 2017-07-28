#include <iostream>
#include <string>

using namespace std;

string findNearest(string source, string des) {
	string res = "";
	int minDistance = source.length();
	for (int i=0;i<=source.length() - des.length(); i++) {
		int count = 0;
		string tempRes = "";
		for (int j=0; j < des.length(); j++) {
			tempRes = tempRes + source[i + j];
			if (source[i + j] != des[j]) {
				count++;
			}
		}
		if (count < minDistance) {
			minDistance = count;
			res = count;
			res = tempRes;
		}
	}
	return res;
}

int main() {
	string a = "ABABDASD";
	string b = "ABAC";

	cout << findNearest(a, b) << endl;
}