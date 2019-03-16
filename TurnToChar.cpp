#include <iostream>
using namespace std;
//每一个小写字母常量都比相应的大写字母的ASCII代码大32
int main(int argc, char const *argv[]) {
  char c1,c2;
  c1 = 'a';
  c2 = 'b';
  c1 = c1-32;
  c2 = c2-32;
  std::cout << c1 << " " << c2 << '\n';
  //运行后可以发现，由于c1，c2是字符变量，所以得到了A，B（65，66）
  return 0;
}
