#include <iostream>

using namespace std;

int main() {
	// Dữ liệu
	int length[] = {12, 8, 13, 24, 36, 25, 5, 8, 12};
	int width = 48;
	int trace[width+1];
	int NumItems = sizeof(length) / sizeof(int);

	// Khởi tạo
	for (int j = 0; j <= width; j++) trace[j] = -1;
	trace[0] = 0;

	// QHĐ
	for (int i = 0; i < NumItems; i++) {
		for (int j = width - length[i]; j >= 0; j--) {
			if (trace[j] > -1) {
				if (trace[j + length[i]] == -1) {
					trace[j + length[i]] = i;
				}
			}
		}
	}

	// Trace
	int s = 48;
	while (s > 0) {
		cout << length[trace[s]]<<" ";
		s -= length[trace[s]];
	}

	cout<<endl;
}