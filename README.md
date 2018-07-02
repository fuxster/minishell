# Minishell

## About

Through the Minishell project, I got to the core of the Unix system and explored 
an important part of this system’s API: process creation and synchronisation.

Besides the basic functionality of a shell (management of the environment and 
the command interpreter), I had to implement this series of builtins:
```
cd, echo, setenv, unsetenv, env and exit.
```
## Installation & Usage

### Requirements
The only requirements are:
- GNU make 
- GCC

### Building the program

1. Download/Clone this repo

        git clone https://github.com/retskcuf/minishell
2. `cd` into the root directory and run `make`

        cd minishell
        make

### Running the program

After building the source, run `./minishell` from the project root.
