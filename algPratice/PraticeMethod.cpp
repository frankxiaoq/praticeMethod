#include "PraticeMethod.h"

int countOne(int _byte)
{
	int num(0);
	while (_byte)
	{
		if (_byte % 2 == 1)
		{
			num++;
		}
		_byte /= 2;
	}
	return num;
}

int countOne2(int _byte)
{
	int num(0);
	while (_byte)
	{
		num += _byte & 0x01;
		_byte >>= 1;
	}
	return num;
}

int countOne3(int _byte)
{
	int num(0);
	while (_byte)
	{
		_byte &= (_byte - 1);
		num++;
	}
	return num;
}

int sum0InFactorial(int n)
{
	int res(0);
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (j % 5 == 0)
		{
			res++;
			j /= 5;
		}
	}
	return res;
}

int sum0InFactorial2(int n)
{
	int res(0);
	while (n)
	{
		res += n / 5;
		n /= 5;
	}
	return res;
}

int lowest1InFactBin(int n)
{
	int res(0);
	while (n)
	{
		n >>= 1;
		res += n;
	}
	return res;
}

int lowest1InFactBin2(int n)
{
	int res(0);
	int tmp_n = n;
	while (n)
	{
		res += n & 0x01;
		n >>= 1;
	}
	res = tmp_n - res;
	return res;
}

char findWaterKing(char *ID, int n)
{
	char candidate;
	int n_times(0);
	for (int i = 0; i < n; i++)
	{
		if (n_times == 0)
		{
			candidate = ID[i];
			n_times = 1;
		}
		else
		{
			if (candidate != ID[i])
			{
				n_times++;
			}
			else
			{
				n_times--;
			}
		}
	}

	return candidate;
}

void findWaterKing2(char *ID, int n)
{
	char candidate1, candidate2, candidate3;
	int n_times1(0), n_times2(0), n_times3(0);
	for (int i = 0; i < n; i++)
	{
		if (n_times1 == 0)
		{
			if (candidate2 == ID[i])
			{
				n_times2++;
			}
			else if (candidate3 == ID[i])
			{
				n_times3++;
			}
			else
			{
				candidate1 = ID[i];
				n_times1 = 1;
			}
		}
		else if (n_times2 == 0)
		{
			if (candidate1 == ID[i])
			{
				n_times1++;
			}
			else if (candidate3 == ID[i])
			{
				n_times3++;
			}
			else
			{
				candidate2 = ID[i];
				n_times2 = 1;
			}
		}
		else if (n_times3 == 0)
		{
			if (candidate1 == ID[i])
			{
				n_times1++;
			}
			else if (candidate2 == ID[i])
			{
				n_times2++;
			}
			else
			{
				candidate3 = ID[i];
				n_times3 = 1;
			}
		}
		else
		{
			if (candidate1 == ID[i])
			{
				n_times1++;
			}
			else if (candidate2 == ID[i])
			{
				n_times2++;
			}
			else if (candidate3 == ID[i])
			{
				n_times3++;
			}
			else
			{
				n_times1--;
				n_times2--;
				n_times3--;
			}
		}
	}

	//candidate1 candidate2 candidate3 is the result
/*
	cout << "the three water king are " << 
		candidate1 << " " << candidate2 << " " << candidate3 << endl;*/

}

long sum1s(long n)
{
	long count(0);
	long factor(1);
	long lower_num(0);
	long curr_num(0);
	long higher_num(0);

	while (n / factor != 0)
	{
		lower_num = n - (n / factor) * factor;
		curr_num = (n / factor) % 10;
		higher_num = n / (factor * 10);

		switch (curr_num)
		{
		case 0 :
			count += higher_num * factor;
			break;
		case 1:
			count += higher_num * factor + lower_num + 1;
			break;
		default:
			count += (higher_num + 1) * factor;
			break;
		}

		factor *= 10;
	}

	return count;
}

template <typename T>
void arrayPartition( vector<T> &input_array, vector<T> &output_array1, vector<T> &output_array2 )
{
	int num_array = input_array.size();
	srand(time(NULL));
	swap(input_array[0], input_array[rand() % num_array]);
	T p = input_array[0];
	for (int i = 1; i < num_array; i++)
	{
		if (input_array[i] > p)
		{
			output_array1.push_back(input_array[i]);
		}
		else
		{
			output_array2.push_back(input_array[i]);
		}
	}
	if (output_array1.size() < output_array2.size())
	{
		output_array1.push_back(p);
	}
	else
	{
		output_array2.push_back(p);
	}
}

template <typename T>
void findKBig( vector<T> &input_array, int K, vector<T> &output_array )
{
	if (K <= 0)
	{
		return;
	}
	
	if (input_array.size() < K)
	{
		output_array = input_array;
		return;
	}
	
	vector<T> arr1, arr2;
	arrayPartition(input_array, output_array, arr1);
	if (output_array.size() < K)
	{
		findKBig(arr1, K-output_array.size(), arr2);
		output_array.insert(output_array.end(), arr2.begin(), arr2.end());
	}
	else if (output_array.size() >= K)
	{
		findKBig(output_array, K, arr2);
		output_array.clear();
		output_array.insert(output_array.end(), arr2.begin(), arr2.end());
	}
}

int myGCD(int x, int y)
{
	if (x < y)
	{
		int tmp = y;
		y = x;
		x = tmp;
	}
	return (y == 0) ? x : myGCD(x-y, y);
}

