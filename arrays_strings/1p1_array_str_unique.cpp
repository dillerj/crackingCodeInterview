/*  Jed Diller
 * 	Cracking the Code Interview Solutions
 * 	Ch1.1 isUnique()
 */

/**********************************
 * Includes for funcs
 **********************************/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std; 

/**********************************
 * Includes for testing
 **********************************/
#include <time.h>
#include <sys/types.h>    

/**********************************
 * Description
 **********************************/
/*
 * Determine if a string is all unique characters. 
 * What if no data structures are allowed? No array or otherwise
 */

/**********************************
 * Define Functions
 **********************************/
 
// O(n^2) verison/ no structures allowed
bool isUnique(string s)
{
    for (int i=0; i<s.length(); i++)
    {
        for (int j=i+1; j<s.length(); j++)
        {
            cout << "s[i]: " << s[i] << " s[j]" << s[j] << "\n";
            if (s[i]==s[j])
            {
                return false;
            }
        }
    }
    return true;
}

// Faster version - assign character to possible index 
// for character = convert character bit to int = index
// ASCII is 8 bit, 256 possible characters
bool isUnique2(string s)
{
    unsigned char inds[256] = {0};
    unsigned char index_equiv;
    for (int i=0; i<s.length(); i++)
    {
        index_equiv = (unsigned int)s[i];
        if (inds[index_equiv] != 0)
        {
            return false;
        } else {
            inds[index_equiv] = 1;
        }
    }
    return true;
}


/*********************************
 * Main Testing
 **********************************/

int main(){

    // Timing
    struct timespec tv_start, tv_end;
    long tv_diff_usec;

    // Testing vals
    int test_num;
    bool result;
    bool answer = true;
    
    /*
     * Slow version testing
     */ 

    // Test 1
    test_num = 1;
    cout << "Test: " <<  test_num << "\n";
    string test_str1 = "abcdef";
    answer = true;
    
    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    result = isUnique(test_str1);
    // end fuction call
    clock_gettime(CLOCK_MONOTONIC,&tv_end);
    tv_diff_usec = 1000000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_nsec - tv_start.tv_nsec);
    cout << "Time test " << test_num << " [ns]: " <<  tv_diff_usec << '\n';

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";

    // Test 2
    test_num = 2;
    cout << "Test: " <<  test_num << "\n";
    string test_str2 = "abcdea";
    answer = false;
    result = isUnique(test_str2);

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";

    /*
     * Fast version testing:
     */ 

    // Test 3
    test_num = 3;
    cout << "Test: " <<  test_num << "\n";
    string test_str3 = "abcdef";
    answer = true;
    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    result = isUnique2(test_str1);
    // end fuction call
    clock_gettime(CLOCK_MONOTONIC,&tv_end);
    tv_diff_usec = 1000000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_nsec - tv_start.tv_nsec);
    cout << "Time test " << test_num << " [ns]: " <<  tv_diff_usec << '\n';

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";


    // Test 4
    test_num = 4;
    cout << "Test: " <<  test_num << "\n";
    string test_str4 = "abcdea";
    answer = false;
    result = isUnique2(test_str2);

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";


    return 0;
}






