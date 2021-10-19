# CS4310 Project 03 Prioritize It

## Team members: Thomas Pickering, Nhat Tran, Celine Mangahas

## Purpose

Understand process scheduling of FreeNOS.

Get hands-on with process priority scheduling implementation.

## Task Description   

### Part 1: (20 pts) 

* [x] Add priority to the PCB class in FreeNOS. Work on a new branch called “priority” in your FreeNos repo. The (u8) PriorityLevel goes from 1 to 5 (low to high priority)

### Part 2: (10 pts) 

* [x] Change the “ps” application to display priority level of processes when you do:
       # ps –l

### Part 3: (20 pts) 

* [x]  Download the "sc" application ("slow_calcs") and put the extracted folder in "FreeNOS\bin". Write an application named “renice” in folder “FreeNOS\bin\renice”, which should work similarly to the “renice” command on Ubuntu. (“# man renice”) This directory and code within should follow the structure of “ps” application.
      Example run: (after you implement the supporting functions in FreeNOS)

      # sc 360 &    #this gives your around 1 minute running time.

      # sc 300 &   #this gives your around 0.5 minute running time.

      # ps –l #suppose the output has PID 17 for “sc 300”

      # renice –n 2 17 #tell Process 17 to be run at priority 2

      # ps –l # make sure the priority changes for “sc 300”

      # # wait to see that “sc 360” finish before “sc 300”

### Part 4: (30 pts) 

* [x] Add support in FreeNOS kernel and system libraries for priority-based scheduling. It can be a simple linear Ready Queue, or you can use the ML algorithm from Zybooks for 10 points in extra credit.

### Part 5: (10 pts) 

* [x] Record a 3-minute (approx..) screencast with your voice (facial image is optional but encouraged) and upload it to a video streaming site like Youtube. The video should include:
Introduce yourselves;
Demo run your code;
Each team member comment on your code: what did you do? Any challenges? How did you overcome them? Any new understanding or insights?
### Part 6:(10 pts) 

* [x] Submit a README.md file, listing:
Your full names;

## GitHub repo 

[GitHub repository](https://github.com/team7project1/project2.git)

https://github.com/team7project1/project2.git

## Screencast video.

[Screencast Video Part 1 - ps and renice demo](https://www.youtube.com/watch?v=SGQiS48h4UI "Youtube")

[Screencast Video Part 2 - backend implementation & renice](https://youtu.be/uBgt9taFSGA "Youtube")

[Screencast Video Part 3 - Prority Scheduler Demonstration](https://www.youtube.com/watch?v=xQ7Fjz1mh0Q "Youtube")
