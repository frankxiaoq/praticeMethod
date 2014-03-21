#include "SortMethod.h"
#include "PraticeMethod.h"

int main(int argc, char **argv)
{
	int arr[] = {-1, 3 -4, 1, 6};
	int arr_sum = maxSumSubArr3(arr, 5);
	cout << arr_sum << endl;

	int aa(0);
	int *pta = &aa;
	int &rfa = aa;
	double bb(0.0);
	double *ptb = &bb;
	double &rfb = bb;
	cout << sizeof(pta) << " " << sizeof(ptb) << endl;
	cout << sizeof(rfa) << " " << sizeof(rfb) << endl;

	return 0;
}