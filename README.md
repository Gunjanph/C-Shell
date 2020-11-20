# shell

Shell is the implementation of a shell in C language.

## Run

1. cd into the directory containing shell
2. Run "make main" or "make" command
3. Execute using command ./a.out

## Features

1. semi-colon separated commands are taken care of
2. modular fashioned coding
3. extra tabs aur spaces are taken care of.
4. error handling of all appropriate cases is taken care of.

### Commands

1. cd : `cd [directory]`
	
	- Changes directory to directory given
	- Implemented in cd.c

2. pwd : `pwd`
	
	- Prints the working directory
	- Implemented in pwd.c

3. ls : `ls [-l -a] [directory]`

	- Prints all the file of the specific directory
	- ls, ls. , ls .. , ls ~ also works.
	- Also works for multiple directories. 
	- Implemented in ls.c

4. echo : `echo [arguments]`

	- Print arguments taking care of spaces
	- Doesn't account double quotes
	- Implemented in echo.c

5. pinfo : `pinfo [PID]`
	
	- With no arguments, it will print details of running command
	- Print details of particular PID.
	- Implemented in pinfo.c

6. setenv : `setenv [var] [value]`

	- Sets an environment variable named var to value.
	- Creats if there is no variable named var.
	- Implemented in envvar.c

7. unsetenv : `unsetenv [var]`

	- Unsets or removes an environment variable named var.
	- Implemented in envvar.c

8. jobs : `jobs`

	- Prints all the currently running background processes with their pid and state(running or stopped).
	- Implemented in jobs.c

9. kjob : `kjob [job no.] [signal no.]`

	- Sends the signal value of signal no. to job no.
	- Implemented in kjob.c

10. fg : `fg [job no.]`

	- Brings the background process with job no. to foreground.
	- Implemented in fg.c

11. bg : `bg [job no.]`

	- Changes the state of stopped background process with job no. to running.
	- Implemented in bg.c

12. Overkill : `overkill`

	- kills all the background processes.
	- Implemented in overkill.c


### Foreground and Background Processes

1. All other commands are treated as foreground process.
2. For background Process, there should be '&' at end of command.
3. Upon termination of a background process, the shell prints its PID with (number of processes-1) running in background.
4. foreground is implemented in foreground.c and background implemented in background.c

### Piping and Redirection

1. Redirection

	- Handles `<`, `>`, `>>`.
	- `>>` appends whereas `.` overwrites the outfile file and `<` takes input from file.
	- Print errors whenever required.
	- Implemented in redirection.c

2. Piping
	
	- Handles `|`.
	- Print errors whenever required.
	- Implemented in piping.c

Piping and redirection both can be implemented together too.

### Signal Handling

1. CTRL-Z

	- Push currently running foreground to background.
	- Implemented in signal_handler.c

2. CTRL-C

	- Interrupts currently running foreground process by signal SIGINT.
	- Implemented in signal_handler.c

### Bonus

1. history : `history [num]`
	
	- Prints last num commands.
	- If no arguments are given, it prints last 10 commands.
	- It stores last 20 command only. If num>20, it will give error.
	- Implemented in history.c

2. nightswatch : `nightswatch -n [seconds] [newborn/interrupt]`

	- `interrupt` argument prints the number of times CPU has been interrupted by keyboard.
	- `newborn` argument prints the neborn PIDs
	- Executes every `n` number of seconds as specified by user.
	- Exit when `q` is pressed.

3. cd : `cd -`
	
	- Prints last working directory
	- Make present working directory equals to last working directory.
	- Implemented in cd.c

4. Exit Codes:

	- Prints a sad face before prompt when an error occurs
	- Prints a happy face before prompt when there is no error.

## Exiting The Shell

1. quit : `quit`
2. ctrl + d

Either of the command will exit the shell XD
