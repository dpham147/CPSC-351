#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

const int arrSize = 10;
int arr[arrSize] = { 7, 12, 19, 3, 18, 4, 2, 6, 15, 8 };
int sorted[arrSize];

DWORD WINAPI mergeSort(LPVOID Param) {
	return 0;
}

int main() {

	DWORD ThreadId;
	HANDLE ThreadHandle;
	int Param[arrSize/2];
	
	ThreadHandle = CreateThread(
		NULL,
		0,
		mergeSort,
		&arr,
		0,
		&ThreadId);

	if (ThreadHandle != NULL) {
		WaitForSingleObject(ThreadHandle, INFINITE);

		CloseHandle(ThreadHandle);

		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
	}


	cout << endl;
	system("pause");
	return 0;
}