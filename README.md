# Order Processing Application

This is an order processing application created for
the ECM2433 coursework 2 assignment.

## Contents
 
 * [Compilation](#Compilation)
 * [Functionality](#Functionality)
 * [Output](#Output)

## Compilation

In order to compile the application, you can run the `compileOP` file:

```bash
$ cd folder-name
$ ./compileOP
```

This will then create an executable called `ordering`.

## Functionality

In order to run the application, you can run the following command:

```bash
$ ./ordering [inputFile]
```

As an example of the format of the input file, I have included `testInputFile.txt`

## Output

The program will output all of the required information to the terminal.

If needing to output this into a file, do the following:

```bash
$ ./ordering testInputFile.txt > output.log 2> error.log
```
