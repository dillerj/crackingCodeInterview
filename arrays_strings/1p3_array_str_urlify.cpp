/*  Jed Diller
 * 	Cracking the Code Interview Solutions
 * 	Ch1.3 URLify()
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
 * Function to remove spaces and replace with %20
 * You are given true length of string
 * Assume the given string has enough space to hold all the extra characters
 *      Editing string in place
 * Example:
 *      "Mr. John Doe", 12
 *      "Mr.%20John%20Doe"
 */

/**********************************
 * Define Functions
 **********************************/
 
void URLify(char s[], int length)
{
    // Count number of spaces in original string
    int num_spaces=0;
    for (int i=0; i<length; i++)
    {
        if (s[i] == ' ')
        {
            num_spaces++;
        }
    }

    // Starting at end of the array
    // Move character to the end and fill in as you go
    int end_idx = (length-num_spaces) + (3 * num_spaces) - 1; // add 3 chars per space found

    for (int i=length-1; i>=0; i--)
    {
        if (s[i] != ' ')
        {
            s[end_idx] = s[i];
            end_idx--;
        } else {
            s[end_idx] = '0';
            s[end_idx-1] = '2';
            s[end_idx-2] = '%';
            end_idx-=3;
        }
    }
    return;
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
    
    /*
     * Slow version testing
     */ 

    // Test 1
    test_num = 1;
    cout << "Test: " <<  test_num << "\n";
    char test_str[50] = "ab cd ef";
    cout << "before: " << test_str << "\n";

    char answer[50]   = "ab%20cd%20ef";
    
    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    URLify(test_str, 8);
    // end fuction call
    clock_gettime(CLOCK_MONOTONIC,&tv_end);
    tv_diff_usec = 1000000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_nsec - tv_start.tv_nsec);
    cout << "Time test " << test_num << " [ns]: " <<  tv_diff_usec << '\n';

    cout << "after: " << test_str << "\n";

    return 0;
}






