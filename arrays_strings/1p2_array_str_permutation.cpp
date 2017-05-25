/*  Jed Diller
 * 	Cracking the Code Interview Solutions
 * 	Ch1.2 isPermutation()
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
 * Give two string decide if one is permutation of the other
 * Permutation if same number of letters in each
 */

/**********************************
 * Define Functions
 **********************************/
 
bool isPermutation(string s1, string s2)
{
    // Assume 256 characters again
    // Do for both strings, compare number thereof
    unsigned int inds1[256] = {0};
    unsigned int inds2[256] = {0};

    if (s1.length() != s2.length())
    {
        return false;
    } else {
        for (int i=0; i<s1.length(); i++)
        {
            // saw that letter, increment associated index
            inds1[(unsigned int)s1[i]] += 1;
            inds2[(unsigned int)s2[i]] += 1;
        }
    }
    // Check all slots
    for (int i=0; i<256; i++)
    {
        // saw that number
        if (inds1[i] != inds2[i])
        {
            return false;
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
    string test_str2 = "fedcba";
    answer = true;
    
    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    result = isPermutation(test_str1, test_str2);
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
    string test_str3 = "fedcaa";
    answer = false;
    
    result = isPermutation(test_str1, test_str3);
    
    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";

    // Test 3
    test_num = 3;
    cout << "Test: " <<  test_num << "\n";
    string test_str4 = "aaaaaaaa";
    string test_str5 = "aaaaaaaa";
    answer = true;
    
    result = isPermutation(test_str4, test_str5);
    
    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";
    
    return 0;
}






