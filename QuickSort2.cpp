#include<iostream>
using namespace std;
void quickSort(int a[], int low, int high) {
  if (low >= high)
  return;
  int i, j, key;
  i = low;
  j = high;
  key = a[low];
  while (i < j) {
    while (i<j&&a[j]>=key) {
      j--;
    }
    a[i] = a[j];
    while (i < j&&a[i] <=key) {
      i++;
    }
    a[j] = a[i];
  } a[i] = key; //基准到位
  quickSort(a, low, i - 1);
  quickSort(a, i + 1, high);
}

int main() {
  int a[] = { 0,4,1,2,3,0,0,0 };
  int len = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, len - 1);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar();
  return 0;
}
