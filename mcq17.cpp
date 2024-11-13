//What happens if you try to compile and run this program?

#include <vector>

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

  int mynumbers1[] = { 8, 9, 7, 6 };

  int mynumbers2[] = { 4, 1, 4, 5 };

  vector < int >v1 (3);

  sort (mynumbers2, mynumbers2 + 3);

  sort (mynumbers1, mynumbers1 + 3);;    //LINE I

  set_symmetric_difference (mynumbers1, mynumbers1 + 1, mynumbers2, mynumbers2 + 2, v1.begin ());    //LINE II

  for_each (v1.begin (), v1.end (), printer);

  return 0;

}

// Options
/*
runtime error at LINE II
the program outputs 1, 4, 7,
compilation error in LINE I
the program outputs 1, 4, 7, 0, 0,
the program outputs 1, 4, 4,
compilation error in LINE II
runtime error at LINE I
*/

// Answer
// the program outputs 1, 4, 7,
// Explanation
// The set_symmetric_difference function computes the symmetric difference of two sorted ranges. The first range is [mynumbers1, mynumbers1 + 1) and the second range is [mynumbers2, mynumbers2 + 2). The result is stored in v1.begin(). The output is 1, 4, 7, which is the result of computing the symmetric difference of the two ranges. The symmetric difference of two sets is the set of elements that are in either of the sets, but not in their intersection. The first range is [1) and the second range is [1, 4). The result is [1, 4, 7). The remaining elements in v1 are 0, 0.