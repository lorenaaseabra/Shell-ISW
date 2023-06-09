## Shell Code in C
This repository contains a shell code implemented in C. The shell code provides a simple command-line interface that allows you to execute commands sequentially or in parallel.

## How to Use
To use the shell code, follow these steps:

1. Clone this repository to your local environment:

```
git clone https://github.com/lorenaaseabra/Shell-ISW.git
```
2. Navigate to the cloned repository:

```
cd Shell-ISW
```

3. Compile the C code:
```
gcc shell_code.c -o shell_code
```

4. Run the compiled program:

```./shell_code
```

## Features
### Sequential and Parallel Execution
The shell code supports two execution styles: sequential and parallel. In the sequential style, commands are executed one after another, waiting for each command to finish before executing the next. In the parallel style, commands are executed concurrently in separate processes.

To switch between the styles, you can use the following commands:

* style sequential: Switches the execution style to sequential.
* style parallel: Switches the execution style to parallel.

## Command Execution
You can enter commands to be executed in the shell. The shell will parse the commands and execute them accordingly based on the current execution style.

Example:
```
lmvs seq> ls -l
```
This command will execute the ls -l command sequentially.

Batch Mode
The shell code also supports batch mode execution. You can provide a batch file containing multiple commands, and the shell will execute them sequentially or in parallel based on the chosen style.

To execute commands from a batch file, use the following command:

```
batch filename
```
Replace filename with the path to your batch file.

## Contributing
Contributions to this repository are welcome. If you would like to contribute, please follow these steps:

Fork this repository to your own GitHub account.

Create a new branch for your feature or bug fix:

```
git checkout -b new-feature
```
Make your desired changes and commit them:

```
git commit -m "Add new feature"
```
Push your changes to your remote repository:

```
git push origin new-feature
```
Open a pull request in this repository, describing your proposed changes.

## License
This repository is licensed under the MIT License. Feel free to use, modify, and distribute the code as needed.
