#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmex.lib")
#pragma comment( lib, "libeng.lib")

#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h"
// end

#include<engine.h>

#include<iostream>
#include<cmath>
#include<time.h>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main(void)
{
	double a = 0, sum = 0;
	int n = 1000;

	double *d = new double[n];

	for (int i = 0; i <n; i++)
	{
		d[i] = i + 1;

	}




	// creating a pointer to the engine
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "Error: Not Found." << endl;
		exit(1);
	}
	// end

	mxArray *A;
	A = mxCreateDoubleMatrix(1, n, mxREAL);
	memcpy((void *)mxGetPr(A), (void *)d, n*sizeof(double));
	engPutVariable(ep, "xx", A);


	engEvalString(ep, "X=xx;");
	engEvalString(ep, "plot(X);");	//call plot function


	engEvalString(ep, "title('Successful!!!');");

	mxDestroyArray(A);



	system("pause");
	return 0;
}