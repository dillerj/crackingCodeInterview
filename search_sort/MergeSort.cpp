/*******************************************************************
 * Author: Jed Diller
 * MergeSort.cpp
 *******************************************************************/

#include "MergeSort.h"

/*******************************************************************
 * Functions
 *******************************************************************/
void mergeSort(int array[], int helper[], int low, int high)
{
    // until low == high call merge sort for left, then right, then merge
    if (low < high)
    {
        int middle = (high+low) / 2; 
        cout << "low, middle, high:" << low << "," << middle << "," << high << "\n";
        mergeSort(array, helper, low, middle);      // left side
        mergeSort(array, helper, middle + 1, high); // right side
        merge(array, helper, low, middle, high);    // do merge
    }
    return;
}

void merge(int array[], int helper[], int low, int middle, int high)
{
    /*
     * Copy both halves in to helper
     */ 
    for (int i = low; i <= high; i++)
    {
        helper[i] = array[i];
        cout << "helper[" << i << "]: " << helper[i] << "\n";
    }

    int helperLeft = low;
    int helperRight = middle + 1;
    int current = low;

    /* 
     * Iterate through helper, compare left and right halves, copy back 
     * the smaller of the two into the original array  
     */ 
    while ((helperLeft <= middle) && (helperRight <= high))
    {
        if (helper[helperLeft] <= helper[helperRight])
        {
            array[current] = helper[helperLeft];
            helperLeft++;
        } else {
            array[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }

    /* 
     * Copy the rest of left side into the orig array
     */
    int remaining = middle - helperLeft;
    for (int i = 0; i <= remaining; i++)
    {
        array[current + i] = helper[helperLeft + i];
    }
    return;
}

/*******************************************************************
 * Class Definitions 
 *******************************************************************/

/******************************************************
 * Main Testing 
 ******************************************************/
int main()
{
    cout << "Testing Merge Sort:\n";
    
    int orig[10] = {0,2,3,6,5,7,8,4,9,1};
    int helper[10] = {0};
    int arr_len = sizeof(orig)/sizeof(orig[0]);
    cout << "array size: " << arr_len << "\n";

    cout << "orig   : [";
    for (int i=0; i<arr_len-1; i++)
        cout << orig[i] << ", ";
    cout << orig[arr_len-1] << "]\n";

    mergeSort(orig, helper, 0, arr_len-1);

    cout << "sorted : [";
    for (int i=0; i<arr_len-1; i++)
        cout << orig[i] << ", ";
    cout << orig[arr_len-1] << "]\n";


    cout << "\nTest 2, sort only first half?\n";

    int orig2[10] = {0,2,3,6,5,7,8,4,9,1};    
    int helper2[10] = {0};    

    cout << "orig   : [";
    for (int i=0; i<arr_len-1; i++)
        cout << orig2[i] << ", ";
    cout << orig2[arr_len-1] << "]\n";

    mergeSort(orig2, helper2, 0, (arr_len-1)/2);

    cout << "sorted : [";
    for (int i=0; i<arr_len-1; i++)
        cout << orig2[i] << ", ";
    cout << orig2[arr_len-1] << "]\n";


    return 0;
}
