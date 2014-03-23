#pragma once
#include <iostream>
#include <time.h>

template <typename T>
void insertionSort(T *input_array, int array_size);

template <typename T>
void mergeSort(T *input_array, int array_size);

template <typename T>
void bubbleSort(T *input_array, int array_size);

template <class HeapType> 
class AHeap
{
public:
	AHeap(HeapType *_array, int _array_size);
	~AHeap();
	HeapType *heapSort();
	inline HeapType getMax() {return heap_pt[0];}	//after build max heap or sorted
	HeapType extractMax();
	bool increaseKey(int i, HeapType key_val);
	bool insertKey(HeapType key_val);
private:
	inline int parent(int i) {return floor(float(i)/2);}
	inline int leftChild(int i) {return (2 * i);}
	inline int rightChild(int i) {return (2 * i + 1);}
	void maxHeapify(int i);
	void buildMaxHeap();

	int heap_size;
	HeapType *heap_pt;
};

namespace ARandom
{
	const long A = 48271;
	const long M = 2147483647;
	const long Q = M / A;
	const long R = M % A;
}

static unsigned long Aseed = 1;

double Arandom(void);
void Arandom_init(unsigned long _seed);

//quick sort
int myPartition(int arr[], int arr_size);
void quickSort(int arr[], int arr_size);