// Hello project


/*
Need to make a terminal with the ability to handle commands.
Needs to be able to store commands into a file(history).
*/

/* ------------- IN CLASS CODE NOTES -----------------*/
    //handles a command(exit, history, pwd"print working directory")
	//handles attaching data and setting files(only needs to be able to handle a single one at a time)

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<unistd.h>
#include<sstream>

using namespace std;


//Need the code from As3 for vector parsing


// Adds user input into log
void addToHistory(string data){
    // open or (if not made yet) make the file.

    //send the data to the file

    //close file

    //end
}

int stdOutRead(string line){

}

int stdInRead(string line){

}

int hasPipe(string line){
    
}



int main(){
	//load any needed data

    //storage file
    string historyLog = "hist_log.txt";
    //get current working directory
    string directory = getcwd();
    //user input
    string in;
    //bool for exiting
    bool ender = false;
    //prep-pipes
    toP[2];
    toC[2];
    if(pipe(toP) < 0){
        cout << "ERROR: Cannot create pipe (toP)" << endl;
        exit(1);
    }
    if(pipe(toC) < 0){
        cout << "ERROR: Cannot create pipe (toC)" << endl;
        exit(1);
    }

    //Store og STD's
    int ogIN = dup(0);
    int ogOUT = dup(1);


	//start up the "terminal"
    while(!ender){
        cout << directory << "~$";
        getline(in, line);
        addToHistory(line);
        if(line = "exit"){
            ender = true;
        }
        else if(line = "history"){
            //print the history
            ifstream file(historyLog);
            if(!file.is_open){
                cout << "ERROR: File not found" << endl;
                exit(3);
            }
            string data;
            while(getline(file, data)){
                cout << data << endl;
            }
            //make sure to close file
            file.close();
        }
        else if(stdOutRead(line)>-1){
            //command -> child -> execvp
            //handle reading to
            pid_t = pid;
            pid = fork();
            if(pid < 0){ //failed
                cout << "ERROR: Cannot create a secondary process" << endl;
                exit(2);
            }
            else if(pid == 0){ //child
                //open a channel to parent
                //execute the command
                //die
            }
            else{ //parent
                //get the file reference prepped
                //wait
                //take the data from child
                //write it to the file
            }
        }
        else if(stdInRead(line)>-1){
            //command -> child -> execvp
            //handle reading from
            pid_t = pid;
            pid = fork();
            if(pid < 0){ //failed
                cout << "ERROR: Cannot create a secondary process" << endl;
                exit(2);
            }
            else if(pid == 0){ //child
                //set pipe to parent
                //wait
                //take data from parent
                //run command
            }
            else{ //parent
                //get reference to file
                //get info
                // pass to child
                //wait
                //read from child and print to screen?????
            }

        }
        else if(stdHasPipe(line)>-1){
            //command -> child -> execvp
            //handle pipe
            pid_t = pid;
            pid = fork();
            if(pid < 0){ //failed
                cout << "ERROR: Cannot create a secondary process" << endl;
                exit(2);
            }
            else if(pid == 0){ //child
                //???????????????
                //execute the command
                //???????????????
            }
            else{ //parent
                //???????????????
                //wait
                //???????????????
            }
        }
        else{
            //child -> execvp()
            //handle single argument
            pid_t = pid;
            pid = fork();
            if(pid < 0){ //failed
                cout << "ERROR: Cannot create a secondary process" << endl;
                exit(2);
            }
            else if(pid == 0){ //child
                //execute command
            }
            else{ //parent
                //wait
            }
        }

    }

	return 0;
}