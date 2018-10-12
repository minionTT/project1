#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class element{
    public:
        element(){
            row = 0;
            column = 0;
        }
        element(int in1, int in2){
            row = in1;
            column = in2;
        }
        void print(){
            cout <<  row << " " << column << endl;
        }
    private:
        int row;
        int column;
};

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
    int num=0;
    
    queue <element> myqueue;
    queue <element> secqueue;

    if(myfile.is_open()){
        myfile >> row >> column;
        //cout << row << " " << column << endl;

        for(i=0; i<row; i++){
            for(j=0; j<column; j++){
                myfile >> tmpin;
                if(i==0){
                    input[1][j] = 1;
                    
                }else{
                    if(input[0][j] >= tmpin){
                        if((input[1][j] & 1) == 1 ) {
                            //cout << i-1 << " " << j << endl;
                            element* in = (element*) new element(i-1,j);
                            //in->print(); 
                            myqueue.push( *in);
                            num++;
                        }
                        
                    }
                    if(input[0][j] > tmpin){
                        input[1][j] = 0;
                    }else{
                        input[1][j] = 1;
                    }
                }
                input[0][j] = tmpin;
                if(j>0){
                    if(input[0][j-1] > tmpin){
                        input[1][j-1] = input[1][j-1] & 1;
                        input[1][j] = input[1][j] & 0;
                        if(i == row - 1){
                            if(input[1][j-1] == 1){
                                element* in = (element*) new element(i,j);
                                secqueue.push( *in);
                                num++;
                            }
                        }
                    }else if(input[0][j-1] < tmpin) {
                        input[1][j-1] = input[1][j-1] & 0;
                        input[1][j] = input[1][j] & 1;
                    }else{
                        input[1][j-1] = input[1][j-1] & 1;
                        input[1][j] = input[1][j] & 1;
                        if(i == row - 1){
                            if(input[1][j-1] == 1){
                                element* in = (element*) new element(i,j);
                                secqueue.push( *in);
                                num++;
                            }
                        }
                    }
                }
                if(i == row - 1){
                    if(j == column - 1){
                        if(input[1][j] == 1){
                            element* in = (element*) new element(i,j);
                            secqueue.push( *in);
                            num++;
                        }
                    }
                }
            }
        }

        cout << num << endl;
        while(!myqueue.empty()){
            element out = myqueue.front();
            out.print();
            myqueue.pop();
        }
        while(!secqueue.empty()){
            element out = secqueue.front();
            out.print();
            secqueue.pop();
        }
        

        myfile.close();
    }else{
        cout << "Unable to open file." << endl;
    }

    return 0;
}