int myGCD2(int x, int y)
{
	int res(0), k(1);
	if (x < y)		//keep x > y
	{
		int tmp = y;
		y = x;
		x = tmp;
	}
	while (y)
	{
		if (x % 2 == 0)	//x is even
		{
			if (y % 2 == 0)	//y is even
			{
				x >>= 1;
				y >>= 1;
				k *= 2;
			}
			else			//y is odd
			{
				x >>= 1;
			}
		}
		else			//x is odd
		{
			if (y % 2 == 0)	//y is even
			{
				y >>= 1;
			}
			else			//y is odd
			{
				if (x-y >= y)
				{
					x = x - y;
				}
				else
				{
					int tmp = y;
					y = x - y;
					x = tmp;
				}
			}
		}
	}

	return (k * x);
}

int maxSumSubArr(int *A, int n)
{
	int max_sum = numeric_limits<int>::min();
	for (int i = 0; i < n; i++)
	{
		int tmp_sum(0);
		for (int j = i; j < n; j++)
		{
			tmp_sum += A[j];
			max_sum = tmp_sum > max_sum ? tmp_sum : max_sum;
		}
	}
	return max_sum;
}

int maxSumSubArr2(int *A, int n)
{
	int nStart = A[n - 1];
	int nAll = A[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		nStart = max(A[i], A[i]+nStart);
		nAll = max(nStart, nAll);
	}

	return nAll;
}

int maxSumSubArr3(int *A, int n)
{
	int nStart = A[0];
	int nAll = A[0];
	for (int i = 1; i < n; i++)
	{
		nStart = max(A[i], A[i]+nStart);
		nAll = max(nStart, nAll);
	}

	return nAll;
}

int binarySearch(int *arr, int arr_size, int val)
{
	int min_ind = 0;
	int max_ind = arr_size - 1;
	int mid_ind;
	while (min_ind < max_ind - 1)
	{
//		mid_ind = (max_ind + min_ind) / 2;
		mid_ind = min_ind + (max_ind - min_ind) / 2;	//this way is better
		if (arr[mid_ind] == val)
		{
			return mid_ind;
		}
		else if (arr[mid_ind] > val)
		{
			max_ind = mid_ind;
		}
		else
		{
			min_ind = mid_ind;
		}
	}
	if (arr[max_ind] == val)
	{
		return max_ind;
	}
	else if (arr[min_ind] == val)
	{
		return min_ind;
	}
	else
	{
		return -1;
	}
}

int binarySearch2( int *arr, int arr_size, int val )
{
	int min_ind = 0;
	int max_ind = arr_size - 1;
	int mid_ind;
	while (min_ind <= max_ind)
	{
		mid_ind = min_ind + ((max_ind - min_ind) >> 1);
		if (arr[mid_ind] > val)
		{
			max_ind = mid_ind - 1;
		}
		else if (arr[mid_ind] < val)
		{
			min_ind = mid_ind + 1;
		}
		else
		{
			return mid_ind;
		}
	}

	return -1;
}

bool myStrToInt( const char *str, int &num )
{
	bool is_neg(false);
	num = 0;

	if (str == NULL)
	{
		num = 0;
		return false;
	}
	
	while (isspace(*str))	//skip space
	{
		++str;
	}
	if (*str == '-')		//is '+' or '-'
	{
		is_neg = true;
		++str;
	}
	else if (*str == '+')
	{
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		int tmp = *str - '0';

		//is overflow or not
		if (!is_neg && (num > INT_MAX/10 || (num == INT_MAX/10 && tmp > INT_MAX%10)))
		{
			num = INT_MAX;
			break;
		}
		else if (is_neg && (num > (unsigned)INT_MIN/10 || 
			(num == (unsigned)INT_MIN/10 && tmp > (unsigned)INT_MIN%10)))
		{
			num = INT_MIN;
			break;
		}

		num = num * 10 + tmp;
		++str;
	}

	num = is_neg ? -num : num;

	return true;
}

void rebuildBinTree( int *preorder, int *inorder, int length, BinaryTreeNode **p_root )
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return;
	}

	BinaryTreeNode *p_tmp = new BinaryTreeNode;
	p_tmp->m_nVal = *preorder;
	p_tmp->m_pLeft = NULL;
	p_tmp->m_pRight = NULL;
	if (p_root == NULL)
	{
		*p_root = p_tmp;
	}

	if (length == 1)
	{
		return;
	}

	int *left_end = inorder;
	while (*left_end != *preorder && left_end != NULL)
	{
		if (left_end == inorder + length - 1)
		{
			throw std::exception("invalid input!");
		}
		++left_end;
	}
	int left_length = (int)(left_end - inorder);
	int right_length = length - left_length - 1;

	if (left_length > 0)
	{
		rebuildBinTree(preorder+1, inorder, left_length, &((*p_root)->m_pLeft));
	}
	if (right_length > 0)
	{
		rebuildBinTree(preorder+left_length+1, inorder+left_length+1, right_length, &((*p_root)->m_pRight));
	}
}

template <typename T>
void CQueue<T>::enqueue(const T &node)
{
	stk1.push(node);
}

template <typename T>
T CQueue<T>::dequeue()
{
	T head;
	if (stk2.empty())		//if stk2 is empty, pop the stk1 into stk2 first
	{
		while (!stk1.empty())
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
	}

	if (!stk2.empty())	//make sure stk2 is not empty after pop stk1
	{
		head = stk2.top();
		stk2.pop();
	}
	else
	{
		throw exception("Error! Queue is empty!");
	}

	return head;
}