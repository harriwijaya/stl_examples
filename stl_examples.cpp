#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //
    std::cout << "Test..." << std::endl;

    // all_of
    // Check if every element in the range satisfies the condition.
    {
        std::vector<int> v{ 5, 3, 7, 9, 4 };
        auto lambda = [](int i) { return i > 1; };
        bool allGreaterThanOne = std::all_of(v.begin(), v.end(), lambda); // true

        std::cout << allGreaterThanOne << std::endl;
    }

    // any_of
    // Check if any element in the range satisfies the condition.
    {
        std::vector<int> v{ 5, 3, 7, 9, 4 };
        auto lambda = [](int i) { return i > 8; };
        bool anyGreaterThanEight = std::any_of(v.begin(), v.end(), lambda); // true

        std::cout << anyGreaterThanEight << std::endl;
    }

    // none_of
    // Check if none of the elements in the range satisfies the condition.
    {
        std::vector<int> v{ 5, 3, 7, 9, 4 };
        auto lambda = [](int i) { return i > 10; };
        bool noneGreaterThanTen = std::none_of(v.begin(), v.end(), lambda); // true

        std::cout << noneGreaterThanTen << std::endl;
    }

    // for_each
    // Does something for each item in a range.
    {
        std::vector<int> v{ 5, 3, 7, 2, 1 };
        auto lambda = [](int i) { std::cout << i << " "; };
        std::for_each(v.begin(), v.end(), lambda); // Prints each element in the container.

        std::cout << std::endl;
    }

    // find
    // Find an item in a given range.
    {
        std::vector<int> v{ 5, 3, 7, 9, 4 };
	
        std::vector<int>::iterator it = std::find(v.begin(), v.end(), 7);

        std::cout << *it << " " << it - v.begin() << std::endl;
    }

    // find_if
    // Find the first item that satisfies a condition.
    {
        std::vector<int> v{ 5, 3, 7, 9, 4 };
	
        auto lambda = [](int i) { return i > 6; };
        std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), lambda); 
        int firstElementGreaterThanSix = *it; // 7

        std::cout << firstElementGreaterThanSix << std::endl;
    }

    // findifnot
    // Find the first item that does not satisfy a condition.
    {
        std::vector<int> v{ 5, 3, 7, 9, 4 };
	
        auto lambda = [](int i) { return i > 6; };
        std::vector<int>::iterator it = std::find_if_not(v.begin(), v.end(), lambda); 
        int firstElementLessThanSix = *it; // 5

        std::cout << firstElementLessThanSix << std::endl;
    }

    // find_end
    // For a range, find the last occurence of a sequence in that range. (Ex. Get the last “oo” in “moo_cookies”.)
    {
        std::string s = "moo_cookies";
        std::string t = "oo";
        std::string::iterator it = std::find_end(s.begin(), s.end(), t.begin(), t.end()); 
        // Points to the 'o' after the 'c'

        std::cout << *it << " " << it - s.begin() << std::endl;
    }

    // findfirstof
    // For a range, find the first occurence of a sequence in that range. (Ex. Get the first “oo” in “moo_cookies”.)
    {
        std::string s = "moo_cookies";
        std::string t = "oo";
        std::string::iterator it = std::find_first_of(s.begin(), s.end(), t.begin(), t.end()); 
        // Points to the 'o' after the 'm

        std::cout << *it << " " << it - s.begin() << std::endl;
    }

    // adjacent_find
    // Find the first occurrence of two consecutive elements that match in a range. (Ex. The “cc” in “accentt”.)
    {
        std::string s = "accentt";
        std::string::iterator it = std::adjacent_find(s.begin(), s.end()); // Points to the first 'c'

        std::cout << *it << " " << it - s.begin() << std::endl;
    }

    // count
    // Count the number of times an item appears in the range.
    {
        std::vector<int> v{ 5, 3, 7, 9, 3, 4 };
	
        int countOfThree = std::count(v.begin(), v.end(), 3); // 2

        std::cout << countOfThree << std::endl;
    }

    // count_if
    // Count the number of occurrences satisfying the lambda function.
    {
        std::vector<int> v{ 5, 3, 7, 2, 1 };
        auto lambda = [](int i) { return i > 2; };
        int count = count_if(v.begin(), v.end(), lambda);

        std::cout << count << std::endl;
    }

    // mismatch
    // Finds the first occurrence where two rangers differ.
    {
        std::vector<int> v1{ 5, 3, 7, 9 };
        std::vector<int> v2{ 5, 3, 2, 9 };
            
        std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::mismatch(v1.begin(), v1.end(), v2.begin());
        int element1 = *p.first; // 7
        int element2 = *p.second; // 2

        std::cout << element1 << " " << element2 << std::endl;
    }

    // equal
    // Check if the elements in two ranges are equal.
    {
        std::vector<int> v1{ 5, 4, 6 };
        std::vector<int> v2{ 5, 4, 6 };
        bool isEqual = std::equal(v1.begin(), v1.end(), v2.begin()); // true

        std::cout << isEqual << std::endl;
    }

    // is_permutation
    // Check if a range is a permutation of another.
    {
        std::vector<char> v1{ 'g', 'o', 'd' };
        std::vector<char> v2{ 'd', 'o', 'g' };
            
        bool isPermutation = std::is_permutation(v1.begin(), v1.end(), v2.begin()); // true

        std::cout << isPermutation << std::endl;
    }

    // search
    // Check if a range contains a certain sequence. (Ex. Does “this” contain “is”?)
    {
        std::vector<char> v1{ 't', 'h', 'i', 's' };
        std::vector<char> v2{ 'i', 's' };
        std::vector<char> v3{ 'a', 'u'};
            
        std::vector<char>::iterator it = std::search(v1.begin(), v1.end(), v2.begin(), v2.end()); 
        // Points to the 'i' in v1
        std::cout << *it << " at " << it - v1.begin() << ", found? = " << (it != v1.end()) << std::endl;

        it = std::search(v1.begin(), v1.end(), v3.begin(), v3.end()); 
        std::cout << *it << " at " << it - v1.begin() << ", found? = " << (it != v1.end()) << std::endl;
    }

    // search_n
    // Search a range for a certain number of a specific item. (Ex. Find two ‘e’s in a row in the word ‘esteem’.)
    {
        //
    }

    // lexicographical_compare
    // Lexographically compare two items to find out which is ‘smaller’.
    {
        //
    }

    /* Modify/Copy A Range
       A range is going to be edited or copied. */
    
    // copy
    // Copy the elements from one range into another.
    {
        //
    }

    // copy_n
    // Copy the first n elements from one range into another.
    {
        //
    }

    // copy_if
    // Copy elements from one range into another if the condition we specify is met.
    {
        //
    }

    // copy_backward
    // Copy the elements from one range into another, starting from the back elements and going to the front.
    {
        //
    }

    // move
    // Move the elements from one range into another. The elements in the original range are valid, but may not be what they were before the move.
    {
        //
    }

    // move_backward
    // Move the elements from one range into another, starting from the back elements and going to the front. The elements in the original range are valid, but may not be what they were before the move.
    {
        //
    }

    // swap
    // Swaps the values of two items.
    {
        //
    }

    // swap_ranges
    // Given two ranges, swaps the items in them (using the swap function).
    {
        //
    }

    // iter_swap
    // Swap the values that two iterators point too.
    {
        //
    }

    // 

    return 0;
}