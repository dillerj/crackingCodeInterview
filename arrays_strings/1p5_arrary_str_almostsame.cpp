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
 * Function to determine if two strings would be the same if you can
 * use 1 delete, add, or swap
 * Return true of false
 * Examples: 
 *      pale pal    true
 *      pale bale   true
 *      bae pale    false
 */

/**********************************
 * Define Functions
 **********************************/
 
bool nearSame(string s1, string s2)
{
    int len_s1 = s1.length();
    int len_s2 = s2.length();

    int num_skips = 0;
    // if same lenght make sure only 1 difference
    if  (len_s1 == len_s2)
    {
        for (int i=0; i<len_s1; i++)
            {
                if (s1[i] != s2[i])
                    num_skips++;
                
                if (num_skips>1)
                    return false;
            }
    } else {
        if (len_s1 > len_s2)
        {
            // iterate along smallest
            // if descrpency found, skip over it
            for (int i=0; i<len_s2; i++)
            {
                if (s1[i+num_skips] != s2[i])
                    num_skips++;
                
                if (num_skips>1)
                    return false;
            }
        } else {
            // len_s1 < len_s2
            // iterate along smallest
            // if descrpency found, skip over it
            for (int i=0; i<len_s1; i++)
            {
                if (s1[i] != s2[i+num_skips])
                    num_skips++;

                if (num_skips>1)
                    return false;
            }

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
    bool answer;
    
    /*
     * Slow version testing
     */ 

    // Test 1
    test_num = 1;
    cout << "Test: " <<  test_num << "\n";
    string test11 = "pale";
    string test12 = "ale";
    answer = true; 
    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    result = nearSame(test11, test12);
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
    string test21 = "pale";
    string test22 = "bale";
    answer = true; 
    // Function call
    result = nearSame(test21, test22);

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";

    // Test 2
    test_num = 3;
    cout << "Test: " <<  test_num << "\n";
    string test31 = "pale";
    string test32 = "bae";
    answer = false; 
    // Function call
    result = nearSame(test31, test32);

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";



    return 0;
}






