# domletters — count dominant letters
Mohamed-Amin Cheaito and Bart Massey 2021

This repository contains a program that counts dominant
letters in alphabetic words of an ASCII text read from
standard input, printing the total count on standard output.

An "alphabetic word" is any sequence of one or more
ASCII letters (`a`-`z` and/or `A`-`Z`) surrounded by
whitespace. For example

    This isn't an "incomplete sentence". Really
    not.

contains just three words: `This`, `an` and `Really`.

The "dominant letter count" of a word is the maximum number of
times that a given letter appears in the word, treating
upper and lowercase letters as equivalent. Examples:

* The dominant letter count of `any` is 1, since the most any
  letter appears is once.

* The dominant letter count of `bookkeeper` is 3, since `e`
  appears three times.

* The dominant letter count of `Arable` is 2, since `a`
  appears twice (once uppercase, once lowercase).

## Build and Run

To build the program, type `make`. This will use the file
named `Makefile` to compile the program.

To run the program once it is built, say

    ./domletters <input.txt

where `input.txt` is the input file to be processed.

## Example

When run using the file `sentence.txt` in this distribution,
the program will produce a dominant letter count of 20. When
run on `swift.txt` it will produce 71.

## Acknowledgements

Thanks to [Project Gutenberg](http://gutenberg.org) for the
text of
[Tom Swift and His Airship](https://www.gutenberg.org/cache/epub/3005/pg3005.txt),
from which the file `swift.txt` in this distribution was
taken.

I couldn't recall how to read a text file from standard input, so I had to use
[stack overflow](https://stackoverflow.com/questions/25985639/passing-text-file-to-standard-input).
Mentioned within program.

## Brief Explanation of Solution

The main gist of my solution is that I go through each letter within the file
and once I reach a space character I consider that as an evaluation/reset point. 


## License

This work is made available under the "MIT License". Please
see the file `LICENSE` in this distribution for license
terms.
