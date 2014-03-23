#include "SortMethod.h"

template <typename T>
void insertionSort(T *input_array, int array_size)
{
	int n = array_size;
	for (int j = 1; j < n; j++)
	{
		T key = input_array[j];
		int i = j - 1;
		while (i >= 0 && input_array[i] > key)
		{
			input_array[i+1] = input_array[i];
			i = i - 1;
		}
		input_array[i+1] = key;
	}
}

template <typename T>
void mergeSort(T *input_array, int array_size)
{
	int n = array_size;
	int q(0);
	if (n > 1)
	{
		q = floor(n/2.);
		mergeSort(input_array, q);
		T *pt_array = input_array + q;
		mergeSort(pt_array, n-q);

		//merge two sorted array
		T *L = new T[q];
		T *R = new T[n-q];
		for (int i = 0; i < q; i++)
		{
			L[i] = input_array[i];
		}
		for (int i = 0; i < (n-q); i++)
		{
			R[i] = pt_array[i];
		}
		for (int k = 0, i = 0, j = 0; k < n; k++)
		{
			if (i < q && j < (n-q))
			{
				if (L[i] <= R[j])
				{
					input_array[k] = L[i];
					i++;
				}
				else
				{
					input_array[k] = R[j];
					j++;
				}
			}
			else if (i == q)
			{
				input_array[k] = R[j];
				j++;
			}
			else if (j == (n-q))
			{
				input_array[k] = L[i];
				i++;
			}
		}
	}
}

template <typename T>
void bubbleSort(T *input_array, int array_size)
{
	int n = array_size;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n-i-1); j++)
		{
			if (input_array[j] > input_array[j+1])
			{
				T temp_element = input_array[j];
				input_array[j] = input_array[j+1];
				input_array[j+1] = temp_element;
			}
		}
	}
}

//class AHeap definition
template <class HeapType>
AHeap<HeapType>::AHeap(HeapType *_array, int _array_size)
{
	heap_size = _array_size;
	heap_pt = new HeapType[heap_size];
	for (int i = 0; i < heap_size; i++)
	{
		heap_pt[i] = _array[i];
	}
}

template <class HeapType>
AHeap<HeapType>::~AHeap()
{
	delete [] heap_pt;
}

template <class HeapType>
HeapType * AHeap<HeapType>::heapSort()
{
	int heap_size_tmp = heap_size;
	buildMaxHeap();
	for (int i = heap_size; i > 1; i--)
	{
		HeapType tmp = heap_pt[i-1];
		heap_pt[i-1] = heap_pt[0];
		heap_pt[0] = tmp;
		heap_size--;
		maxHeapify(1);
	}
	heap_size = heap_size_tmp;

	HeapType *out_heap_pt = new HeapType[heap_size];
	for (int i = 0; i < heap_size; i++)
	{
		out_heap_pt[i] = heap_pt[i];
	}

	return out_heap_pt;
}

template <class HeapType>
HeapType AHeap<HeapType>::extractMax()
{
/*
	if (heap_size < 1)
	{
		cout << "Error!!The Heap is empty!!!" << endl;
		return HeapType;
	}*/

	buildMaxHeap();
	HeapType maxElement = heap_pt[0];
	heap_pt[0] = heap_pt[heap_size-1];
	heap_size--;
	maxHeapify(1);

	return maxElement;
}

template <class HeapType>
bool AHeap<HeapType>::increaseKey( int i, HeapType key_val )	//parameter i must be equal or larger than 1
{
	if (key_val < heap_pt[i-1])
	{
		cout << "new key value is smaller than current key!" << endl;
		return false;
	}
	else
	{
		heap_pt[i-1] = key_val;
		while(i > 1 && heap_pt[parent(i)-1] < heap_pt[i-1])
		{
			HeapType tmp = heap_pt[i-1];
			heap_pt[i-1] = heap_pt[parent(i)-1];
			heap_pt[parent(i)-1] = tmp;
			i = parent(i);
		}
		return true;
	}
}

template <class HeapType>
bool AHeap<HeapType>::insertKey( HeapType key_val )
{
	heap_size++;
	heap_pt[heap_size-1] = key_val;
	int i = heap_size;
	while(i > 1 && heap_pt[parent(i)-1] < heap_pt[i-1])
	{
		HeapType tmp = heap_pt[i-1];
		heap_pt[i-1] = heap_pt[parent(i)-1];
		heap_pt[parent(i)-1] = tmp;
		i = parent(i);
	}

	return true;
}

template <class HeapType>
void AHeap<HeapType>::maxHeapify( int i )	//parameter i must be equal or larger than 1
{
	int largest;
	int left_num = leftChild(i);
	int right_num = rightChild(i);

	if (left_num <= heap_size && heap_pt[left_num-1] > heap_pt[i-1])
	{
		largest = left_num;
	}
	else
	{
		largest = i;
	}

	if (right_num <= heap_size && heap_pt[right_num-1] > heap_pt[largest-1])
	{
		largest = right_num;
	}

	if (largest != i)
	{
		HeapType tmp = heap_pt[largest-1];
		heap_pt[largest-1] = heap_pt[i-1];
		heap_pt[i-1] = tmp;
		maxHeapify(largest);
	}
}

template <class HeapType>
void AHeap<HeapType>::buildMaxHeap()
{
	for (int i = floor(float(heap_size) / 2); i > 0; i--)
	{
		maxHeapify(i);
	}
}

double Arandom(void)
{
	long seed_tmp;
	seed_tmp = ARandom::A * (Aseed % ARandom::Q) - ARandom::R * (Aseed / ARandom::Q);
	Aseed = seed_tmp >= 0 ? seed_tmp : seed_tmp+ARandom::M;

	return Aseed;
}

void Arandom_init(unsigned long _seed)
{
	Aseed = _seed;
}

int myPartition( int arr[], int arr_size )
{
	if (arr == NULL || arr_size <= 0)
	{
		throw new std::exception("Invalid input array!");
	}

	srand(unsigned(time(0)));
	int pivot = rand() % arr_size;
	int tmp = arr[pivot];
	arr[pivot] = arr[arr_size-1];
	arr[arr_size-1] = tmp;

	int j(-1);
	int &pivot_val = arr[arr_size-1];
	for (int i = 0; i < arr_size; ++i)
	{
		if (arr[i] < pivot_val)
		{
			++j;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	++j;
	tmp = pivot_val;
	pivot_val = arr[j];
	arr[j] = tmp;

	return j;
}

void quickSort(int arr[], int arr_size)
{
	if (arr == NULL || arr_size <= 0)
	{
		return;
	}

	int left_size = myPartition(arr, arr_size);
	int right_size = arr_size - left_size;
	if (left_size > 0)
	{
		quickSort(arr, left_size);
	}
	if (right_size > 0)
	{
		quickSort(arr, right_size);
	}
}