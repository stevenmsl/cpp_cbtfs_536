#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol536;

/*
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   /
  3   1 5
*/

tuple<string> testFixture1()
{
  return make_tuple("4(2(3)(1))(6(5))");
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 " << endl;
  Solution sol;
  auto result = sol.build(get<0>(f));
  cout << "Expect to see 4" << endl;
  auto expectRoot = result ? to_string(result->val) : "0";
  cout << expectRoot << endl;
  cout << "Expect to see 2" << endl;
  auto expectLeft = result && result->left ? to_string(result->left->val) : "0";
  cout << expectLeft << endl;
  cout << "Expect to see 3" << endl;
  auto expectLeftLeft = result && result->left && result->left->left ? to_string(result->left->left->val) : "0";
  cout << expectLeftLeft << endl;
  cout << "Expect to see 6" << endl;
  auto expectRight = result && result->right ? to_string(result->right->val) : "0";
  cout << expectRight << endl;
}

main()
{
  test1();
  return 0;
}