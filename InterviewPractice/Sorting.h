#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

namespace Sorting{

	inline int Partition(int* list, int start, int finish){

		int pIndex = start;
		int pivot = list[finish];

		for (int i = start; i < finish; i++){
			if (list[i] <= pivot){
				if (pIndex != i){
					int temp = list[i];
					list[i] = list[pIndex];
					list[pIndex] = temp;
				}
				pIndex++;
			}
		}

		if (pIndex != finish){
			int temp = list[finish];
			list[finish] = list[pIndex];
			list[pIndex] = temp;
		}
		
		return pIndex;
	}

	inline int* MyQuickSort(int* list, int start, int size){

		if (start < size){
			int rightHalfIndex = Partition(list, start, size);
			MyQuickSort(list, start, rightHalfIndex - 1);
			MyQuickSort(list, rightHalfIndex + 1, size);
		}

		return list;
	}
}