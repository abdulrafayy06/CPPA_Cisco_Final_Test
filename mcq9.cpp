//What will happen when you attempt to compile and run the following code?

#include <vector>

#include <iostream>

#include <set>

#include <deque>

#include <algorithm>

using namespace std;

template < class T > struct Out
{

  ostream & out;

  Out (ostream & o):out (o)
  {
  }

  void operator () (const T & val)
  {

     out << val << ", ";

  }

};

struct Sequence
{

  int start;

    Sequence (int start):start (start)
  {
  }

  int operator () ()
  {

    return start++ % 7;

  }

 };

int
main ()
{

  vector < int >v1 (3);    //LINE I

  generate (v1.begin (), v1.end (), Sequence (10));    LINE I

  set < int >s1 (v1.rbegin (), v1.rend ());

  deque < int >d1 (s1.rbegin (), s1.rend ());

  reverse (v1.begin (), v1.end ());

  reverse (d1.begin (), d1.end ());    //LINE II

  for_each (s1.begin (), s1.end (), Out < int >(cout));

  for_each (d1.begin (), d1.end (), Out < int >(cout));

return 0;

}


//Options:

/*
the program outputs 3, 4, 5, 3, 4, 5, 3, 4, 5,
the program outputs 3, 4, 5, 3, 4, 5,
the program outputs 3, 4, 5, 5, 4, 3,
compilation error in LINE I
runtime error at LINE I
compilation error in LINE II
*/

//Answer: compilation error in LINE I
//Explanation: The program outputs: compilation error in LINE I. The generate function requires a function object that takes no arguments. The program doesn't output 3, 4, 5, 3, 4, 5, because the generate function generates a sequence of numbers starting from 10. The program doesn't output 3, 4, 5, because the for_each function outputs the elements in the order they are stored in the container. There are no runtime errors in the code.