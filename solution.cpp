#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol536;
using namespace std;

Node *Solution::_build(string &s, int &i)
{
  /* find the value - it can be negative */
  auto val = string("");
  while (s[i] == '-' || isdigit(s[i]))
    val.push_back(s[i++]);
  auto root = new Node(stoi(val));
  /* i now points at the next char after the value */
  if (i < s.size() && s[i] == '(')
    /* skip '(', build the left subtree, and skip ')' */
    i++, root->left = _build(s, i), i++;
  if (i < s.size() && s[i] == '(')
    /* skip '(', build the left subtree, and skip ')' */
    i++, root->right = _build(s, i), i++;

  return root;
}

Node *Solution::build(string &s)
{
  auto i = 0;
  /*per the question */
  if (s.empty())
    return nullptr;
  return _build(s, i);
}