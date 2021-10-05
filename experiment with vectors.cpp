#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n=10;
	vector<int> vec(n);
	
	cout<<"Intial vector: ";
	for(int i=0;i<n;i++){
		cout<<vec[i]<<" ";
	}
	//the elements
	
	for(int i=0;i<n;i++){
		vec.push_back(i);	
	}
	cout<<"\nafter adding the elements vector is: ";
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\nThe size is: "<<vec.size();
	cout<<"\nThe capacity is: "<<vec.capacity();
	
	//adding the element in last
	vec.push_back(4);
	int a=vec.size(); 
	cout<<"\nLast element entered is: "<<vec[a-1];
		cout<<"\nElements are: ";
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\nThe size is: "<<vec.size();
	
	//deleting the last element
	vec.pop_back();
	
	cout<<"\nAfter deleting last element contents are: ";
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\nThe size is: "<<vec.size();
	//inserting the element at the begining
	vec.insert(vec.begin(),5);
	cout<<"\nElement that inserted: "<<vec[0];
		cout<<"\nElements are: ";
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	
	//element accesser
	cout<<"\nOperartor[i]: vec[3]: "<<vec[3];
	cout<<"\nElement at position 3: "<<vec.at(4);
	cout<<"\nReference of first element: "<<vec.front();
	cout<<"\nReference of last element: "<<vec.back();
	
	//reserving
	vec.reserve(8);
	cout<<"\nAfter reserve , size : "<<vec.size();
	
	//resizing 
	vec.resize(6);
	cout<<"\nThe size after resizing is: "<<vec.size();
	
	//clearing the whole elements
	vec.clear();
	cout<<"\nNow the size of vector after using clear func.: "<<vec.size();
	
	//check if  vector is empty or not
	if(vec.empty()==false)
	    cout<<"\nVector is not empty.";
	else
	    cout<<"\nVector is empty.";
	
	
	return 0;
}
/*OUTPUT_________________
Intial vector: 0 0 0 0 0 0 0 0 0 0
after adding the elements vector is: 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9
The size is: 20
The capacity is: 20
Last element entered is: 4
Elements are: 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 4
The size is: 21
After deleting last element contents are: 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9
The size is: 20
Element that inserted: 5
Elements are: 5 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9
Operartor[i]: vec[3]: 0
Element at position 3: 0
Reference of first element: 5
Reference of last element: 9
After reserve , size : 21
The size after resizing is: 6
Now the size of vector after using clear func.: 0
Vector is empty.
*/

