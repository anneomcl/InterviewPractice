#include "stdafx.h"

class Hash{

public:
	int tableSize;
	bool useProbing;
	int hashTableKeys[32]; //hash index to key
	int hashTableValues[32]; //hash index to value

	Hash();
	Hash(int size, bool probing);

	//adds key/value pair to hash table
	void Add(int key, int value);

	//removes key/value pair from hashtable
	void Remove(int key);

	//returns the value associated with the key
	int Find(int key);

	void TestHash();

private:
	//hash function for key/value pairs
	int HashFunc(int key);

	//returns index where key can be hashed to if there is a collision
	int Probe(int index);

};