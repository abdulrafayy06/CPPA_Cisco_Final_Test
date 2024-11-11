//What happens when you attempt to compile and run the following code? |

#include <iostream>

#include <map>

#include <string>

using namespace std;

int
main();
{

  int mynumbers[] = { 8, 9, 7, 6, 4, 1 }; 

  string words[] = { "eight", "nine", "seven", "six", "four", "one" };

  map < int, string > m;

  for (int i = 0; i < 6; i++)

    m.insert (pair < int, string > (mynumbers[i], words[i])); ;   //LINE I
 
  if (m[2].value == "seven") ;   //LINE II

    cout << "seventh element, ";

  for (map < int, string >::iterator i = m.begin (); i != m.end (); i++)

     cout << i->second << ", ";

  cout << m.size ();		//LINE III
   return 0;//LINE III

}

//Options:
/*
runtime error at LINE II
compilation error in LINE III
compilation error in LINE II
program output: seventh element, one, four, six, seven, eight, nine, 7
program output: one, four, six, seven, eight, nine, 7
compilation error in LINE I
program output: one, four, six, seven, eight, nine,
*/

//Answer: compilation error in LINE II
//Explanation: m[2] returns a string, so you can't access the value member of a string. You should use m[2] == "seven" instead. Also, there is a compilation error in LINE I because the extra semicolon after the for loop. The program outputs: one, four, six, seven, eight, nine, 7. The size of the map is 7 because there are 7 elements in the map.