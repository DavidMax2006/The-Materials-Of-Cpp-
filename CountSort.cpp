#include<iostream>
using namespace std;
void countSort(int a[], int len) {
  int low = a[0], high = a[0];
  for (int i = 0; i < len; ++i) {  //找范围
    low = a[i] < low ? a[i] : low;
    high = a[i] > high ? a[i] : high;
  }
  int range = high - low+1;
  int *count = new int[range];
  //memset(count, 0, sizeof(int)*(range));
  for(int i=0;i<len;++i){  //统计频次
    count[a[i]-low]++;
  }
  for (int i = 0,j=0; i < range; ++i) {  //赋值
    while (count[i]--) {
      a[j++] = i+low;
    }
  }
}

int main() {
  int a[] = { 2, 2, 3, 8, 7,0,4};
  int len = sizeof(a) / sizeof(a[0]);
  countSort(a, len);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar();
  return 0;
}
