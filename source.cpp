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
            /* TODO: Create a child */
            childPid = fork();

            /* TODO: Error check to make sure the child was successfully created */
            if (childPid < 0)
            {
                cout << "Fork failed";
            }
            if (childPid == 0)
            {
                cout << "This is a child process with PID " << getpid() << endl;
                cout << " Child process was successfully created" << endl;
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

            if (childPid == 0)
            {
                execlp("/usr/bin/wget", "wget", <URL STRING1>,NULL));
            }


            /*** TODO: If I am a parent, I will do the following ***?
            /* Wait for the child process to terminate */

            if (fork())
            {
                inFile.open("urls.txt");
                if(inFile)
                {
                    childPid= fork();
                }

                inFile.close();
                wait(NULL);
            }

        }
    } while (cmdBuff != "exit");

    return 0;
}
