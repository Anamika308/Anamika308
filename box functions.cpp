#include <iostream>
using namespace std;

class Box
{
public:
    Box(){};
    double m_Length;
    double m_Width;
    double m_Height;

};

int main()
{
    Box box1;
    Box box2;

    double boxVolume_1(0.0);
    double surfaceArea_1(0.0);
    double boxVolume_2(0.0);
    double surfaceArea_2(0.0);
    
    cout << "Enter the length, breadth, height of first box:"<<endl; 
   cin >> box1.m_Length >> box1.m_Width >>box1.m_Height ;

   cout << "Enter the length, breadth, height of second box:"<<endl; 
   cin >> box2.m_Length>> box2.m_Width >>box2.m_Height ;


    boxVolume_1 = box1.m_Height * box1.m_Length * box1.m_Width;
    surfaceArea_1 = 2.0 * ((box1.m_Height * box1.m_Width) + (box1.m_Length * box1.m_Height) + (box1.m_Length * box1.m_Width));

    boxVolume_2 = box2.m_Height * box2.m_Length * box2.m_Width;
    surfaceArea_2 = 2.0 * ((box2.m_Height * box2.m_Width) + (box2.m_Length * box2.m_Height) + (box2.m_Length * box2.m_Width));


    cout << "Volume of box1= " << boxVolume_1 <<" and volume of box2= "<<boxVolume_2<< endl<<endl;
    cout << "Surface Area of box1= " << surfaceArea_1<<" and surface area of box2= "<<surfaceArea_2 << endl;
    
    if((box1.m_Length==box2.m_Length)&&(box1.m_Width==box2.m_Width)&&(box1.m_Height==box2.m_Height))
    {
    	cout<<"\nBoth boxes are equal."<<endl;
	}else{
		cout<<"\nBoth boxes are not equal."<<endl;
	}
	
	if((box1.m_Length==box1.m_Width)&&(box1.m_Width==box1.m_Height)&&(box1.m_Height==box1.m_Length))
	{
		cout<<"\nBox1 is cube."<<endl;
	}else{
		cout<<"\nBox1 is cuboid."<<endl;
	}
	
	if((box2.m_Length==box2.m_Width)&&(box2.m_Width==box2.m_Height)&&(box2.m_Height==box2.m_Length))
	{
		cout<<"\nBox2 is cube."<<endl;
	}else{
		cout<<"\nBox2 is cuboid."<<endl;
	}
    
    return 0;
}
