#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//SERIAL DOWNLOADER

int main()
{
    /* The Input File */
    ifstream inFile;
    string input;
    string url;
    inFile.open("urls.txt");

    if(inFile.is_open())
      cout << "URL file opened sucessfully ..." << endl;
    else
      {
          cout << "ERROR: could not open file" << endl;
          exit(0);
      }
    /* The command buffer */
    string cmdBuff;

    /* The ID of the child process */
    pid_t childPid;

    /* Keep running until the user has typed "exit" */
    do
    {
        /* Prompt the user to enter the command */
        cerr << "cmd>";
        cin >> cmdBuff;

        /* If the user wants to exit */
        if (cmdBuff != "exit")
        {
          while(inFile.is_open() && getline(inFile, url))
          {
              /* TODO: Create a child */
              childPid = fork();

              /* TODO: Error check to make sure the child was successfully created */
              if (childPid < 0)
              {
                  cout << "Fork failed";
              }
              else if (childPid == 0)
              {
                  cout << "\n\nThis is a child process with PID " << getpid() << endl;
                  cout << "Child process was successfully created" << endl;
                  cout << "URL read and passed: " << url << endl;
                    execlp("/usr/bin/wget", "wget", url, NULL);
              }


            /*** TODO: If I am child, I will do this: ****/
        /* Call execlp() to replace my program with that specified at the command line.
    * PLEASE NOTE: YOU CANNOT PASS cmdBuff DIRECTLY to execlp(). It is because
            * cmdBuff is an object of type string (i.e., a class) and execlp() expects
        * an array of characters.  However, you can pass cmdBuff.c_str(), which will
            * return an array of characters representation of the string object.
            *
            * Also, please do not forget to error check your exelp() system calls.
            */


            /*** TODO: If I am a parent, I will do the following ***?
            /* Wait for the child process to terminate */

              else
              {
                wait(NULL);
                cout << "Child complete" << endl;
              }
          }
           inFile.close();
           cout << "Data file closed ..." << endl;
        }

    } while (cmdBuff != "exit");



    return 0;
}
