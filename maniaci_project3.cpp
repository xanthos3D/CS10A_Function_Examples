#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
//list of prototypes
void menuDisplay();
void checkInput(/*out*/int&);
void options(/*in*/int);
void menuSelect(/*in*/int);
void getScores (/*in*/int,/*out*/int&);
void scoresFromFile(/*in*/int,/*out*/int&);
void storeFileData(bool,/*in*/int,/*in*/int,/*out*/int&);
void highestScore(/*in*/int,/*inout*/const int[],/*out*/int&);
void lowestScore(/*in*/int,/*inout*/const int[],/*out*/int&);
void average(/*in*/int,/*inout*/const int[]);
void printScore(/*in*/int,/*in*/const int[]);


int main()
{
    int input = 0;

    do{
        menuDisplay();//call to display menu
        checkInput(input);//calls to get a valid input
        menuSelect(input);//calls to the selection function
    }while(input != 8);
    cout<<"\nArray processing test now concluded. Exiting program .....\n"<<endl;



}
//list of all void functions
//displays menu
void menuDisplay()
{
    cout<<"---------------------------------------------------\n1-D ARRAY PROCESSING MENU OPTIONS\n---------------------------------------------------"<<endl;
    cout<<"1. Read in 10 scores from user."<<endl;
    cout<<"2. Read in 10 scores from the file, scores.txt."<<endl;
    cout<<"3. Print all scores."<<endl;
    cout<<"4. Print the highest score."<<endl;
    cout<<"5. Print the lowest score."<<endl;
    cout<<"6. Print the average score."<<endl;
    cout<<"7. Print one score (give its entry number)"<<endl;
    cout<<"8. Quit program"<<endl;


}
//prompts user to enter input for option the want to choose
void checkInput(/*out*/int& input)
//pre prompts user for input
//post sends user input back to main
{
    int in = 0;
    cout<<"\nEnter your choice:";
    cin>>in;
    while(!cin|| in <0 || in > 8){// input validation to ensure values is between 1 and 8
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Please enter a valid choice"<<endl;
        cout<<"Enter your choice:";
        cin>>in;
    }
    input = in;
    cout<<endl;


}
// void function to serve as the internal menu options.
void menuSelect(int input)
//pre obtains a valid input from main to be used for deciding what to do through the switch statement below
{
    const int sizes = 10;
    static int scores[sizes],highest = 0,lowest = 9999;// these values being static is needed as each time the function is called it needs to know what has been input from prior options
    double avg = 0.0;
    switch(input){

        case (1): for(int counter = 0;counter < 10;counter++)
                  {
                      getScores(counter, scores[counter]);//calls get scores to obtain scores from the user.
                  }
                  break;
        case (2): scoresFromFile(1,scores[1]);// calls function to get scoress from  a valid file.
                  for(int counter = 0;counter < 10;counter++)
                  {
                      storeFileData(true,0,counter,scores[counter]);//obtains values from the storefiledata function
                  }
                 break;
        case (3):for(int counter = 0;counter < 10;counter++)//forloop for printing out scores once they have been obtained
                  {
                      if(counter == 9)
                      {
                        cout<<"score #"<<counter + 1<<":      "<<scores[counter]<<endl;
                      }else{
                        cout<<"score #"<<counter + 1<<":       "<<scores[counter]<<endl;
                      }
                  }
                    cout<<endl;
                    break;
        case (4):highestScore(sizes,scores, highest);//calls function highest score to calculate highest score and return in to this function
                  cout<<"The highest score is "<<highest<<endl;
                  cout<<endl;
                 break;
        case (5):lowestScore(sizes,scores, lowest);//calls function lowest score to calculate lowest score and return in to this function
                 cout<<"The lowest score is "<<lowest<<endl;
                 cout<<endl;
                 break;
        case (6): average(sizes,scores);//calls function to calculates average by obtaining array data and its size
                 cout<<endl;
                 break;
        case (7): printScore(sizes,scores);//calls function to print a singular score
                 break;
        case (8)://falls through and exits program
                 break;
    }

}
//function prompts user to enter scores and ensures they are valid
void getScores(/*in*/int scoreNum,/*out*/int& returning)
//pre: prompts user for input
//post: ensure input is valid and sends it back to switch function.
{
 int input = 0;
 cout<<"score #"<<scoreNum + 1<<":";
 cin>>input;
     while(!cin || input < 0){//used for input validation. ensures that values are not -
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Please enter a score"<<endl;
        cout<<"score #"<<scoreNum + 1<<":";
        cin>>input;
    }
 returning = input;
}
//function gets scores from a file
void scoresFromFile(/*in*/int scoreNum,/*out*/int& returning)
{
    //pre: opens a valid file
    //post: sends values in file to a storage function
    string fileName = "";
    const int sizes = 10;
    int scores = 0,storage[sizes], counter = 0;

    ifstream inFile;
    cout<<endl;
    cout<<"Enter another filename or type quit to exit: ";
    cin>>fileName;
    inFile.open(fileName.c_str());// for run time input for file name prior to c++11
        // bonds a valid file to the incoming stream to the incoming stream variable
        //file not found validation routine
        while(!inFile){
                inFile.clear();//clears the failstate of the incoming file stream.
                inFile.ignore(200, '\n');// clears buffer of the failstate of the incoming file stream
                cout<<"File note found. Enter the correct filename: ";
                cin>>fileName;
                inFile.open(fileName.c_str());
            }
            cout<<"File has successfully opened and 10 scores have been read and stored."<<endl;
            cout<<"Please select the print all scores menu option to view the scores"<<endl;
            while(inFile){
        inFile>>scores;//read the next int
        storeFileData(false,scores,counter,storage[counter]);//collects values and stores then in another function to be retrieved by the switch function
        counter++;
        }
        inFile.close();// to close file
        cout<<endl;

}
//function to store values from a file
void storeFileData(bool choose,/*in*/int scores,int place/*out*/,int& returning)
{
    //pre: obtains value from function
    //post:returns values to switch function or obtains values and stores them depending on bool variable
    const int sizes = 10;
    static int storage[sizes];
    if (choose == true){
       returning = storage[place];
    }else{
storage[place] = scores;
   returning = scores;
    }
}
//function finds highest score
void highestScore(/*in*/int SIZE,/*in*/const int score[],/*out*/int& large)
//pre: obtains array, size of array and outputs largest
//post:finds highest score by comparing all values in the array passed to it
{
    int highest = 0;

    for(int counter = 0;counter < SIZE;counter++){
        if(score[counter] > highest)
        {
        highest = score[counter];
        large = highest;
        }
    }
}
//function finds lowest score
void lowestScore(/*in*/int SIZE,/*in*/const int score[],/*out*/int& low)
//pre: obtains array, size of array and outputs smallest
//post:finds smallest score by comparing all values in the array passed to it
{
     int lowest = 9999;
    for(int counter = 0;counter < SIZE;counter++){
    if(score[counter]< lowest)
    {
        lowest = score[counter];
        low = lowest;
    }
    }
}
//function to calculate average
void average(/*in*/int SIZE,/*inout*/const int scores[])
{
//pre: obtains array, size of array and outputs average
//post:finds average score by comparing all values in the array passed to it

     double sum = 0, total = 10, average = 0;
    for(int counter = 0;counter < SIZE;counter++)
    {
        sum += scores[counter];
    }
     average = sum / total;
     cout<<"The average score is "<< fixed<< showpoint<< setprecision(2)<<average<<endl;
}
//function finds a specific score
void printScore(int SIZE,const int scores[])
{
//pre: obtains array, size of array and outputs value an place in array
//post:finds place by prompting user and ensuring it is valid. then finds value from array passed to in and displays it.
    int input = 0;

    cout<<"Please enter entry or row # of score you want:";
    cin>>input;
     while(!cin || input < 0 || input > 10){
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Invalid entry. please enter a number between 1 and 10."<<endl;
        cout<<"Please enter entry or row # of score you want:";
        cin>>input;
     }
    cout<<"Entry #"<<input<<" score: "<<scores[input-1]<<endl;
}








