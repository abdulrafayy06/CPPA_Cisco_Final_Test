//What will happen when you attempt to compile and run the following code?

#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

int
main ()
{

  int mynumbers[] = { 8, 9, 7, 6, 1, 1, 6, 6 };

  vector < int >v (mynumbers, mynumbers + 8);

  vector < int >::iterator it = search_n (v.begin (), v.end (), 2, 1);    //LINE I

  cout << it - v.begin () << ", ";    //LINE I

  return 0;

}

//Options:

/*
the program outputs 8,
the program outputs 1,
runtime error at LINE I
compilation error in LINE I
compilation error in LINE II
the program outputs 4,
*/

//Answer: the program outputs 4,
//Explanation: The search_n function searches for the first occurrence of the subsequence in the range. The program outputs: 4, because the subsequence {1, 1} is found in the vector v at position 4. The program doesn't output 8, because the search_n function returns an iterator to the first element found in the range. There are no runtime errors in the code.