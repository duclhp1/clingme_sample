#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <ctime>

#define MAX_TEXT_LENGTH 110

#define TEST1 1

using namespace std;

ifstream fi;
long numPlace;
std::vector<string> list;
string textSearch;

int max(int a, int b) {
	return a>b?a:b;
}

int dynamicProg(string source, string textSearch) {
	int f[MAX_TEXT_LENGTH][MAX_TEXT_LENGTH];
	// khởi tạo
	for (int i = 0; i<=source.length(); i++){
		for (int j=0; j<=textSearch.length(); j++) f[i][j] = 0;
	}

	// quy hoạch động
	for (int i=1; i<=source.length(); i++) {
		for (int j=1; j<=textSearch.length(); j++) {
			if (toupper(source[i-1]) == toupper(textSearch[j-1])) {
				f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
			}
			else {
				f[i][j] = max(f[i][j], f[i-1][j]);
				f[i][j] = max(f[i][j], f[i][j-1]);
			}
		}
	}
#ifdef TEST
	// debug
	for (int i=1; i<=source.length(); i++) {
		for (int j=1; j<=textSearch.length(); j++) {
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
#endif

	return f[source.length()][textSearch.length()];
}

int main() {
	fi.open("name.txt");
	fi >> numPlace;
	string temp;
	getline(fi, temp);

	for (int i = 0; i < numPlace; i++) {
		getline(fi, temp);
		list.push_back(temp);
	}

	cout << "Nhap xau can tim: ";

	getline(std::cin, textSearch);

#ifdef TEST

	dynamicProg(list.at(0), textSearch);
#else

	// bắt đầu search
	clock_t start = clock();
	int eps = 1;
	int res_num = 0;

	cout << "start search\n---------------------------------------\n";

	for (auto s : list) {
		int res = dynamicProg(s, textSearch);
		if (eps + res >= textSearch.length()) {
			// cout << res << " " << textSearch.length() << endl;
			cout << s<<endl;
			res_num ++;
		}
	}

	clock_t end = clock();

	float deltaTime = (float)(end - start) / CLOCKS_PER_SEC;

	printf("Tim duoc %d ket qua trong %.2fs\n", res_num, deltaTime);
#endif
	return 1;
}