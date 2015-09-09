#include "stdafx.h"
#include "Hash.h"
#include <iostream>

Hash::Hash(){
	tableSize = 32;
	useProbing = true;
	for (int i = 0; i < tableSize; ++i){
		hashTableKeys[i] = -1;
		hashTableValues[i] = -1;
	}
}

Hash::Hash(int size, bool probing){
	tableSize = size;
	useProbing = probing;
	for (int i = 0; i < tableSize; ++i){
		hashTableKeys[i] = -1;
		hashTableValues[i] = -1;
	}
}

int Hash::HashFunc(int key){
	return key % 5;
}

void Hash::Add(int key, int value){
	int hashIndex = HashFunc(key);

	if (hashTableKeys[hashIndex] >= 0){
		if (useProbing){
			int newIndex = Probe(hashIndex);
			if (newIndex != -1){
				hashTableKeys[newIndex] = key;
				hashTableValues[newIndex] = value;
			}
		}
	}
	else{
		hashTableKeys[hashIndex] = key;
		hashTableValues[hashIndex] = value;
	}
}

int Hash::Probe(int index){
	for (int i = index + 1; i < tableSize; i++){
		if (hashTableKeys[i] == -1){
			return i;
		}
	}
	for (int i = 0; i < index; i++){
		if (hashTableKeys[i] == -1){
			return i;
		}
	}
	return -1;
}

void Hash::Remove(int key){
	int hashIndex = HashFunc(key);

	if (hashTableKeys[hashIndex] == key){
		hashTableValues[hashIndex] = -1;
	}
	else if (hashTableKeys[hashIndex] == -1){
		return;
	}
	else{
		int i = hashIndex;
		while (hashTableKeys[i] != key)
		{
			if (hashTableKeys[i] < 0){
				break;
			}
			if (i == tableSize - 1){
				i = -1;
			}
			i++;
		}
		hashTableKeys[i] = -1;
		hashTableValues[i] = -1;
	}
}

int Hash::Find(int key){
	int hashIndex = HashFunc(key);

	if (hashTableKeys[hashIndex] == key){
		return hashTableValues[hashIndex];
	}
	else if (hashTableKeys[hashIndex] == -1){
		return -1;
	}
	else{
		for (int i = hashIndex + 1; i < tableSize; i++){
			if (hashTableKeys[i] < 0){
				return -1;
			}
			else if (hashTableKeys[i] == key){
				return hashTableValues[i];
			}
		}
		for (int i = 0; i < hashIndex; i++){
			if (hashTableKeys[i] < 0){
				return -1;
			}
			else if (hashTableKeys[i] == key){
				return hashTableValues[i];
			}
		}
	}
	return -1;
}