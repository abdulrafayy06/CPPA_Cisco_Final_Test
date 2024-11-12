//What will happen when you attempt to compile and run the following code?

#include <deque>

#include <iostream>

#include <algorithm>

using namespace std;

void
printer (int i)
{

  cout << i << ", ";

}

int
main ()
{

  int mynumbers[] = { 8, 9, 7, 6, 4, 1 };

  deque < int >d1 (mynumbers, mynumbers + 6)

  deque < int >::iterator it = lower_bound (d1.begin (), d1.end (), 3);

  d1.push_back (4);    //LINE I

  for_each (it, d1.end (), printer);    //LINE II

  return 0
}

//Options:

/*
compilation error in LINE II
the program outputs 8, 9, 7, 6, 4, 1,
the program outputs 8, 9, 7, 6, 4, 1, 4
compilation error in LINE I
runtime error at LINE I
the program outputs 8, 9, 7, 6, 4, 4,
*/

//Answer: compilation error in LINE II
//Explanation: The program outputs: compilation error in LINE II. The for_each function expects a function object that takes one argument, but the printer function takes two arguments. The program outputs: 8, 9, 7, 6, 4, 1, because the lower_bound function returns an iterator to the first element that is not less than 3. The program doesn't output 8, 9, 7, 6, 4, 1, 4, because the lower_bound function returns an iterator to the first element that is not less than 3. There are no runtime errors in the code.