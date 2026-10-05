# 🔁 Recursion Templates in C++

A complete collection of **C++ recursion templates** for DSA and LeetCode.

The goal is not to memorize every problem. Instead, learn the common recursion patterns and reuse them.

---

# 📚 Table of Contents

* [1. What is Recursion?](#1-what-is-recursion)
* [2. Basic Recursion](#2-basic-recursion)
* [3. Increasing Recursion](#3-increasing-recursion)
* [4. Decreasing Recursion](#4-decreasing-recursion)
* [5. Recursion Returning a Value](#5-recursion-returning-a-value)
* [6. Factorial](#6-factorial)
* [7. Fibonacci](#7-fibonacci)
* [8. Two Recursive Calls](#8-two-recursive-calls)
* [9. Include / Exclude](#9-include--exclude)
* [10. Subsets](#10-subsets)
* [11. Subsequences](#11-subsequences)
* [12. Backtracking](#12-backtracking)
* [13. Permutations](#13-permutations)
* [14. Combinations](#14-combinations)
* [15. Combination Sum](#15-combination-sum)
* [16. String Recursion](#16-string-recursion)
* [17. String Partitioning](#17-string-partitioning)
* [18. Generate Parentheses](#18-generate-parentheses)
* [19. Accumulator Recursion](#19-accumulator-recursion)
* [20. Tail Recursion](#20-tail-recursion)
* [21. Array Recursion](#21-array-recursion)
* [22. Recursive Search](#22-recursive-search)
* [23. Binary Search](#23-binary-search)
* [24. Tree Recursion](#24-tree-recursion)
* [25. Preorder](#25-preorder)
* [26. Inorder](#26-inorder)
* [27. Postorder](#27-postorder)
* [28. Tree Return Value](#28-tree-return-value)
* [29. Divide and Conquer](#29-divide-and-conquer)
* [30. Merge Sort](#30-merge-sort)
* [31. Master Templates](#31-master-templates)
* [32. How to Identify a Recursion Pattern](#32-how-to-identify-a-recursion-pattern)
* [33. Recursion Checklist](#33-recursion-checklist)

---

# 1. What is Recursion?

Recursion is a technique where a function **calls itself** to solve a smaller version of the same problem.

Every recursive solution normally contains:

```text
1. Base Case
2. Current Work
3. Recursive Call
```

General structure:

```cpp
void solve(...)
{
    // Base Case
    if(...)
    {
        return;
    }

    // Current Work

    // Recursive Call
    solve(...);
}
```

---

# 2. Basic Recursion

## Template

```cpp
void solve(int n)
{
    // Base Case
    if(n == 0)
    {
        return;
    }

    // Work
    cout << n << " ";

    // Recursive Call
    solve(n - 1);
}
```

## Example

```cpp
solve(5);
```

Output:

```text
5 4 3 2 1
```

## Pattern

```text
Base Case
    ↓
Do Work
    ↓
Recursive Call
```

---

# 3. Increasing Recursion

Used when we want to move from smaller to larger values.

```cpp
void solve(int i, int n)
{
    if(i > n)
    {
        return;
    }

    cout << i << " ";

    solve(i + 1, n);
}
```

Call:

```cpp
solve(1, 5);
```

Output:

```text
1 2 3 4 5
```

---

# 4. Decreasing Recursion

```cpp
void solve(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << n << " ";

    solve(n - 1);
}
```

Call:

```cpp
solve(5);
```

Output:

```text
5 4 3 2 1
```

---

# 5. Recursion Returning a Value

Use this pattern when every recursive call produces an answer.

```cpp
int solve(int n)
{
    if(n == 0)
    {
        return 0;
    }

    int result = solve(n - 1);

    return n + result;
}
```

Example:

```cpp
cout << solve(5);
```

Output:

```text
15
```

The important pattern is:

```cpp
int result = solve(...);

return combine(result);
```

---

# 6. Factorial

Mathematical definition:

```text
n! = n × (n - 1)!
```

Base case:

```text
0! = 1
```

## Code

```cpp
int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
```

Example:

```cpp
factorial(5)
```

```text
5 × factorial(4)
5 × 4 × factorial(3)
5 × 4 × 3 × factorial(2)
5 × 4 × 3 × 2 × factorial(1)
5 × 4 × 3 × 2 × 1
= 120
```

---

# 7. Fibonacci

Fibonacci:

```text
0 1 1 2 3 5 8 13 ...
```

## Code

```cpp
int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}
```

## Pattern

```text
              fib(n)
             /      \
       fib(n-1)    fib(n-2)
```

This is an example of **multiple recursive calls**.

---

# 8. Two Recursive Calls

General template:

```cpp
void solve(...)
{
    if(base_case)
    {
        return;
    }

    // Choice 1
    solve(...);

    // Choice 2
    solve(...);
}
```

Tree:

```text
                 solve
                /     \
          Choice 1   Choice 2
             /          \
          solve        solve
```

This pattern appears in:

* Fibonacci
* Subsets
* Subsequences
* Decision problems
* Binary choices
* Backtracking

---

# 9. Include / Exclude

One of the most important recursion patterns.

At every element, we have two choices:

```text
Include
Exclude
```

## Template

```cpp
void solve(int index)
{
    if(index == n)
    {
        return;
    }

    // Include
    current.push_back(arr[index]);

    solve(index + 1);

    current.pop_back();

    // Exclude
    solve(index + 1);
}
```

## Decision Tree

```text
                  []
                /    \
          Include    Exclude
             /          \
           [x]           []
```

Used for:

* Subsets
* Subsequences
* Subset Sum
* Knapsack
* Combination problems

---

# 10. Subsets

## Template

```cpp
class Solution
{
public:

    vector<vector<int>> ans;
    vector<int> current;

    void solve(int index, vector<int>& nums)
    {
        if(index == nums.size())
        {
            ans.push_back(current);
            return;
        }

        // Include
        current.push_back(nums[index]);

        solve(index + 1, nums);

        current.pop_back();

        // Exclude
        solve(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        solve(0, nums);

        return ans;
    }
};
```

For:

```text
nums = [1,2]
```

Possible subsets:

```text
[]
[1]
[2]
[1,2]
```

---

# 11. Subsequences

A subsequence maintains the original order but can skip elements.

## Template

```cpp
void solve(int index,
           string& s,
           string& current)
{
    if(index == s.length())
    {
        cout << current << endl;
        return;
    }

    // Take
    current.push_back(s[index]);

    solve(index + 1, s, current);

    current.pop_back();

    // Not Take
    solve(index + 1, s, current);
}
```

For:

```text
abc
```

Subsequences include:

```text
""
"a"
"b"
"c"
"ab"
"ac"
"bc"
"abc"
```

---

# 12. Backtracking

Backtracking is:

```text
Choose
   ↓
Explore
   ↓
Undo
```

## Master Template

```cpp
void solve(...)
{
    // Base Case
    if(base_case)
    {
        ans.push_back(current);
        return;
    }

    for(...)
    {
        // Choose
        current.push_back(...);

        // Explore
        solve(...);

        // Undo
        current.pop_back();
    }
}
```

## The Most Important Line

```cpp
current.pop_back();
```

This is the **undo step**.

---

# 13. Permutations

For permutations, every position can choose an unused element.

## Template

```cpp
class Solution
{
public:

    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& nums,
               vector<bool>& used)
    {
        if(current.size() == nums.size())
        {
            ans.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i])
            {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            solve(nums, used);

            // Undo
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool> used(nums.size(), false);

        solve(nums, used);

        return ans;
    }
};
```

For:

```text
[1,2,3]
```

Examples:

```text
123
132
213
231
312
321
```

---

# 14. Combinations

Combinations do not care about order.

## Template

```cpp
void solve(int start,
           vector<int>& current)
{
    if(...)
    {
        ans.push_back(current);
        return;
    }

    for(int i = start; i < n; i++)
    {
        current.push_back(i);

        solve(i + 1, current);

        current.pop_back();
    }
}
```

Important:

```cpp
solve(i + 1, ...)
```

This prevents going backwards and creating duplicate combinations.

---

# 15. Combination Sum

When an element can be used multiple times:

```cpp
void solve(int index,
           int target,
           vector<int>& current)
{
    if(target == 0)
    {
        ans.push_back(current);
        return;
    }

    if(index >= nums.size() || target < 0)
    {
        return;
    }

    // Take
    current.push_back(nums[index]);

    solve(index,
          target - nums[index],
          current);

    current.pop_back();

    // Skip
    solve(index + 1,
          target,
          current);
}
```

### Important Difference

If reuse is allowed:

```cpp
solve(index, ...)
```

If reuse is NOT allowed:

```cpp
solve(index + 1, ...)
```

---

# 16. String Recursion

```cpp
void solve(int index, string& s)
{
    if(index == s.length())
    {
        return;
    }

    cout << s[index];

    solve(index + 1, s);
}
```

Example:

```text
HELLO
```

Processing:

```text
H
E
L
L
O
```

---

# 17. String Partitioning

Used in problems such as:

* Palindrome Partitioning
* String splitting
* Partition problems

## Template

```cpp
void solve(int start,
           string& s,
           vector<string>& current)
{
    if(start == s.length())
    {
        ans.push_back(current);
        return;
    }

    for(int end = start;
        end < s.length();
        end++)
    {
        if(isValid(s, start, end))
        {
            current.push_back(
                s.substr(
                    start,
                    end - start + 1
                )
            );

            solve(end + 1, s, current);

            current.pop_back();
        }
    }
}
```

Pattern:

```text
Start
 ↓
Try every possible ending
 ↓
Check validity
 ↓
Choose substring
 ↓
Recursive call
 ↓
Undo
```

---

# 18. Generate Parentheses

A very important backtracking problem.

## Template

```cpp
class Solution
{
public:

    vector<string> ans;

    void solve(int open,
               int close,
               string current)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(current);
            return;
        }

        // Add '('
        if(open > 0)
        {
            solve(open - 1,
                  close,
                  current + '(');
        }

        // Add ')'
        if(close > open)
        {
            solve(open,
                  close - 1,
                  current + ')');
        }
    }

    vector<string> generateParenthesis(int n)
    {
        solve(n, n, "");

        return ans;
    }
};
```

### Important Condition

```cpp
if(close > open)
```

We can add `)` only when there is an unmatched `(`.

---

# 19. Accumulator Recursion

Useful when carrying information through recursive calls.

```cpp
void solve(int n, int sum)
{
    if(n == 0)
    {
        cout << sum;
        return;
    }

    solve(n - 1, sum + n);
}
```

Call:

```cpp
solve(5, 0);
```

Result:

```text
15
```

Flow:

```text
sum = 0
 ↓
0 + 5 = 5
 ↓
5 + 4 = 9
 ↓
9 + 3 = 12
 ↓
12 + 2 = 14
 ↓
14 + 1 = 15
```

---

# 20. Tail Recursion

The recursive call is the last operation.

```cpp
void solve(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << n << " ";

    solve(n - 1);
}
```

Pattern:

```text
Work
 ↓
Recursive Call
```

---

# 21. Array Recursion

```cpp
void solve(vector<int>& arr, int index)
{
    if(index == arr.size())
    {
        return;
    }

    cout << arr[index] << " ";

    solve(arr, index + 1);
}
```

Call:

```cpp
solve(arr, 0);
```

This pattern is useful for:

* Array traversal
* Searching
* Checking conditions
* Recursive sorting
* Recursive processing

---

# 22. Recursive Search

```cpp
bool search(vector<int>& arr,
            int index,
            int target)
{
    if(index == arr.size())
    {
        return false;
    }

    if(arr[index] == target)
    {
        return true;
    }

    return search(arr,
                  index + 1,
                  target);
}
```

Pattern:

```text
Check current
     ↓
If found → true
     ↓
Otherwise → search next
```

---

# 23. Binary Search

Recursive binary search:

```cpp
int binarySearch(vector<int>& arr,
                 int low,
                 int high,
                 int target)
{
    if(low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] == target)
    {
        return mid;
    }

    if(target < arr[mid])
    {
        return binarySearch(
            arr,
            low,
            mid - 1,
            target
        );
    }

    return binarySearch(
        arr,
        mid + 1,
        high,
        target
    );
}
```

Pattern:

```text
             Array
            /     \
        Left       Right
```

Only one half is explored.

---

# 24. Tree Recursion

Basic binary tree template:

```cpp
void solve(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    // Process current node

    solve(root->left);

    solve(root->right);
}
```

Tree structure:

```text
             1
           /   \
          2     3
         / \
        4   5
```

Recursion naturally moves through:

```text
Root
 ↓
Left
 ↓
Left
 ↓
...
```

---

# 25. Preorder

Order:

```text
ROOT → LEFT → RIGHT
```

```cpp
void preorder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->val << " ";

    preorder(root->left);

    preorder(root->right);
}
```

---

# 26. Inorder

Order:

```text
LEFT → ROOT → RIGHT
```

```cpp
void inorder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}
```

For a Binary Search Tree, inorder traversal gives sorted order.

---

# 27. Postorder

Order:

```text
LEFT → RIGHT → ROOT
```

```cpp
void postorder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->val << " ";
}
```

---

# 28. Tree Return Value

Example: Maximum Depth of Binary Tree.

```cpp
int solve(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = solve(root->left);

    int right = solve(root->right);

    return 1 + max(left, right);
}
```

Pattern:

```text
Solve Left
    ↓
Solve Right
    ↓
Combine
```

General tree-return template:

```cpp
ReturnType solve(TreeNode* root)
{
    if(root == NULL)
    {
        return base_value;
    }

    ReturnType left =
        solve(root->left);

    ReturnType right =
        solve(root->right);

    return combine(left, right);
}
```

---

# 29. Divide and Conquer

Divide and Conquer follows:

```text
Divide
  ↓
Solve
  ↓
Combine
```

## Template

```cpp
ReturnType solve(problem)
{
    // Base Case
    if(small_problem)
    {
        return answer;
    }

    // Divide
    problem1 = ...;
    problem2 = ...;

    // Conquer
    auto answer1 = solve(problem1);
    auto answer2 = solve(problem2);

    // Combine
    return combine(answer1, answer2);
}
```

Used in:

* Merge Sort
* Quick Sort
* Binary Search
* Tree problems

---

# 30. Merge Sort

```cpp
void mergeSort(vector<int>& arr,
               int low,
               int high)
{
    if(low >= high)
    {
        return;
    }

    int mid =
        low + (high - low) / 2;

    mergeSort(arr,
              low,
              mid);

    mergeSort(arr,
              mid + 1,
              high);

    merge(arr,
          low,
          mid,
          high);
}
```

Pattern:

```text
                 Array
                /     \
             Left     Right
             /          \
           ...          ...
                ↓
              Merge
```

---

# 31. Master Templates

These are the most important templates to memorize.

---

## Template 1: Simple Recursion

```cpp
void solve(...)
{
    if(base_case)
    {
        return;
    }

    // Work

    solve(...);
}
```

---

## Template 2: Return Recursion

```cpp
int solve(...)
{
    if(base_case)
    {
        return base_value;
    }

    int result = solve(...);

    return combine(result);
}
```

---

## Template 3: Two Choices

```cpp
void solve(...)
{
    if(base_case)
    {
        return;
    }

    solve(...); // Choice 1

    solve(...); // Choice 2
}
```

---

## Template 4: Include / Exclude

```cpp
void solve(int index)
{
    if(index == n)
    {
        return;
    }

    // Include
    current.push_back(arr[index]);

    solve(index + 1);

    current.pop_back();

    // Exclude
    solve(index + 1);
}
```

---

## Template 5: Backtracking

```cpp
void solve(...)
{
    if(base_case)
    {
        ans.push_back(current);
        return;
    }

    for(...)
    {
        // Choose
        current.push_back(...);

        // Explore
        solve(...);

        // Undo
        current.pop_back();
    }
}
```

---

## Template 6: Tree Recursion

```cpp
int solve(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left =
        solve(root->left);

    int right =
        solve(root->right);

    return combine(left, right);
}
```

---

## Template 7: Divide and Conquer

```cpp
ReturnType solve(...)
{
    if(base_case)
    {
        return answer;
    }

    // Divide

    auto left = solve(left_part);

    auto right = solve(right_part);

    // Combine

    return combine(left, right);
}
```

---

# 32. How to Identify a Recursion Pattern

When you see a recursion problem, ask these questions.

### Question 1

**What is the smallest possible problem?**

That becomes your:

```text
BASE CASE
```

---

### Question 2

**Can I make the problem smaller?**

For example:

```cpp
n - 1
```

or:

```cpp
index + 1
```

or:

```cpp
left + right
```

---

### Question 3

**Does the problem have choices?**

If yes:

```text
Choice 1
Choice 2
```

Think:

```cpp
solve(...)
solve(...)
```

---

### Question 4

**Do I need to undo my choice?**

If yes, you probably need:

```text
BACKTRACKING
```

Pattern:

```cpp
choose();

solve();

undo();
```

---

### Question 5

**Am I returning an answer?**

If yes:

```cpp
int solve(...)
```

instead of:

```cpp
void solve(...)
```

---

# 33. Recursion Checklist

Before writing recursive code:

```text
┌─────────────────────────────┐
│      RECURSION CHECKLIST    │
└─────────────────────────────┘

1. Identify the BASE CASE

2. Identify the SMALLER PROBLEM

3. Decide what CURRENT WORK is

4. Make the RECURSIVE CALL

5. Decide whether the function:
   → returns a value
   → modifies a global answer
   → modifies a current path

6. If using backtracking:
   → CHOOSE
   → EXPLORE
   → UNDO

7. Check whether the recursion
   actually moves toward the base case
```

---

# 🧠 Quick Pattern Recognition

| Problem Type         | Pattern                   |
| -------------------- | ------------------------- |
| Print 1 to N         | Simple recursion          |
| Print N to 1         | Simple recursion          |
| Factorial            | Return recursion          |
| Sum of N             | Return recursion          |
| Fibonacci            | Two recursive calls       |
| Subsets              | Include / Exclude         |
| Subsequences         | Include / Exclude         |
| Permutations         | Backtracking + Used       |
| Combinations         | Backtracking + Start      |
| Combination Sum      | Backtracking              |
| Generate Parentheses | Backtracking + Conditions |
| Palindrome Partition | Backtracking + Partition  |
| Word Search          | Backtracking + Grid       |
| N-Queens             | Backtracking              |
| Tree Traversal       | Tree recursion            |
| Tree Height          | Tree return recursion     |
| Binary Search        | Divide and conquer        |
| Merge Sort           | Divide and conquer        |
| Quick Sort           | Divide and conquer        |

---

# 🔥 Golden Rule

Almost every recursion/backtracking problem can be reduced to:

```text
                RECURSION
                    │
          ┌─────────┴─────────┐
          │                   │
      ONE CALL            MULTIPLE CALLS
          │                   │
      Simple              Choices
      Recursion               │
                              ↓
                       ┌──────────────┐
                       │              │
                  Include/Exclude  Backtracking
                       │              │
                    Subsets       Permutations
                    Subseq.       Combinations
                                  N-Queens
                                  Word Search
```

---

# ⭐ The 5 Lines You Should Remember

For most backtracking problems:

```cpp
for(...)
{
    // 1. CHOOSE
    current.push_back(...);

    // 2. EXPLORE
    solve(...);

    // 3. UNDO
    current.pop_back();
}
```

For include/exclude:

```cpp
// Include
current.push_back(arr[index]);
solve(index + 1);
current.pop_back();

// Exclude
solve(index + 1);
```

For tree recursion:

```cpp
left = solve(root->left);

right = solve(root->right);

return combine(left, right);
```

---

# 🚀 Recursion Learning Roadmap

```text
BEGINNER
   │
   ├── Basic Recursion
   ├── Factorial
   ├── Sum
   └── Array Recursion
          │
          ▼
INTERMEDIATE
   │
   ├── Multiple Recursion
   ├── Fibonacci
   ├── Include / Exclude
   ├── Subsets
   └── Subsequences
          │
          ▼
BACKTRACKING
   │
   ├── Permutations
   ├── Combinations
   ├── Combination Sum
   ├── Generate Parentheses
   ├── Palindrome Partition
   └── Word Search
          │
          ▼
TREES
   │
   ├── DFS
   ├── Preorder
   ├── Inorder
   ├── Postorder
   └── Tree DP
          │
          ▼
ADVANCED
   │
   ├── Divide & Conquer
   ├── Merge Sort
   ├── Quick Sort
   └── Advanced Backtracking
```

---

# 💡 Final Mental Model

Whenever you get a recursion problem, first write:

```cpp
void solve(...)
{
    // What is the smallest case?
    if(...)
    {
        return;
    }

    // What is my choice?

    // What smaller problem should I solve?

    solve(...);

    // Do I need to undo something?
}
```

Then convert it into one of these patterns:

```text
Simple Recursion
       ↓
Return Recursion
       ↓
Two Choices
       ↓
Include / Exclude
       ↓
Backtracking
       ↓
Tree Recursion
       ↓
Divide & Conquer
```

**Don't memorize solutions. Memorize the pattern.**
