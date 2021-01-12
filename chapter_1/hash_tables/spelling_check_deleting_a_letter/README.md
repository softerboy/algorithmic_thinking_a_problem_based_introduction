# Problem 3: _Spelling check: Deleting a Letter_

### The problem

In this problem, we are given two strings where the first string has one more character than second. Our task to
determine the number of ways in which on character can be deleted from the first string to arrive at the second string.
For example, there is one way to get from `favour` to `favor`: we can remove the `u` from the first string. There are
three ways to get from `abcdxxxef` to `abcdexxef`: we can remove any of the `x` characters from the string.  
&nbsp;&nbsp; The context for the problem is a spellchecker. The first string might be `bizzarre` (a misspelled word) and
the second might be `bizzare` (a correct spelling). In this case, there are two ways to fix the misspelling - by
removing either one of the two `z`s from first string. The problem is more general though, having nothing to do with
actual English words or spelling mistakes.

---
#### Input
The input is two lines, with the first string on the first line and the second string on the second line. Each string
can be up to one million characters.

---
#### Output
If there is no way to remove a character from the first string to get the second string, output `0`. Otherwise, output
two lines:
- On the first line, output the number of ways in which a character can be deleted from the first string to get the
second string.
- On the second line, output a space-separated list of the indices of the characters in the first string that can be
removed to get the second string. The problem requires we index a string from 1, not 0. (That's a bit annoying, but we
we'll be careful.)  

&nbsp;&nbsp; For example, for input:  
`abcdxxxef`  
`abcdxxef`  
we would output  
`3`  
`5 6 7`  
