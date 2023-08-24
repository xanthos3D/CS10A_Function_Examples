//math tutor
//xander maniaci
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//a void list for all function prototypes
void doOneSet(/*in*/char,/*in*/ int,/*out*/int&);
void getProbsPerSet(/*out*/int&);
void printReport(/*in*/int, /*in*/int, /*in*/int,/*in*/int);
void printHeader(/*in*/char);
void getMaxNum(/*out*/int&);
void doOneProblem(/*in*/char,/*in*/int, /*out*/int&);
void getNumbers(/*out*/int&,/*out*/int&,/*out*/ int);
void calcCorrectAnswer(/*in*/char ,/*in*/int ,/*in*/int,/*out*/int&);
void checkAnswer(/*in*/int,/*in*/int,/*out*/bool&);

int main (){
    //declares variables for storing scores aswell as the maximum number of problems per set.
    int probsPerSet;
    int set1Correct,set2Correct, set3Correct;

    srand(time(0)); // to setup seed for random number generator.
    getProbsPerSet(probsPerSet);//void call function to get the problems
    doOneSet('+', probsPerSet,set1Correct);// void function call
    doOneSet('-', probsPerSet,set2Correct);// void function call
    doOneSet('*', probsPerSet,set3Correct);// void function call
    printReport(set1Correct,set2Correct,set3Correct,probsPerSet);//void calls print report to get final results.

return 0;
}
//list of all void functions
//void do one set is a function that obtains the set char value + - and * as well as the number of sets and returns the score after the problem set.
void doOneSet(/*in*/char determine,/*in*/int repeat,/*out*/int& setscore)
//pre: gathers char and int value to send to other void functions for generation of problem sets.
//post:sends score to main to be used for final scores
{
    int repit = 0, correct = 0;

    printHeader(determine);
    doOneProblem(determine, repeat,correct);
    setscore = correct;
}
//this void function obtains the the number of problems for each set
void getProbsPerSet(/*out*/int& incoming){
    //pre:is called to find number of problems. problems will be within 3 to 10 as requested
    //post: sends out the number of problems per set to main
    int input = 0;
    cout<<"Enter problems per set: ";
    cin>> input;
    while(input < 3 || input >10||!cin ){//input validation
    cin.clear();
    cin.ignore(200,'\n');
    cout<<"Invalid input. try again."<<endl;
    cout<<"Enter problems per set: ";
    cin>> input;
    }
    incoming = input;//sets outgoing value to be valid user input



}
// this void function prints out the header in each set.
void printHeader(/*in*/char sign)
//pre:accepts a char variable from doOneSet.
//post: uses char variable to determine which header is needed.
{
    switch(sign){
        case('+'):cout<<"Set #1\n----------"<<endl;
        break;
        case('-'):cout<<"Set #2\n----------"<<endl;
        break;
        case('*'):cout<<"Set #3\n----------"<<endl;
        break;

    }
}
//void function prompts the user to input a number that will be the maximum value a random number can be generated.
void getMaxNum(/*out*/int& maxNum)
{
    //pre: is called from doOneProblem to prompt user to enter a max number for generating numbers.
    //post: returns max number to doOneProblem.
    int numMax = 0;
    cout<<"What is the maximum number for this set? ";
    cin>>numMax;
        while(numMax < 0 || !cin){//input validation
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Invalid input. try again."<<endl;
        cout<<"What is the maximum number for this set? ";
        cin>>numMax;
    }

    maxNum = numMax;


}
// void function that generates the problem sets using a switch statement as well as calling other functions for various problem set generation
void doOneProblem(/*out*/char symbol,/*out*/int repeater,/*out*/int& correct)
//pre: obtains a char  and a int for determining which set is active during that call
//post: sends the number of correct problems to doOneSet which then sends it to main where it is stored for final scoring.
{
    //variable declarations to store values
    int num1 = 0, num2 = 0,input = 0, answer = 0, maxNum = 0, valid = 0;
    bool cor = true;
    getMaxNum(maxNum);
    //for loop to loop through sets based on the number sent from main which was obtain from getProbsPerSet
    for(int counter = 0; counter < repeater; counter++){
            getNumbers(num1, num2,maxNum);// calls getNumbers to obtain randomly generated numbers
        switch(symbol){
        case('+'): calcCorrectAnswer(symbol,num1, num2, answer);//calls calcCorrectAnswer to obtain the correct answer
                    cout << num1 <<" + " << num2 <<" = ";
                    cin >>input;
                    checkAnswer(input,answer,cor);// calls checkAnswer to check to see if the answer input is correct.
                    break;
        case('-'):calcCorrectAnswer(symbol,num1, num2, answer);
                    cout << num1 <<" - " << num2 <<" = ";
                    cin >>input;
                    checkAnswer(input,answer,cor);
                    break;
        case('*'):calcCorrectAnswer(symbol,num1, num2, answer);
                    cout << num1 <<" * " << num2 <<" = ";
                    cin >>input;
                    checkAnswer(input,answer,cor);
                    break;
        }
        if(cor == true){// if statement to add one to valid to keep track of correct answers
            valid++;
        }

}
correct = valid;// sets correct to number of correct answers to be set to doOneSet which is then sent to
cout<<endl;// spacer between sets
}
// void function used for generating numbers
void getNumbers(/*out*/int& num1,/*out*/int& num2,/*in*/int maxNum)
//pre: obtains maximum number from doOneProblem
//post: generates two random numbers and sends them to doOneProblem
{
    num1 = rand() % maxNum + 1;
    num2 = rand() % maxNum + 1;
}
//void function creates the correct answer
void calcCorrectAnswer(/*in*/char symbol,/*in*/int num1,/*in*/int num2 ,/*out*/int& answer)
//pre: obtains char for finding the correct equation as well as the two numbers for calculations
//post: uses a switch statement to find and set answer to proper answer which is then sent back to doOneProblem
{
    switch(symbol){
        case('+'):answer = num1 + num2;
                    break;
        case('-'):answer = num1 - num2;
                    break;
        case('*'):answer = num1 * num2;
                    break;
        }

}
//check answer to see if users answer is the same as the true answer
void checkAnswer(/*out*/int input,/*out*/int answer,/*in*/bool& correct)
//pre:obtains user input and true answer from doOneProblem
//post:returns a bool value which is true or false. also prints out if answer was correct or not.
{
        if(input == answer){
            cout<<"correct"<<endl;
            correct = true;
            }else{
            cout<<"incorrect"<<endl;
            correct = false;
            }
}
//returns the final score values at the very end of the program
void printReport(/*in*/int correct1, /*in*/int correct2, /*in*/int correct3,/*in*/int probset)
//pre:obtains the numbers of correct answers from each problem set from main as well as the number of problems per set.
//post: calculates the percentage for each of the correct values and prints them out to the screen
{
    //declares values for calculations
    double percent1 = 0, percent2 = 0, percent3 = 0, overall = 0, sum = 0;
    percent1 = (100*correct1)/probset;
    cout<<"\nSet#1:  You got "<<correct1<<" correct out of "<<probset<<"  for "<<percent1<<"%"<<endl;
    percent2 = (100*correct2)/probset;
    cout<<"Set#2:  You got "<<correct2<<" correct out of "<<probset<<"  for "<<percent2<<"%"<<endl;
    percent3 = (100*correct3)/probset;
    cout<<"Set#3:  You got "<<correct3<<" correct out of "<<probset<<"  for "<<percent3<<"%"<<endl;
    overall = (100*(correct1 + correct2 + correct3))/(probset*3);//
    sum = correct1 + correct2 + correct3;
    cout<<"Overall You got "<<sum<<" correct out of "<<probset*3<<"  for "<<overall<<"%"<<endl;

}













