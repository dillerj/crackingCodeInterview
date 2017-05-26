/*  Jed Diller
 * 	Cracking the Code Interview Solutions
 * 	Ch1.4 isPalindrome
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
 * Function to determine if stirng is a permutation of a palindrome
 */

/**********************************
 * Define Functions
 **********************************/
 
bool isPalidrome(string s)
{
    // Number of characters must be even for even length strings
    // All but one char must have even number for odd length string
    unsigned char hash[256] = {0};
    
    for (int i=0; i<s.length(); i++)
    {
        hash[(unsigned char)s[i]] += 1;
    } 

    // Check for even and uneven
    unsigned char num_odd = 0;
    for (int i=0; i<sizeof(hash); i++)
    {
        if (hash[i]%2 != 0)
        {
            num_odd++;
        } 
    }

    // If there is more than one char with and off number of character return false
    if (num_odd <= 1)
    {
        return true;
    } else {
        return false;
    }
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
    bool answer;
    
    /*
     * Slow version testing
     */ 

    // Test 1
    test_num = 1;
    cout << "Test: " <<  test_num << "\n";
    string test1 = "abba";
    answer = true; 
    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    result = isPalidrome(test1);
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
    string test2 = "abbad";
    answer = true; 
    // Function call
    result = isPalidrome(test2);

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";

    // Test 3
    test_num = 3;
    cout << "Test: " <<  test_num << "\n";
    string test3 = "abbadc";
    answer = false; 
    // Function call
    result = isPalidrome(test3);

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";




    return 0;
}






