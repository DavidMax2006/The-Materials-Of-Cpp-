#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int i,j;  //i和j是整型变量
  i = 'A';  //将一个字符常量赋给整型变量i
  j = 'B';  //将一个字符常量赋给整型变量j
  std::cout << i << " " << j << '\n';  //输出整型变量i和j的值，‘\n’是换行符
  return 0;
}
