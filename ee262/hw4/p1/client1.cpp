#include<iostream>
#include<string>
#include"triple.h"

using std::string;
using std::endl;
using std::cout;

using simSequence::Triple;

int main(void) {
  Triple<long> var1(11, 1500, 780000, string("var1"));
  var1.print();
  cout<<"var1's second element: "<<var1.getSecond()<<endl;

  cout<<endl;
  Triple<char> var2('t', 'n', 'o', string("var2"));
  var2.print();
  cout<<"var2's third element: "<<var2.getThird()<<endl;

  cout<<endl;
  Triple<double> var3(0.44, 1.567, -89.432523, string("var3"));
  var3.print();
  cout<<"var3's first element: "<<var3.getFirst()<<endl;

  cout<<endl;
  Triple<string> var4(string("go"), string("away"), string("corona"), string("var4"));
  var4.print();

  cout<<endl;
  Triple<int> var5(-10, 20, 30);
  var5.print();

  return 0;
}

