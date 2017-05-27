/*  Jed Diller
 * 	Cracking the Code Interview Solutions
 * 	Ch1.7 rotateMatrix
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
 * Rotate a matrix 90 degrees
 * Can it be sone inplace?
 */

/**********************************
 * Define Functions
 **********************************/
 
bool rotateMatrix(int **m, int rows, int cols)
{
    // Check to make sure it's square matrix
    if (rows!=cols)
        return false;

    // Rotate clockwise, temp for start variable, work backwards
    // Determine how many levels there are in the matrix
    // 4x4 = 2 levels, 3x3 = 2 levels, 2x2 = 1 level
    
    // Per level, decrease length by 2
    for (int level=0; level < rows/2; level++)
    {
        cout << "Level:" << level << "\n";
        // Start on outside most level
        int first = level; // 
        int last = cols - 1 - level; // 
        for (int i=first; i<last; i++)
        {
            int offset = i - first;
            // save top element
            int top = m[first][i]; 
            // left element -> top
            m[first][i] = m[last-offset][first];
            // bottom -> left
            m[last-offset][first] = m[last][last-offset];
            // right -> bottom 
            m[last][last-offset] = m[i][last];
            // top -> right
            m[i][last] = top;
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
    
    // Create Matrix 
    int **m;
    int rows = 3;
    int cols = 3;
    /* allocate the array */
    m = new int*[rows];
    for(int i = 0; i < rows; i++)
        m[i] = new int[cols];

    // Testing vals
    int test_num;

    // Test 1
    test_num = 1;
    cout << "Test: " <<  test_num << "\n";

    // Set test values 
    int k=0;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            m[i][j] = k;
            k++;
        }
    }

    // Matrix before
    cout << "Before: \n";
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << "m["<<i<<"]["<<j<<"]: "<< m[i][j] << "\n";
        }
    }

    // Function call
    bool result = rotateMatrix(m,rows,cols);
    
    // Matrix after
    cout << "After: \n";
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << "m["<<i<<"]["<<j<<"]: "<< m[i][j] << "\n";
        }
    }


    // Test 2
    test_num = 2;
    cout << "\nTest: " <<  test_num << "\n";


    // Create Matrix 
    int **m2;
    rows = 4;
    cols = 4;
    /* allocate the array */
    m2 = new int*[rows];
    for(int i = 0; i < rows; i++)
        m2[i] = new int[cols];

    // Set test values 
    k=0;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            m2[i][j] = k;
            k++;
        }
    }
    
    // Matrix before
    cout << "Before: \n";
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << "m2["<<i<<"]["<<j<<"]: "<< m2[i][j] << "\n";
        }
    }

    // Function call
    result = rotateMatrix(m,rows,cols);
    
    // Matrix after
    cout << "After: \n";
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << "m2["<<i<<"]["<<j<<"]: "<< m2[i][j] << "\n";
        }
    }


    // Unallocate array
    for(int i = 0; i < rows; i++)
        delete [] m[i];
    delete [] m;    
    
    return 0;
}






