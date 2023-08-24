//rainfall
#include <iostream>
using namespace std;

void getData(/*inout*/double[],/*in*/int);
double displayReport(/*inout*/const double[],/*in*/int);
double totalRainfall(/*inout*/const double[],/*in*/int);
double averageRainfall(/*inout*/const double[],/*in*/int);
double dryestRainfall(/*inout*/const double[],/*in*/int);
double wettestRainfall(/*inout*/const double[],/*in*/int);

int main()
{
    const int months = 12;
    double rainfall[months] ={32.45,1.2,3.2,4.5,100.56,.45,.01,.02,0,0,3.45,2.34};
    double rainfall2[months]= {};
    double totalRainfall();
    displayReport(rainfall,months);
return 0;
}
void getData(/*inout*/double[],/*in*/int)
{

}
double displayReport(/*inout*/const double somearray[],/*in*/int size)
{

    cout<<"\n++++++++++++++++++++++++++++++++++."<<endl;
    cout<<"2018 Rain Report for Sonoma county."<<endl;
    cout<<"++++++++++++++++++++++++++++++++++."<<endl;
    cout<<"current rainfall data for the year."<<endl;
    for(int count = 0; count<size; count++)
    {
        cout<<"month#"<<(count +1)<<": "<< somearray[count]<<endl;
    }
    cout<<"total rainfall :"<<totalRainfall(somearray,size)<<" inches."<<endl;
        cout<<"average rainfall :"<<averageRainfall(somearray,size)<<" inches."<<endl;
        cout<<"total rainfall :"<<endl;
        cout<<"total rainfall :"<<endl;
    }

}
double totalRainfall(/*inout*/const double somearray[],/*in*/int size)
{
    double rainfall_total = 0;

    for(int count = 0;count<size;count++)
    {
        rainfall_total+= somearray[count];

    }

    return rainfall_total;
}
double averageRainfall(/*inout*/const double somearray[],/*in*/int size)
{
double average = totalRainfall(somearray,size)/size;
}
double dryestRainfall(/*inout*/const double somearray[],/*in*/int size)
{

}
double wettestRainfall(/*inout*/const double somearray[],/*in*/int size)
{

}

