# CS4310 Project 02 - *"Wait", don't "kill" it...*

Team members: **Thomas Pickering, Nhat Tran, Celine Mangahas**

## Purpose

Understand the structure of FreeNOS (API, system calls, traps).

“Git” ready.

Get debugging skills.

## Task Description

### Part 1: Git

* [x] Follow this [guide](https://product.hubspot.com/blog/git-and-github-tutorial-for-beginners), and make your FreeNOS-1.0.3 Folder a git repo, make its remote repo (“origin”) a new repo in your GitHub account.
* [x] Make and check out a branch named “wait”. You will be working on this branch for this project.
* [x] Add GitHub user: “2404s21” as a collaborator.

### Part 2: Write an application named “wait” in folder “FreeNOS-1.0.3\bin\wait”

* [x] It should work similarly to the wait command that comes with Ubuntu. (In your terminal, do “man wait” to learn more.) It should be able to wait for a background process (e.g. “sleep 30 &”) to finish and return.
* [x] It should follow the application code structure like the “sleep” command of FreeNOS.

### Part 3: Record a 3-minute (approx..) screencast with your voice (facial image is optional but encouraged)

* [x] Introduce yourselves;
* [x] Demo kill a process or two;
* [x] Show off your contribution to FreeNOS: what you did to get rid of the bug? What debugger did you use?

## Link to the GitHub repository

[GitHub repository](https://github.com/team7project1/project2)

## Link to the screencast video

[Screencast Video]( https://www.youtube.com/watch?v=NL24W5JA3YU&ab_channel=ThomasPickering "Youtube")

## Notes

Screencast Software & Version: nVidia Geforce Experience (Shadowplay Tool) Version 3.23.0.74


# CS4310 Project 03 Prioritize It
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

* [ ] Write an application named “renice” in folder “FreeNOS\bin\renice”, which should work similarly to the “renice” command on Ubuntu. (“# man renice”) This directory and code within should follow the structure of “sleep” application.
      Example run: (after you implement the supporting functions in FreeNOS)

      # sleep 30 &

      # sleep 45 &

      # ps –l #suppose the output has PID 17 for “sleep 30”

      # renice –n 2 17 #tell Process 17 to be run at priority 2

      # ps –l # make sure the priority changes for “sleep 30”

      # # wait to see that “sleep 45” finish before “sleep 30”

### Part 4: (30 pts) 

* [ ] Add support in FreeNOS kernel and system libraries for priority-based scheduling. It can be a simple linear Ready Queue, or you can use the ML algorithm from Zybooks for 10 points in extra credit.

### Part 5: (10 pts) 

* [ ] Record a 3-minute (approx..) screencast with your voice (facial image is optional but encouraged) and upload it to a video streaming site like Youtube. The video should include:
Introduce yourselves;
Demo run your code;
Each team member comment on your code: what did you do? Any challenges? How did you overcome them? Any new understanding or insights?
### Part 6:(10 pts) 

* [ ] Submit a README.md file, listing:
Your full names;

## The link to your GitHub repo 

[GitHub repository](https://github.com/team7project1/project2)
(you should also maintain a README.md in your GitHub repo, which is updated with information about features/branches added);

## The link to your screencast video.

[Screencast Video](  "Youtube")
