# Serial & Parallel Downloaders
# Team: Adam Gemperline & Victoria Tran

This program is to demonstrate our knowledge of serial and parallel downloaders. 

# QUESTIONS
1.) In the output of time what is the difference between real, user, and sys times?

2.) Which is longer: user time or sys time? Use your knowledge to explain why.

3.) When downloading the files above, which downloader finishes faster? Why do you think that is?

4.) Repeat the experiment for 10 files (any reasonably large-sized files, eg 100MB)  
 Is the downloader in the previous question still faster? If not so, why do you think  that is?
  

# ABOUT THE PROJECT
The *serial downloader* downloads files one at a time from the internet.
Upon receiving the "wget" command from the user, this program will execute a series of downloading processes by forking parent processes to create child processes. 
Each child process will read the next URL from a text file, and subsequently download the URL file.
Each parent process will wait for its child process to complete and terminate before the parent may terminate. 
The download processes will occur one-at-a-time, and the program will terminate after all downloads are complete.

On the other hand, the *parallel downloader* downloads multiple files at the same time.
After receiving the "wget" command from the user, the parent process forks as many child processes as there are urls in the text. 
Each child process would read and download a distinct url. 
The parent processes will wait for all of the children processes to complete and terminate.
