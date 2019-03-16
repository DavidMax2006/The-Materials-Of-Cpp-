#include<iostream>
#include<vector>
using namespace std;
int getnum(int a[], int len) {
  int max = a[0];
  int num = 1;
  for (int i = 1; i < len; ++i) {
    max=a[i] > max ? a[i] : max;
  }
  while (max /= 10) {
    num++;
  }
  return num;
}
void radixSort(int a[], int len) {
  int num = getnum(a, len); //获得位数
  vector<vector<int> >radix(10);
  for(int k=0;k<num;++k){
    for (int i = 0; i < len; ++i) {  //存放元素
      int t = int(a[i]);
      radix[t].push_back(a[i]);
    }
    vector<vector<int> >::iterator p;
    vector<int>::iterator q;
    int i = 0;
    for (p = radix.begin(); p != radix.end(); ++p) {  //取出元素
      for (q = (*p).begin(); q !=(*p).end(); ++q) {
        a[i++] = *q;
      }
    }
    for (int i = 0; i < 10; ++i) {  //清空容器中元素
      if(!radix[i].empty())
      radix[i].clear();
    }
  }
}

int main() {
  int a[] = { 0,1,89,4,45,41,7,9,0,52,80,100 };
  int len = sizeof(a) / sizeof(a[0]);
  radixSort(a, len);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar();
  return 0;
}
