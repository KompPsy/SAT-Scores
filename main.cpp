/*
 * Author:Peter Aldrich
 * Class Data Structure CAIS 230
 * Date FEB 16 2018
 * Program Details:
 * This program entails of getting SAT score for Math and Verbal section
 * Getting the mean and Standard dev


*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <string>
using namespace std;

int main(){
//GLOBAL VARIABLES

    int sat[10][2], mathavg = 0, verbavg = 0;
    double mathstd = 0.0;
    double verbstd = 0.0;

//FUNCTIONS

    void describe_program();

    void read_scores(int sat[10][2]);

    void compute_means(int sat[10][2], int& mathavg, int& verbavg);

    void compute_std(int sat[10][2],int mathavg, int verbavg, double& mathstd,
                     double& verbstd);

    void show_results(int sat[10][2], int mathavg, int verbavg, double mathstd,
                      double verbstd);
    bool again();
    do{
        describe_program();

        read_scores(sat);
        compute_means(sat, mathavg, verbavg);
        compute_std(sat,  mathavg, verbavg, mathstd, verbstd);

        show_results(sat,  mathavg, verbavg, mathstd, verbstd);

    } while(again());
    return 0;
}

void  describe_program(){
    cout << "This is a SAT Program that takes the scores of math and verbal" <<'\n';
    cout << "which takes the mean and Standard Deviation of both sections" <<'\n';
    cout << "The Program records then writes it into a text file" <<'\n';
    return;
}
void read_scores(int sat[10][2]){
    int a; int b;
// We need a for loop to read the array for scores
    for(a=0; a<10; a++){
//another loop for subject which is 2
        for(b=0; b<2; b++){
            if(b==0){
                cout << "Enter Math Score: " <<'\n';
                cin >> sat[a][b];
            }
            else {
                cout << "Enter Verbal Score: " <<'\n';
                cin >> sat[a][b];
            }
        }
    }
    return;
}
void compute_means(int sat[10][2], int& mathavg, int& verbavg){

    double mthSATScore=0;
    double vblSatScore=0;
    int a;
    int b;
    for(a=0; a<10; a++){
//another loop for subject which is 2
        for(b=0; b<2; b++){
            if(b==0){
                mthSATScore += sat[a][b];
            }
            else{
                vblSatScore += sat[a][b];
            }
        }
    }
//We want to use mathavg and verbavg to get the total avg of each one divide by 10
    mathavg = mthSATScore/10;
    verbavg = vblSatScore/10;

    return;
}
void compute_std(int sat[10][2],int mathavg, int verbavg, double& mathstd, double& verbstd){
// We need Varience then we can get the std
    double mthVar = 0.0;
    double vblVar = 0.0;
    int a;
    int b;
    for (a = 0; a < 10; a++) {
//another loop for subject which is 2
        for (b = 0; b < 2; b++) {
            if (b == 0) {
                mthVar += pow((sat[a][b] - mathavg), 2);
            }
            else {
                vblVar += pow((sat[a][b] - verbavg), 2);
            }

        }
//We want to use mathavg and verbavg to get the total avg of each one divide by n-1
        mathavg = mthVar / 9;
        verbavg = vblVar / 9;
    }
    return;

}
void show_results(int sat[10][2], int mathavg, int verbavg, double mathstd,double verbstd) {
    ofstream write;
    write.open("SatScores.txt", ios::app);
    write << endl;
    write << fixed << showpoint << setprecision(2);
    write << setw(20) << "Math" << setw(14) << "Verbal" << setw(14) << endl;
    write << setw(20) << "----" << setw(14) << "------" << setw(14) << endl;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 2; b++) {
            if (b == 0) {
                write << setw(20) << sat[a][b];
            } else {
                write << setw(10) << sat[a][b] << endl;
            }
        }
    }

    write << "Score Mean" << endl;
    write << "----------" << endl;
    write << setw(10) << (mathavg);
    write << setw(10) << (verbavg);
    write << endl << endl;

    write << "Score STD" << endl;
    write << "---------" << endl;
    write << setw(8) << mathstd;
    write << setw(8) << verbstd;
    write << endl << endl;
    write.close();

    return;
}
bool again() {
    char response;
    while((response!= 'N' && response!= 'Y' && response!= 'y' && response!= 'n')){
        cout<<"Enter Correct response"<<endl;
        cout<<"(Note: y is for Yes and n is for No"<<endl;
        cin>>response;
    }
    response = tolower(response);

    if(response == 'y')
        return true;
    else
        return false;
}