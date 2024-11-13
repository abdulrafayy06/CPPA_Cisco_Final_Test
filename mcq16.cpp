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

  vector < double >v1 (7);

  sort (mynumbers2, mynumbers2 + 4);

  sort (mynumbers1, mynumbers1 + 4);    //LINE I

   merge (mynumbers1, mynumbers1 + 2, mynumbers2, mynumbers2 + 2, v1.begin ());    //LINE II

  for_each (v1.begin (), v1.end (), printer);

  return 0;

}

//Options
/*
compilation error in LINE II
compilation error in LINE I
the program outputs 1, 4, 6, 7, 0, 0,
the program outputs 1, 4, 6, 7, 0, 0, 0,
the program outputs 1, 4, 4, 6,
runtime error at LINE I
*/

// Answer
//the program outputs 1, 4, 6, 7, 0, 0, 0,
//Explanation
//The merge function merges two sorted ranges. The first range is [mynumbers1, mynumbers1 + 2) and the second range is [mynumbers2, mynumbers2 + 2). The result is stored in v1.begin(). The output is 1, 4, 6, 7, 0, 0, 0, which is the result of merging the two ranges. The first range is [1, 4) and the second range is [4, 6). The result is [1, 4, 4, 6). The remaining elements in v1 are 0, 0, 0.