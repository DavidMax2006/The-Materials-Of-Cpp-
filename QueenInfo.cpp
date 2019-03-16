#include <iostream>


int main(void) {
  //Queen's personal Infomation
  unsigned int age = 12;   //Input Queen's age,12 years old
  bool male = false;  //Record male or not, isn't
  bool female = !male;   //!false is true
  bool girl = age < 18 && female;  //Under 18 and a female is a girl
  bool is_not_child = age < 2 || age >= 18;  //false

  std::cout << std::boolalpha;
  std::cout << "Queen's Personal Infomation" << std::endl;
  std::cout << "Age:" << age << std::endl;
  std::cout << "Male:" << male << std::endl;
  std::cout << "Female:" << female << std::endl;
  std::cout << "Girl:" << girl << std::endl;
  std::cout << "Isn't Child:" << is_not_child << std::endl;
  return 0;
}
