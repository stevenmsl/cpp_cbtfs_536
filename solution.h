
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

/*takeaways
  - 4(2(3)(1))(6(5))
  - so from 4's perspective the left tree is (2(3)(1)) and the right tree is (6(5))
    - you will build the left tree when you encounter the first '('
      and skip the matching ')' once you're done building it
    - so for 4's left child we are building this tree 2(3)(1)
      - 2's left child is 3 and this what we will build first
        and the right child 1
           2
          / \
         3   1
    - back to 4, after we skip the ')', we can go ahead and build the
      right child (6(5))

*/

using namespace std;
namespace sol536
{
    class Solution
    {
    private:
        Node *_build(string &s, int &i);

    public:
        Node *build(string &s);
    };
}
#endif