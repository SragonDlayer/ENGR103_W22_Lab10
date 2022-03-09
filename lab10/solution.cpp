/**********************************************************
 * Filename: solution.cpp
 * Author: Ben Roney
 * Date: 3/9/2022
 * Desc: A solution to the given task
 * Input: 
 * Output:
 * *******************************************************/
#include <iostream> 
#include <cstdlib>

using namespace std;

#define MAX_LENGTH 1024

void arraySum(int size, int nums[]);
void makeArray(int size, int nums[]);
bool isPosInt(string number);

int main() {
	string sizeStr = "";
	int size = 0;
   	do{
		cout << "Please enter the size of your array (2-1023): ";
		cin >> sizeStr;
	} while(!(isPosInt(sizeStr) && (stoi(sizeStr) < MAX_LENGTH) && stoi(sizeStr) > 1));
	size = stoi(sizeStr);
	int nums[size+1];
	makeArray(size, nums);
	arraySum(size, nums);
	cout << "The array is: [";
	for(int i=0; i<size; i++){
		cout << nums[i];
		if(i != size-1)
		   	cout << ", ";
		else if(i==size-1)
		   	cout << "]" << endl;
	}
}

bool isPosInt(string number){
	if(number == "")
	   	return false;
	for(int i=0; i<number.length(); i++){
		if(!(number[i] >= '0' && number[i] <= '9'))
		   	return false;
	}
	return true;
}

void makeArray(int size, int nums[]){
	string val = "";
   	for(int i=0; i<size; i++){
	   	do{
	   		cout << "Please enter integer value " << i+1 << ": ";
			cin >> val;
		} while(!isPosInt(val));
		nums[i] = stoi(val);
		//cout << nums[i];
	}
}

void arraySum(int size, int nums[]){
	for(int i=0; i<size; i++){
		int temp = 0;
	   	temp = nums[i+1];
	   	nums[i+1] = nums[i] + temp;
	}	
}
