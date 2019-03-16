#include <iostream>

int main(void) {
  bool a = 10 == 9;  //false
  bool b = 10 != 9;  //true
  bool c = 10 >= 9;  //true
  bool d = 10 <= 9;  //false

  std::cout << std::boolalpha;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << (10 > 9) << std::endl;
  std::cout << (10 < 9) << std::endl;
  return 0;
}
