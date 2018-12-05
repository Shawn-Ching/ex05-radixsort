//
// Created by Shawn Ching on 9/26/18.
//

#include <iostream>
#include "radixsort.h"

using std::cout;
using std::endl;
using edu::vcccd::vc::csv15::radixsort;



int main(int argc, char *argv[])
{
//  int array[] = {1, 4, 10, 11, 2, 7, 23, 52};
    int array[] = {170, 45, 75, 90, 2, 24, 802, 66};

    radixsort(array,8);
};