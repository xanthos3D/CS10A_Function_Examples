//xander maniaci
//project 1
#include<iostream>

using namespace std;
//out going functions prototypes
void drawcone(int);
void evenbox(int, int);
void oddbox(int, int);

int main(){
    //declaration of variables to receive inputs
    int height = 0, width = 0, stages = 0;
    // prompts user for height width and number of stages. each input has a input validation while loop after it to ensure only acceptable variables are entered
    cout<<"this program prints a rocket ship with your specifications"<<endl;
    cout<<"enter a height: ";
    cin>>height;
    while(!cin || height < 3 || height > 15){
    cin.clear();
    cin.ignore(200,'\n');
    cout<<"please enter a height that is between 3 and 15."<<endl;
    cout<<"enter a height: ";
    cin>>height;
    }
    cout<<"enter a width: ";
    cin>> width;
    while(!cin || width < 3 || width > 15){
    cin.clear();
    cin.ignore(200,'\n');
    cout<<"please enter a width that is between 3 and 15."<<endl;
    cout<<"enter a width: ";
    cin>>width;
    }
    cout<<"enter number of stages: ";
    cin>>stages;
    while(!cin || stages < 0){
    cin.clear();
    cin.ignore(200,'\n');
    cout<<"please enter a stage that is a positive number."<<endl;
    cout<<"enter number of stages: ";
    cin>>stages;
    }
    //draws the cone on top. had to manipulate the variable input inorder to make the cone line up better with the other stages of the body.
    drawcone(width/2+1);
// for loop to print out number of stages and a if statement to see if a hollow or filled stages are to be output.
for(int counter = 0;counter < stages; counter++){
if(height%2 == 0){
    evenbox(height, width);
}else{
oddbox(height, width);
}
}
//draws bottom cone.
drawcone(width/2+1);

return 0;
}
//outputs a cone
void drawcone(int number){
    //variables needed for generating cone
    int width1 = 0, width2 = 0,change = 1, height = 0;
    //sets variables to input value.
    width1 = number;
    width2 = number;
    height = number;
    // this series of nested for loops prints out three triangles that when combine create the cone.
    for(int counter = 0; counter < height;counter++){
        for(int counter2 = 0; counter2 < width1;counter2++){
         if(counter2 >= width1-1){
            cout<<"*";
         }else if(counter2 < width1){
         cout<<" ";
         }
        }
        if(counter > 0){
        for(int counter3 = 0; counter3 < change; counter3++){
            cout<<" ";
        }
        for(int counter4 = 0; counter4 < change; counter4++){
            if(counter4 == change-1){
                cout<<"*";
            }else{
            cout<<" ";
            }
        }
        change++;
        }
        cout<<endl;
        width1--;
 }
}
//prints out the even box
void evenbox(int height, int width){
    //prints out first row of hollow box.
    for(int firstrow = 0;firstrow < width; firstrow++){
        cout<<"*";
    }
    cout<<endl;
    for(int counter = 0; counter < height-2; counter++){
        for(int counter2 = 0; counter2 < width; counter2++){
                //tests to see if there should be a * or a space printed.
            if(counter2 == 0 || counter2 == width-1){
            cout<<"*";
            }else if(counter2 > 0 && counter2 < width-1){
            cout<<" ";
            }
        }
        cout<<endl;
    }
    // prints bottom row
    for(int lastrow = 0;lastrow < width; lastrow++){
        cout<<"*";
    }
    cout<<endl;

}
// prints out a odd box. just prints a filled square
void oddbox(int height, int width){

    for(int counter = 0; counter < height; counter++){
        for(int counter2 = 0; counter2 < width; counter2++){
                cout<<"*";
        }
        cout<<endl;

    }
}




