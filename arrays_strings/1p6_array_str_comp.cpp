/*  Jed Diller
 * 	Cracking the Code Interview Solutions
 * 	Ch1.5 compressString
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
 * Function to compress strings
 * Return a string w/ letters and number of consecutive
 * Only upper and lower case A-Z
 * If length is not smaller than original, return original
 * Examples: 
 *      aaabbcc -> a3b2c2
 */

/**********************************
 * Define Functions
 **********************************/
 
string compressString(string orig)
{
    string comp = "";
    int start=0;
    int end=0;
    int num_char=0;

    cout << orig << "\n";
    cout << "0123456789012345678901234567890\n";
    while (end < orig.length())
    {
        cout << "start->orig["<<start<<"]: " << orig[start] << "\n";
        cout << "end  ->orig["<<end<<"]: " << orig[end] << "\n";
        cout << "num_char: " << num_char << "\n";
        if (orig[start] == orig[end])
        {

            // Special test for end
            if (end == orig.length()-1)
            {
                num_char++;
                comp += orig[start]; // character 'a'
                comp += std::to_string(num_char);
            }

            // Increment
            end++;
            num_char++;

        } else {
            // Not the same so start adding to new string
            comp += orig[start]; // character 'a'
            comp += std::to_string(num_char);
            cout << "comp: " << comp << "\n";
            // On to next character
            start = end;
            num_char = 0;
        }
    }
    cout << "Orig: " << orig << "\n";
    cout << "Comp: " << comp << "\n";
    if (comp.length() >= orig.length() )
        return orig;
    else
        return comp;
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
    string result;
    string answer;
    
    /*
     * Slow version testing
     */ 

    // Test 1
    test_num = 1;
    cout << "Test: " <<  test_num << "\n";
    string test1 = "aaaa";
    answer.assign("a4"); 

    clock_gettime(CLOCK_MONOTONIC,&tv_start);
    // Function call
    result.assign( compressString(test1) );
    // end fuction call
    clock_gettime(CLOCK_MONOTONIC,&tv_end);
    tv_diff_usec = 1000000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_nsec - tv_start.tv_nsec);
    cout << "Time test " << test_num << " [ns]: " <<  tv_diff_usec << '\n';

    cout << "Result: " << result << "\n";
    cout << "Answer: " << answer << "\n";

    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";
    

    // Test 2
    test_num = 2;
    cout << "Test: " <<  test_num << "\n";
    string test2 = "aaaabbe";
    answer.assign("a4b2e1"); 
    
    result.assign( compressString(test2) );
    
    cout << "Result: " << result << "\n";
    cout << "Answer: " << answer << "\n";
    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";


    // Test 3
    test_num = 3;
    cout << "Test: " <<  test_num << "\n";
    string test3 = "aaaabbeeeAAAAAABBBBCCCCDd";
    answer.assign("a4b2e3A6B4C4D1d1"); 
    
    result.assign( compressString(test3) );
    
    cout << "Result: " << result << "\n";
    cout << "Answer: " << answer << "\n";
    if (result != answer)
        cout << "Test "<< test_num << " FAILED\n";
    else
        cout << "Test "<< test_num << " PASS\n";

    return 0;
}






