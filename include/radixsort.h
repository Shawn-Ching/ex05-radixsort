//
// Created by Shawn Ching on 9/26/18.
//

#ifndef EX05_RADIXSORT_RADIXSORT_H
#define EX05_RADIXSORT_RADIXSORT_H

#include <cstdint>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                /*template <class T>
                void print(T *array, size_t size)   //debugging tool
                {
                    for (size_t i = 0; i < size; i++)
                    {
                        cout << array[i] << " | ";
                    }
                    cout << endl;
                }*/

                template<class T>
                void myRadix(T *array, size_t size)
                {
                    if(array == nullptr)
                    {
                        return ;
                    }
                    T radix[10][size];
                    size_t maxVal = 0;  ///Max Value
                    size_t digitPos =1;
                    size_t pass = 1;

                    for(size_t i = 0; i < size; i++)    ///Find Max Value in array
                    {
                        if(array[i] > maxVal)
                        {
                            maxVal = array[i];
                        }
                    }

                    while(maxVal / digitPos > 0)
                    {
                        T bucketSize[10]; /// Tracks how elements in each bucket
                        std::fill(bucketSize, bucketSize+10, 0);
                        for(size_t i = 0; i < size; i++)
                        {
                            size_t radixInd = (array[i] / digitPos) % 10;  ///Find n-th digit and set Bucket Index
                            radix [radixInd][bucketSize[radixInd]++] = array[i];
                        }
                        for (size_t i = 0, arrInd = 0; i < 10; i++) ///Rewrite to original array
                        {
                            for(size_t j = 0; j < bucketSize[i]; j++)
                            {
                                array[arrInd] = radix[i][j];
                                arrInd ++;
                            }
                        }
                        //cout << "pass #" << pass++ << ": "; //debugging tool
                        //print(array,size);  //debugging tool

                        digitPos *= 10;
                    }
                }




                template<class T>
                void radixsort(T array[], size_t size)
                {
                    // put your code here
                    myRadix(array,size);

                }


            }}}}

#endif //EX05_RADIXSORT_RADIXSORT_H

