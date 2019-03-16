#include <iostream>
using namespace std;
void sertSort(int a[], int len) {
  for (int i = 1; i < len; ++i) {
    int key = a[i];
    int left = 0, right = i-1;
    while (!(left > right)) {  //在区间内查找位置
      int middle = (left + right) / 2;
      if (a[middle] > key)
           right = middle-1;
      else left = middle+1;
    }
    for (int j = i - 1; !(j<left); --j) {
      a[j+1] = a[j];
    }
    a[left] = key; //left为新元素无要插入的位置
  }
}

int main() {
  int a[] = {5,45,1,3,0,99,2,10 };
  int len = sizeof(a) / sizeof(a[0]);
  sertSort(a, len);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar();
  return 0;
}
