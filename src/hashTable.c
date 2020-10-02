//#include"hashTable.h"

//
//
//
///**
// * Create default hash word set.
// *
// * @param size number of elements in
// *             the hash table.
// */
//public HashWordSet(int size) {
//	words = null;
//	nrElements = 0;
//	resize(nextPrime(size));
//}
//
//static int getNextPrime(int n) {
//	long tmp;
//
//	/*  Wilson's theorem for determine the next prime.*/
//	/*  Time complexity O(n).   */
//	do {
//		n++;
//		tmp = 1;
//		for (int i = 1; i < n; i++) {
//			/*	(tmp * i) mod p === r*/
//			tmp = (tmp * i) % n;
//		}
//	} while ((tmp + 1) % n != 0);
//
//	return n;
//}
//
//int hashTableResize(int size) {
//
//	if (words == NULL) {
//		words = new Word[size];
//		for (int i = 0; i < size; i++)
//			words[i] = null;
//	} else {
//		if (size < words.length)
//			return 0; //throw new IllegalArgumentException("Size must be greater than previous size");
//		hashTableReHash(size);
//	}
//}
//void hashTableReHash(int size) {
//
//	/*  Copy current hash.  */
//	Word[] oldArray = new Word[getTableSize()];
//	for (int i = 0; i < words.length; i++)
//		oldArray[i] = words[i];
//
//	/*  Clear.  */
//	words = new Word[size];
//	for (int i = 0; i < size; i++)
//		words[i] = null;
//
//	/*  Rehashing phase. */
//	nrElements = 0;
//	for (Word k : oldArray) {
//		if (k != null)
//			add(k);
//	}
//}
////
////void hashTableAdd(Word word) {
////
////	/*  Validate arguments. */
////	if (word == null)
////		throw new NullPointerException("word must be a non-null reference object");
////
////	/*  Resize if condition is meet. */
////	if (size() >= getTableSize() - 2)
////		resize(nextPrime(getTableSize() * 2));
////
////	/*  Compute next index. */
////	int hashIndex = findPosition(word);
////
////	/*  Only update if object does not exists.  */
////	if (words[hashIndex] == null) {
////		nrElements++;
////
////		/*  Create node object and add. */
////		words[hashIndex] = word;
////	}
////}
////
/////**
//// * @param word
//// * @return
//// */
////@Override
////		static int contains(int hash) {
////	return words[findPosition(hash)] != null;
////}
////
/////**
//// * Compute the position of the word
//// * object using quadratic probing.
//// *
//// * @param word valid word object.
//// * @return index position in the range of [0, tableSize - 1]
//// * @throws NullPointerException if word object is null.
//// */
////static int findPosition(int hash) {
////
////	if (word == null)
////		throw new NullPointerException("word must be a non-null reference object");
////
////	/*  */
////	int offset = 1;
////	int currentPos = hash(word);
////
////	assert currentPos < getTableSize() && currentPos >= 0;
////
////	/*  Iterate till object has been found. */
////	while (words[currentPos] != null) {
////		if (words[currentPos].compareTo(word) == 0)
////			break;
////		currentPos += offset;
////		offset += 2;
////		currentPos %= getTableSize();
////	}
////
////	return currentPos;
////}
////
/////**
//// * Compute the hash.
//// *
//// * @param word valid word object.
//// * @return unsigned int hash digit in range from [0, table size]
//// */
////private int hash(Word word) {
////	int uhash = Math.abs(word.hashCode());
////	return uhash % getTableSize();
////}
////
/////**
//// * Get current size of number
//// * of elements.
//// *
//// * @return non-negative number.
//// */
////@Override
////		public int size() {
////	return nrElements;
////}
////
////private int getTableSize() {
////	return words.length;
////}