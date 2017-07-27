#include <iostream>

using namespace std;

int main() {
	// Dữ liệu
	int length[] = {12, 8, 13, 24, 36, 25, 5, 8, 12};
	int width = 48;
	bool canMake[width+1];
	int NumItems = sizeof(length) / sizeof(int);

	// Khởi tạo
	for (int j = 0; j <= width; j++) canMake[j] = false;
	canMake[0] = true;

	// QHĐ
	for (int i = 0; i < NumItems; i++) {
		for (int j = width - length[i]; j >= 0; j--) {
			if (canMake[j]) {
				canMake[j + length[i]] = i;
			}
		}
	}

	// Đưa ra danh sách các tổng có thể tạo từ dãy
	for (int i=0;i<=width;i++)
		if (canMake[i]) cout << i << " ";
	cout<<endl;
}