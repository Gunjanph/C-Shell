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
	
	a. Changes directory to directory given
	b. Implemented in cd.c

2. pwd : `pwd`
	
	a. Prints the working directory
	b. Implemented in pwd.c

3. ls : `ls [-l -a] [directory]`

	a. Prints all the file of the specific directory
	b. ls, ls. , ls .. , ls ~ also works.
	c. Also works for multiple directories. 
	d. Implemented in ls.c

4. echo : `echo [arguments]`

	a. Print arguments taking care of spaces
	b. Doesn't account double quotes
	c. Implemented in echo.c

5. pinfo : `pinfo [PID]`
	
	a. With no arguments, it will print details of running command
	b. Print details of particular PID.
	c. Implemented in pinfo.c

6. setenv : `setenv [var] [value]`

	a. Sets an environment variable named var to value.
	b. Creats if there is no variable named var.
	c. Implemented in envvar.c

7. unsetenv : `unsetenv [var]`

	a. Unsets or removes an environment variable named var.
	b. Implemented in envvar.c

8. jobs : `jobs`

	a. Prints all the currently running background processes with their pid and state(running or stopped).
	b. Implemented in jobs.c

9. kjob : `kjob [job no.] [signal no.]`

	a. Sends the signal value of signal no. to job no.
	b. Implemented in kjob.c

10. fg : `fg [job no.]`

	a. Brings the background process with job no. to foreground.
	b. Implemented in fg.c

11. bg : `bg [job no.]`

	a. Changes the state of stopped background process with job no. to running.
	b. Implemented in bg.c

12. Overkill : `overkill`

	a. kills all the background processes.
	b. Implemented in overkill.c


### Foreground and Background Processes

1. All other commands are treated as foreground process.
2. For background Process, there should be '&' at end of command.
3. Upon termination of a background process, the shell prints its PID with (number of processes-1) running in background.
4. foreground is implemented in foreground.c and background implemented in background.c

### Piping and Redirection

1. Redirection

	a. Handles `<`, `>`, `>>`.
	b. `>>` appends whereas `.` overwrites the outfile file and `<` takes input from file.
	c. Print errors whenever required.
	d. Implemented in redirection.c

2. Piping
	
	a. Handles `|`.
	b. Print errors whenever required.
	c. Implemented in piping.c

Piping and redirection both can be implemented together too.

### Signal Handling

1. CTRL-Z

	a. Push currently running foreground to background.
	b. Implemented in signal_handler.c

2. CTRL-C

	a. Interrupts currently running foreground process by signal SIGINT.
	b. Implemented in signal_handler.c

### Bonus

1. history : `history [num]`
	
	a. Prints last num commands.
	b. If no arguments are given, it prints last 10 commands.
	c. It stores last 20 command only. If num>20, it will give error.
	d. Implemented in history.c

2. nightswatch : `nightswatch -n [seconds] [newborn/interrupt]`

	a. `interrupt` argument prints the number of times CPU has been interrupted by keyboard.
	b. `newborn` argument prints the neborn PIDs
	c. Executes every `n` number of seconds as specified by user.
	d. Exit when `q` is pressed.

3. cd : `cd -`
	
	a. Prints last working directory
	b. Make present working directory equals to last working directory.
	c. Implemented in cd.c

4. Exit Codes:

	a. Prints a sad face before prompt when an error occurs
	b. Prints a happy face before prompt when there is no error.

## Exiting The Shell

1. quit : `quit`
2. ctrl + d

Either of the command will exit the shell XD
