#include <iostream>
#include <string>
#include <vector>

using namespace std;

float widthOfString(std::string input);
void autoHeight(string& input, float maxWidth);
vector<string> splitBy(string input, char character);

int main() {
	string s = "Quý khách vui lòng chuẩn bị sẵn số tiền mặt tương ứng để thuận tiện cho việc thanh toán.";
	autoHeight(s, 55);

	cout << "---------------------------------------------\n";
	autoHeight(s, 60);	
}

float widthOfString(std::string input) {
	return input.length();
}

vector<string> splitBy(string input, char character) {
	string s ="";
	vector<string> v;
	v.clear();
	for (char c : input) {
		if (c == character) {
			v.push_back(s);
			s = "";
		}
		else {
			s = s + c;
		}
	}

	if (s.length()) v.push_back(s);	

	return v;
}

void autoHeight(string& input, float maxWidth) {
	std::vector<string> v = splitBy(input, ' ');

	string line = "";
	float width = 0;

	for (string s : v) {
		float wS = widthOfString(s + " ");
		if (width + wS > maxWidth) {
			cout << line << endl;
			line = s + " ";
			width = wS;
		}
		else {
			line = line + s + " ";
			width += wS;
		}
	}

	if (line.length()) {
		cout << line << endl;
	}
}