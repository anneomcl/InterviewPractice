#include "stdafx.h"
#include "Hash.h"
#include "MySTDLib.h"
#include "Sorting.h"
#include <stdlib.h>
#include <iostream>

inline void TestATOI(){

	char * numberString = "1234567";
	int numberInt = atoi(numberString);

	std::cout << "Starting atoi tests..." << std::endl;

	//Test stdlib function.
	if (numberInt == 1234567){
		std::cout << "Test 1 passed." << std::endl;
	}

	char * numberString2 = "      1234567 is my phone number.()@#$&*!!";
	int numberInt2 = atoi(numberString2);

	//Test stdlib function w/ complicated string.
	if (numberInt2 == 1234567){
		std::cout << "Test 2 passed." << std::endl;
	}

	char * numberString3 = "The &#*@) number 1234567 is my phone number.";
	int numberInt3 = atoi(numberString3);

	//Test stdlib function w/ invalid string
	if (numberInt3 == 0){
		std::cout << "Test 3 passed." << std::endl;
	}

	char * numberString4 = "The  number is my phone number.";
	int numberInt4 = atoi(numberString4);

	//Test stdlib function w/ another invalid string
	if (numberInt4 == 0){
		std::cout << "Test 4 passed." << std::endl;
	}
	
	numberInt = MySTDLib::MyAtoI(numberString);

	//Test my function.
	if (numberInt == 1234567){
		std::cout << "Test 5 passed." << std::endl;
	}

	numberInt2 = MySTDLib::MyAtoI(numberString2);

	//Test my function on a complicated string.
	if (numberInt2 == 1234567){
		std::cout << "Test 6 passed." << std::endl;
	}

	numberInt3 = MySTDLib::MyAtoI(numberString3);

	//Test my function w/ invalid string
	if (numberInt3 == 0){
		std::cout << "Test 7 passed." << std::endl;
	}
}

inline void TestHash(){

	std::cout << "Starting hash tests..." << std::endl;
	Hash tbl = Hash(5, true);

	//Test 1: Add key/value pair.
	tbl.Add(1, 2);
	if (tbl.hashTableKeys[1] == 1 && tbl.hashTableValues[1] == 2){
		std::cout << "Test 1 passed." << std::endl;
	}

	//Test 2: Add key/value pair and handle collision.
	tbl.Add(6, 7);
	if (tbl.hashTableKeys[2] == 6 && tbl.hashTableValues[2] == 7){
		std::cout << "Test 2 passed." << std::endl;
	}

	//Test 2a
	tbl.Add(4, 5);
	if (tbl.hashTableKeys[4] == 4 && tbl.hashTableValues[4] == 5){
		std::cout << "Test 2a passed." << std::endl;
	}

	//Test 2b
	tbl.Add(9, 10);
	if (tbl.hashTableKeys[0] == 9 && tbl.hashTableValues[0] == 10){
		std::cout << "Test 2b passed." << std::endl;
	}

	//Test 3: Find key/value pair (no probing).
	int entry1 = tbl.Find(1);
	if (entry1 == 2){
		std::cout << "Test 3 passed." << std::endl;
	}

	//Test 4: Find key/value pair (probing required).
	int entry2 = tbl.Find(6);
	if (entry2 == 7){
		std::cout << "Test 4 passed." << std::endl;
	}

	//Test 5: Remove key/value pair (no probing).
	tbl.Remove(1);
	if (tbl.Find(1) == -1){
		std::cout << "Test 5 passed." << std::endl;
	}

	//Test 6: Remove key/value pair (probing required).
	tbl.Remove(6);
	if (tbl.Find(6) == -1){
		std::cout << "Test 6 passed." << std::endl;
	}

	//Test 6a
	tbl.Remove(9);
	if (tbl.Find(9) == -1){
		std::cout << "Test 6a passed." << std::endl;
	}
}

inline void TestPalindrome(){

	std::cout << "Starting palindrome tests..." << std::endl;

	char* myString = "racecar";
	if (MySTDLib::IsPalindrome(myString)){
		std::cout << "Test 1 passed." << std::endl;
	}

	char* myString2 = "racefcar";
	if (!MySTDLib::IsPalindrome(myString2)){
		std::cout << "Test 2 passed." << std::endl;
	}
}

inline void TestQuickSort(){

	std::cout << "Starting quick sort tests..." << std::endl;
	int myList[] = { 3, 1, 5, 6, 2, 7, 9, 10, 4 };

	//Test 1: Quick sort simple list.
	int* sortedList = Sorting::MyQuickSort(myList, 0, 9);
	int sortedListTest[] = { 1, 2, 3, 4, 5, 6, 7, 9, 10 };

	for (int i = 0; i < 8; i++){
		std::cout << sortedList[i] << std::endl;
		if (sortedList[i] != sortedListTest[i]){
			return;
		}
	}
	
	std::cout << "Quick sort Test 1 passed." << std::endl;
}