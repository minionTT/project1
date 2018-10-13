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
        int print_row(){
            return row;
        }
        int print_col(){
            return column;
        }
    private:
        int row;
        int column;
};

int main(int argc, char* argv[]){
    //string line;

    string infilename = "./";
    string outfilename = "./";
    infilename += argv[1];
    outfilename += argv[1];
    infilename += "/matrix.data";
    outfilename += "/final.peak";
    fstream infile (infilename);
    ofstream outfile (outfilename);

    int row,column;
    int i,j;
    int tmpin;
    int input[2][1001];
    int num=0;
    
    queue <element> myqueue;
    queue <element> secqueue;

    if(infile.is_open()){
        infile >> row >> column;
        //cout << row << " " << column << endl;

        for(i=1; i<=row; i++){
            for(j=1; j<=column; j++){
                infile >> tmpin;
                if(i==1){
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
                if(j>1){
                    if(input[0][j-1] > tmpin){
                        input[1][j-1] = input[1][j-1] & 1;
                        input[1][j] = input[1][j] & 0;
                        if(i == row){
                            if(input[1][j-1] == 1){
                                element* in = (element*) new element(i,j-1);
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
                        if(i == row){
                            if(input[1][j-1] == 1){
                                element* in = (element*) new element(i,j-1);
                                secqueue.push( *in);
                                num++;
                            }
                        }
                    }
                }
                if(i == row){
                    if(j == column){
                        if(input[1][j] == 1){
                            element* in = (element*) new element(i,j);
                            secqueue.push( *in);
                            num++;
                        }
                    }
                }
            }
        }

        if(outfile.is_open()){
            outfile << num << endl;
            //cout << num << endl;
            while(!myqueue.empty()){
                element out = myqueue.front();
                outfile << out.print_row() << " " << out.print_col() << endl;
                //cout << out.print_row() << " " << out.print_col() << endl;
                myqueue.pop();
            }
            while(!secqueue.empty()){
                element out = secqueue.front();
                outfile << out.print_row() << " " << out.print_col() << endl;
                //cout << out.print_row() << " " << out.print_col() << endl;
                secqueue.pop();
            }
            outfile.close();
        }else{
            cout << "Unable to open file_out" << endl;
        }

        infile.close();
    }else{
        cout << "Unable to open file_in" << endl;
    }

    return 0;
}
