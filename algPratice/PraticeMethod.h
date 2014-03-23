#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

//Book 2.1, calculate sum of '1' in binary(8 bit)
int countOne(int _byte);
int countOne2(int _byte);
int countOne3(int _byte);

//Book 2.2 problem 1, calculate sum of '0' in factorial 'N!'
int sum0InFactorial(int n);
int sum0InFactorial2(int n);

//Book 2.2 problem 2, output the lowest '1' in factorial 'N!' in binary
int lowest1InFactBin(int n);
int lowest1InFactBin2(int n);

//Book 2.3, find the WaterKing
char findWaterKing(char *ID, int n);
void findWaterKing2(char *ID, int n);

//Book 2.4 problem 1, calculate sum of '1' in number 'n'
long sum1s(long n);

//Book 2.5, find the K biggest number of an array
template <typename T>
void findKBig(vector<T> &input_array, int K, vector<T> &output_array);
template <typename T>
void arrayPartition(vector<T> &input_array, vector<T> &output_array1, vector<T> &output_array2);

//Book 2.7, find greatest common divisor, GCD
int myGCD(int x, int y);	//simply minus
int myGCD2(int x, int y);

//Book 2.14, find the biggest sum of subarray
int maxSumSubArr(int *A, int n);
int maxSumSubArr2(int *A, int n);
int maxSumSubArr3(int *A, int n);

//Book 3.11 binary search
int binarySearch(int *arr, int arr_size, int val);
int binarySearch2(int *arr, int arr_size, int val);

//Book <point to the offer>
//convert string to int
bool myStrToInt(const char *str, int &num);

//rebuild the binary tree
struct BinaryTreeNode{
	int m_nVal;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
void rebuildBinTree(int *preorder, int *inorder, int length, BinaryTreeNode **p_root);

//use two stack for queue implementation
template <typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();
	void enqueue(const T &node);
	T dequeue();
private:
	stack<T> stk1;	//for enqueue
	stack<T> stk2;	//for dequeue
};