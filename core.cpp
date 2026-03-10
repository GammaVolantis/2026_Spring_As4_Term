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
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

using namespace std;


//Need the code from As3 for vector parsing

vector<string> tokenize(string str) {

    stringstream token(str);
    string word;
    vector<string> tokens;
    while (token >> word) {
        tokens.push_back(word);
    }

    return tokens;
}

// Adds user input into log
void addToHistory(string data){
    // open or (if not made yet) make the file.

    //send the data to the file

    //close file

    //end
}

int stdOutRead(vector<string> line){
    int index = -1;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == ">") {
            index = i;
            break;
        }
    }
    return index;
}

int stdInRead(vector<string> line){
    int index = -1;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == "<") {
            index = i;
            break;
        }
    }
    return index;
}

int hasPipe(vector<string> line){
    int index = -1;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == "|") {
            index = i;
            break;
        }
    }
    return index;
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
        char* cmdLine;
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
        vector<string> command = tokenize(line);
        else if(stdOutRead(command)>-1){
            //command -> child -> execvp
            //handle reading to
            int orgOut = dup(1);
            cmdLine = new char[stdOutRead(command)];
            for (int i = 0; i < stdOutRead(command); ++i) {
                cmdLine[i] = (char*)commands[i].c_str();
            }
            pid_t pid;
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
        else if(stdInRead(command)>-1){
            //command -> child -> execvp
            //handle reading from
            pid_t pid;
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
        else if(stdHasPipe(command)>-1){
            int pipeLoc = stdHasPipe(command);
            vector<string> firstCommand;
            vector<string> secondCommand;

            for(int i = 0; i<pipeLoc; i++){
                firstCommand.push_back(command[i]);
            }
            char* firstComPrepped[firstCommand.size()+1];
            for(int i = 0; i<firstCommand.size(); i++){
                firstComPrepped[i] = firstCommand[i].c_str();
            }
            firstComPrepped[firstCommand.size()] = NULL;

            for(int i = pipeLoc+1; i < command.size(); i++){
                secondCommand.push_back(command[i]);
            }
            char* secondComPrepped[secondCommand.size()+2];
            for(int i = 0; i<secondCommand.size(); i++){
                secondComPrepped[i] = secondCommand[i].c_str();
            }
            secondComPrepped[secondCommand.size()+1] = NULL;
            //command -> child -> execvp
            //handle pipe
            pid_t pid;
            pid = fork();
            if(pid < 0){ //failed
                cout << "ERROR: Cannot create a secondary process" << endl;
                exit(2);
            }
            else if(pid == 0){ //child
                //setup the output pipe
                dup2(toP[1], 1);
                close(toP[1]);
                close(toP[0]);
                //execute the command
                if (execvp(fisrtComPrepped[0], firstComPrepped) < 0){
                    cout << "Error: Cannot chnage the process exe image a process" << endl;
                    exit(3);
                }
            }
            else{ //parent
                //wait
                wait(0);
                //get the data from the first child

                //pass it to the second child via code inheritance
                // OR just get it when we need it from the pipe
                pid_t pid;
                pid = fork();
                if(pid < 0){ //failed
                    cout << "ERROR: Cannot create a secondary-secondary process" << endl;
                    exit(2);
                }
                else if(pid == 0){ //child
                    //execute the command
                    dup2(toP[0], 0);
                    close(toP[0]);
                    close(toP[1]);
                    //get the information from the pipe
                    string childData;
                    cin >>  childData;
                    secondComPrepped[secondCommand.size()] = childData;
                if (execvp(secondComPrepped[0], secondComPrepped) < 0){
                    cout << "Error: Cannot chnage the process exe image a process" << endl;
                    exit(3);
                }

                }
                else{ //parent
                    //wait


                }
            }
        }
        else{
            //child -> execvp()
            //handle single argument
            pid_t pid;
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
