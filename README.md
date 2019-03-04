# Serial & Parallel Downloaders
# Team: Adam Gemperline & Victoria Tran

This program is to demonstrate our knowledge of serial and parallel downloaders. 

# QUESTIONS
1.) In the output of time what is the difference between real, user, and sys times?
 - *real* time is the total elapsed time including time slices used by other processes and time the process spends blocked.
       Typically the time we view on the clock.
   *user* time is the CPU time spent in user-mode code (outside the kernel). User time is the only CPU time used in executing the process. 
   *sys* time is the amount of CPU time spent in the kernel. This means executing CPU time spent in system calls within the kernel, as   
      opposed to library code, which is still running in user-space.

2.) Which is longer: user time or sys time? Use your knowledge to explain why.
 - Generally, user time is longer than sys time. However, there are certain circumstances in which sys time is longer. 
 
3.) When downloading the files above, which downloader finishes faster? Why do you think that is?
 - As we ran the time program on the command line, we concluded that the parallel downloader finishes faster.  
 - The parallel downloader completes all downloads in a quicker fashion because of its multi-process application and use of parallelism. The program has the ability to simultaneously execute processes, whereas the serial downloader has concurrency, but not parallelism.


4.) Repeat the experiment for 10 files (any reasonably large-sized files, eg 100MB)  
 Is the downloader in the previous question still faster? If not so, why do you think  that is?
 - Yes the parallel downloader is still much faster as it utilizes parallelism and executes multiple processes simultaneously.

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
