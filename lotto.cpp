//lotto
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;

void generatenumbers(/*inout*/int[],/*in*/int);
void userinput(/*inout*/int[],/*in*/int);
void showoutput(const int[],const int[], int);
void findmatch(const int[],const int[], int);

int main()


{
const int size = 5;
//const int MAX_SIZE = 9;

int lottery[size]={};
int userticket[size]={};
}
void generatenumbers(/*inout*/int[],/*in*/int size)
{
  srand(time(0));
  for(int count = 0;count<size;count++)
  {
      random[count] = 0 + rand() % MAX_SIZE;
  }
}
void userinput(/*inout*/int[],/*in*/int)
{

}
void showoutput(const int random[],const intuserticket[], int size)
{

}
void findmatch(const int random[],const intuserticket[], int size)
{

}

