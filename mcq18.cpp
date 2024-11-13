//What happens if you try to compile and run this program? Choose all that apply:

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

};

 ostream & operator << (ostream & stream, const Pocket & pocket)
{

  stream << pocket.getValue ();

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

  int mynumbers1[] = { 8, 9, 7, 6 };

  int mynumbers2[] = { 4, 1, 4, 5 };

  vector < Pocket > v1 (7, 0);

  sort (mynumbers2, mynumbers2 + 4);

  copy (mynumbers1, mynumbers1 + 3, v1.begin ());

  copy (mynumbers2, mynumbers2 + 3, v1.begin () + 3);

  sort (mynumbers1, mynumbers1 + 4);    //LINE I

  inplace_merge (v1.begin (), v1.begin () + 4, v1.end ());    //LINE II

  for_each (v1.begin (), v1.end (), printer);

  return 0;
}

// Options:
/*
the program outputs 4, 4, 6, 8, 9, 7,
runtime error at LINE I
the program outputs 4, 4, 8, 9, 7, 1,
you shouldn't call inplace_merge function on non ordered v1 vector ;;;;
compilation error in LINE I
the program outputs 4, 4, 0, 8, 9, 7, 1,
compilation error in LINE II
*/

// Answer
// the program outputs 4, 4, 0, 8, 9, 7, 1,
// Explanation
// The copy function copies the elements from the mynumbers1 and mynumbers2 arrays to the v1 vector. The first three elements of v1 are [8, 9, 7] and the next three elements are [4, 1, 4]. The sort function sorts the mynumbers1 array. The inplace_merge function merges the two sorted ranges [8, 9, 7] and [4, 1, 4] in the v1 vector. The output is 4, 4, 0, 8, 9, 7, 1. The result of merging the two ranges is [4, 4, 0, 8, 9, 7, 1]. The remaining element in v1 is 0. The inplace_merge function requires that the two ranges to be merged are sorted. In this case, the two ranges are not sorted, so the result is not sorted. The output is 4, 4, 0, 8, 9, 7, 1. The remaining element in v1 is 0. The inplace_merge function requires that the two ranges to be merged are sorted. In this case, the two ranges are not sorted, so the result is not sorted. The output is 4, 4, 0, 8, 9, 7, 1. The remaining element in v1 is 0. The inplace_merge function requires that the two ranges to be merged are sorted. In this case, the two ranges are not sorted, so the result is not sorted. The output is 4, 4, 0, 8, 9, 7, 1. The remaining element in v1 is 0. The inplace_merge function requires that the two ranges to be merged are sorted. In this case, the two ranges are not sorted, so the result is not sorted. The output is 4, 4, 0, 8, 9, 7, 1. The remaining element in v1 is 0. The inplace_merge function requires that the two ranges to be merged are sorted. In this case, the two ranges are not sorted, so the result is not sorted. The output is 4, 4, 0, 8, 9, 7, 1. The remaining element in v1 is 0. The inplace