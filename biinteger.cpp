#include<iostream>
#define digits 18

class biginteger {
	int arr[digits];
    char *number;
    int* input()
    {
    	
	}
    public:
    	void biginteger();
    	
    	biginteger operator + (biginetger num1);
    	biginteger operator - (biginteger num1);
    	biginteger operator * (biginteger num1);
    	biginteger operator / (biginteger num1);
};

biginteger biginteger::operator + (biginteger num1);
biginteger biginteger::operator - (biginteger num1);
biginteger biginteger::operator * (biginteger num1);
biginteger biginteger::operator / (biginteger num1);
