//Which sentences are 100% true about the code below (multiple choice) when control reaches return:

#include <vector>

#include <iostream>

using namespace std;

int
main ()
{

vector < int >v1 (10, -1);

vector < int >v2; 

v2.reserve (10);

  for (unsigned i = 0; i < 10; i++)

    {

    v2.push_back (i);

    }
  cout << v2[0] << ", " << v1[0];

  return 0;

}

//Options:
/*
value returned by size() is the same for vectors v1 and v2
both vectors v1 and v2 have the same capacity

program outputs: -1,10

program outputs: 0, 0

program outputs: 0, -1

program outputs: -1, 0

*/

//Answer: program outputs: 0, -1
//Explanation: v2.reserve(10) only reserves memory for 10 elements, but the size of v2 is still 0. v2.push_back(i) adds elements to the vector, so v2[0] is 0. v1[0] is -1 because v1 was initialized with 10 elements, all set to -1.