#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
using namespace sdds;
int main() {
   Stack<double> d;
   Stack<double> a;
   Stack<string> s;
   d.push(1.2).push(2.3).push(3.5).push(4.6);
   a = d;//copy assignment test
   s.push("Green").push("Blue").push("Black");
   cout << d.depth() << " doubles in the Stack \"d\"" << endl;
   cout << s.depth() << " strings in the Stack \"s\"" << endl;
   while (d) {
      cout << d.pop() << endl;
   }
   while (a) {
       cout << "copy assignment test" << endl;
       cout << a.pop() << endl;//test
   }
   while (s) {
      cout << s.pop() << endl;
   }
   return 0;
}