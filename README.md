# Typoitory a writing speed test.
Typoiotry is a command line application that helps you track and improve your typing speed. Unlike many typing speed programs Typoitory utilizes a real list of words. Which means that you are testing your typing speed with real words, not just using 300 most common words.


## Requairments
The program was tested and written in a linux environment and compiled using Clang. I don't know if you can run it somewhere else. If you end up using some other compiler other than Clang make sure to change the syntax accordingly.

To run this you need: 
* CLI (command line interface) 
* C compiler (like clang)

## Setup
To run the application open the terminal, cd to the directory and giving you use clang on linux, run:

```bash
clang typoitory.c -o typoitory
```
If don't have clang here is a guide: [https://clang.llvm.org/get_started.html](https://clang.llvm.org/get_started.html)

`typoitory.c` is the source code.

`typoitory` will be the executable that you will be turn.

## Usage
When you run the program `./typoitory`, you will be prompted to input words. It worth mentioning that the more words you have the more correct it will be. 20 or 30 is fair amount.

After you choose the amount of words, input the exact words that are showing on the screen. Every character has to be exactly equal to the prompted word.

At the end, when you typed all the words, you will see the results.

## Improvements
There are many improvements which can be made. Here are some of them:
- If the input is over 50 chars, the program will result in a segmentation fault (it will crash). 
- There is no timeout for inactivity, if the user goes away from screen the timer will continue on counting.

The program is simple but for a reason. Its purpose other than improving my typing speed, is to give a general overview of how a low level language works. Nothing is implemented for you, instead you have to implement everything on your own. There are no pre-built sorting, search algorithms. FOR loops and IF statements are your only option.

## Credit
The words in the dictionary file are from this [repo](https://github.com/first20hours/google-10000-english)