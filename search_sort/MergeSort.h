/*******************************************************************
 *  Jed Diller
 *  MergeSort.h
 *******************************************************************/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <string>
using namespace std;
#include <iomanip>

/*******************************************************************
 * Structures
 *******************************************************************/


/*******************************************************************
 * Function Prototypes
 *******************************************************************/
void mergeSort(int array[], int helper[], int low, int high);
void merge(int array[], int helper[], int low, int middle, int high);

/*******************************************************************
 * Class declaration
 *******************************************************************/

#endif // MERGESORT_H