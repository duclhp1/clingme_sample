#include <iostream>

using namespace std;

int main() {
	// Dữ liệu
	int length[] = {12, 8, 13, 24, 36, 25, 5, 8, 12};
	int width = 48;
	int trace[width+1];
	int NumItems = sizeof(length) / sizeof(int);

	bool notUsed[NumItems];
	int usedItems = 0;

	// Khởi tạo notUsed
	for (int i = 0; i < NumItems; i++) notUsed[i] = true;

	for (;usedItems < NumItems;) {
		// Khởi tạo
		for (int j = 0; j <= width; j++) trace[j] = -1;
		trace[0] = 0;

		// QHĐ
		for (int i = 0; i < NumItems; i++) {
			if (notUsed[i]) {
				for (int j = width - length[i]; j >= 0; j--) {
					if (trace[j] > -1) {
						if (trace[j + length[i]] == -1) {
							trace[j + length[i]] = i;
						}
					}
				}
			}
		}

		int s = 0;

		for (int i=width; i > 0; i--) {
			if (s < i && trace[i] > -1) {
				s = i;
				break;
			}
		}

		// Trace
		while (s > 0) {
			cout << length[trace[s]]<<" ";
			notUsed[trace[s]] = false;
			s -= length[trace[s]];
			usedItems++;
		}

		cout << endl;
	}
}