#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    string line;
    string filename = "./";
    filename += argv[1];
    filename += "/matrix.data";
    fstream myfile (filename);

    int row,column;
    int i,j;
    int tmpin;
    int input[2][1000];

    if(myfile.is_open()){
        myfile >> row >> column;
        cout << row << " " << column << endl;

        for(i=0; i<row; i++){
            for(j=0; j<column; j++){
                myfile >> tmpin;
                if(i==0){
                    input[0][j] = tmpin;
                    input[1][j] = 1;
                    if(j>0){
                        if(input[0][j-1] > tmpin){
                            input[1][j-1] = input[1][j-1] & 1;
                            input[1][j] = input[1][j] & 0;
                        }else if(input[0][j-1] < tmpin) {
                            input[1][j-1] = input[1][j-1] & 0;
                            input[1][j] = input[1][j] & 1;
                        }else{
                            input[1][j-1] = input[1][j-1] & 1;
                            input[1][j] = input[1][j] & 1;
                        }
                    }
                }else{
                    if(j==0){
                        if(input[i-1][j] > tmpin){

                        }
                    }
                }
            }
        }

        

        myfile.close();
    }else{
        cout << "Unable to open file." << endl;
    }

    return 0;
}
