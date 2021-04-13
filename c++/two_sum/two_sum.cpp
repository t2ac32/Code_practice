#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <unordered_set>

using namespace std;

/*
given a set of ordered or unordered numbers. 
Find two numbers in the list that add up to a given target number.

e.j.
numbers ={3 ,6, 9,12,15,4,2,1,30} 
target = 15
return 6 and 9
*/

/*
Good Questions to make
-  are inputes always valid?
- is the set always ordered
- is the target alway valid for example .. a engative target
*/

/*
Analyzying the problem :

- we want to numbers that add up to a target. 
- this tell us that we will make a adding (+) operation.
- at the same time we know that we will be given at least the target that means:
  a + b = target
  - where a and b can be found in the numbers set
  - a = target - b , this is a difference operation that will give us the second number to serch 
    in the numbers array.
*/

/* A simple solution */

bool twoSum(const list<int> &nums, int target, std::pair<int, int> &result)
{
    bool pairFound = false;
    // save the visited numbers
    std::unordered_set<int> visited_nums;

    // iterate to find the first number
    for (const auto &n : nums)
    {
        if (n <= target)
        {
            bool remainderExists = (visited_nums.find(target - n) != visited_nums.end());
            if (remainderExists)
            {
                result.first = target - n;
                result.second = n;
                pairFound = true;
                break;
            }
            visited_nums.insert(n);
        }
    }
    return pairFound;
}

void printPairs(const list<int> &&nums, int target)
{
    std::pair<int, int> pair;
    bool pairFound = twoSum(nums, target, pair);
    if (pairFound)
    {
        cout << pair.first << '\t' << pair.second << std::endl;
    }
    else
    {
        cout << "Pair not found" << std::endl;
    }
}

int main()
{
    //base test case
    printPairs({3, 6, 9, 12, 15, 4, 2, 1, 30}, 15);

    //other test cases:
    printPairs({3, 6, 9, 12, 15, 4, 2, 1, 30}, 31);
    printPairs({3, 6, 9, 12, 15, 4, 2, 1, 30}, 30);
    printPairs({3, 6, 9, 12, 15, 4, 2, 1, 30}, -1);
    printPairs({3, 6, 9, 12, 15, 4, 2, 1, 30}, 10000);
    return 0;
}