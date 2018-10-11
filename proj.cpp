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
    int i,j,k;
    int input[2][1000];

    if(myfile.is_open()){
        myfile >> row >> column;
        cout << row << " " << column << endl;

        for(i=0; i<part; i++){
            for(j=0; j<100; j++){
                for(k=0; k<column; k++){
                    myfile >> input[j][k];
                    trans[k][j] = input[j][k];
                    //cout << input[j][k] << " ";

                    

                }
                //cout << endl;
            }
        }

        for(j=100*part; j<row; j++){
            for(k=0; k<column; k++){
                myfile >> input[j][k];
                //cout << input[j][k] << " ";
            }
            //cout << endl;
        }

        myfile.close();
    }else{
        cout << "Unable to open file." << endl;
    }

    return 0;
}

