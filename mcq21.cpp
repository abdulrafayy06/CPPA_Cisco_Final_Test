//What happens if you try to compile and run this program?

#include <vector>

#include <iostream>

#include <algorithm>

using namespace std;

class Pocket
{

  int value;

public:

    Pocket (int value):value (value)
  {
  }

  int getValue () const
  {
    return value;
  }

  bool operator < (const Pocket & _Right) const
  {
    return value < _Right.value;
  }

  bool operator < (const int &_Right) const
  {
  return value < _Right;
  }

  operator  int () const
  {
    return value;
  }

};
ostream & operator << (ostream & stream, const Pocket & pocket)
{

  stream << pocket.getValue ()

  return stream;

}

void
printer (Pocket i)
{
 
  cout << i << ", ";
 
}

int
main ()
{

  Pocket mynumbers1[] = { 8, 9, 7, 6 };

  int mynumbers2[] = { 4, 1, 4, 5 };

  vector < Pocket > v1 (7, 0);

  sort (mynumbers2, mynumbers2 + 4);

  sort (mynumbers1, mynumbers1 + 4);    //LINE I

  set_symmetric_difference (mynumbers1, mynumbers1 + 3, mynumbers2, mynumbers2 + 3, v1.begin ());    //LINE II

  for_each (v1.begin (), v1.end (), printer);

  return 0;

}

// Options:
/*
the program outputs 1, 4, 4, 6, 7, 8,
compilation error in LINE II
the program outputs 1, 4, 4, 6, 7, 8, 0,
the program outputs 4, 8, 3, 1,
runtime error at LINE I
compilation error in LINE I
*/

// Answer: compilation error in LINE II
//Explanation:
// The set_symmetric_difference function requires that the destination range is at least as large as the largest of the two source ranges. In this case, the destination range is of size 7, which is larger than the largest source range of size 4. The program will compile and run without any errors, and the output will be 1, 4, 4, 6, 7, 8, 0, which is the result of the set_symmetric_difference operation on the two source ranges. The set_symmetric_difference function returns the elements that are unique to each of the two source ranges, and stores them in the destination range. In this case, the elements that are unique to the first source range are 6, 7, and 8, and the elements that are unique to the second source range are 1 and 4. The destination range is of size 7, so the remaining elements are filled with zeros.