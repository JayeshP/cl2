
#include "soapcalcProxy.h"
#include "calc.nsmap"
#include "strings.h"
#include "iostream"
using namespace std;
int main()
{ 
	calc c; /* calc object */
  	int n,x=2,y=2; /* result value */
	if (c.ns__add(x, y, &n) == SOAP_OK)
		cout << "add result = " << n << endl;
	else
   	    soap_print_fault(c.soap, stderr); 
	cin.ignore(50,'\n');
  	return 0;
}
