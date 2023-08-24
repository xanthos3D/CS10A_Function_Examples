//xander maniaci
//Algorithm Workbench 6 Driver’s License Exam
#include <iostream>
using namespace std;
//prototypes

void getAnswers(char&);
void checkAnswer(char,int,int&,int&,string&);
void displayResults(string, int);
void getTestResult(int, int);
int main()
{
     const int sizes = 20;
     char answers[sizes];
     string check[sizes], temp;
     int correct = 0,incorrect = 0;

     cout<<"This program checks a portion of the Driver's License Exam."<<endl;
     for(int counter = 0; counter < sizes; counter++)
    {
        getAnswers(answers[counter]);
        checkAnswer(answers[counter],counter,correct,incorrect,temp);
        check[counter] = temp;
    }
    getTestResult(correct,incorrect);
    for(int counter1 = 0; counter1 < sizes; counter1++)
    {
        displayResults(check[counter1],counter1);
    }

return 0;
}

void getAnswers(char& answer)
{
    char input;
    static int tracker = 0;
        cout<<"enter the answer to the problem#"<< tracker + 1 <<": ";
        cin>> input;
        while(!cin || input< 63 || input > 69 && input < 96 || input > 101)
        {
        cin.clear();//clears the fail state of the incoming file stream.
        cin.ignore(200, '\n');// clears buffer of the fail state of the incoming file stream
        cout<<"enTer a valid character."<<endl;
        cout<<"enter the answer to the problem#"<< tracker+1 <<": ";
        cin>> input;
        }
        answer = input;
        tracker++;

}

void checkAnswer(char answer, int problem,int& correct,int& incorrect, string& temp)
{
    const int sizes = 20;
    char capTrueAnswers[sizes] = {'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'};
    char lowerTrueAnswers[sizes] = {'b','d','a','a','c','a','b','a','c','d','b','c','d','a','d','c','c','b','d','a'};
    if(answer == capTrueAnswers[problem])
        {
            correct++;
            temp = "CORRECT.";
        }else if(answer == lowerTrueAnswers[problem]){
            correct++;
            temp = "CORRECT.";
        }else{
         incorrect++;
         temp = "INCORRECT.";
        }

}
void displayResults(string right, int problem)
{
    cout<<"On problem "<< problem + 1 <<" your answer was "<< right <<endl;

}
void getTestResult(int correct, int incorrect)
{
    if(correct < 15)
    {
        cout<<"you FAILED the exam."<<endl;
    }else{
        cout<<"you PASSED the exam."<<endl;
    }

    cout<<"Answers correct: "<< correct <<endl;
    cout<<"Answers incorrect: "<< incorrect<< endl;
    cout<<endl;
}









