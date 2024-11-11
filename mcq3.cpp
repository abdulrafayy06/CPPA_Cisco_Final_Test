//What happens when you attempt to compile and run the following code?
#include <iostream>

#include <map>

using namespace std;

int
main ()
{

  int mynumbers[] = { 8, 9, 7, 6, 4, 1, 4 };

  string words[] = { "eight", "nine", "seven", "six", "four", "one", "four" };

  map < int, string > m;

  for (int i = 0; i < 7; i++)
    {

    m.insert (pair < int, string > (mynumbers[i], words[i]));    //LINE I

    }

  if (m.count (4) == 2)

    m.erase (2);        //LINE II

  for (map < int, string >::iterator i = m.begin (); i != m.end (); i++)
 
    {

      cout << i->first << ", ";

    }

  return 0;

}

//Options:
/*

compilation error in LINE I
compilation error in LINE II
runtime error at LINE II
program output: 1, 6, 7, 8, 9, 4
program output: 1, 4, 7, 8, 9, 4,
program output: 1, 4, 6, 7, 8, 9,
program output: 1, 4, 6, 7, 8, 9, 4,

*/

//The answer is program output: 1, 4, 6, 7, 8, 9,
//Explanation: The program outputs: 1, 4, 6, 7, 8, 9, because the map is sorted by key. The map has two elements with key 4, so the map size is 6. The program doesn't output the last 4 because the map is sorted by key, and the last 4 is the second element with key 4. There are no compilation errors or runtime errors in the code.