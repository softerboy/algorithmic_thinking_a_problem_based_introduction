# Problem 1: _Unique Snowflakes_

### The problem

We're given a collection of snowflakes, and we have to determine whether any of the snowflakes in the collection are
identical.  
&nbsp;&nbsp; A snowflake is represented by six integers, where each integer gives the length of one the snowflake's
arms. For example, this is a snowflake:  
`3, 9, 15, 2, 1, 10`  
&nbsp;&nbsp; Snowflakes can also repeated integers, such as  
`8, 4, 8, 9, 2, 8`  
&nbsp;&nbsp; What does it mean for two snowflakes to be identical? Let's work up to that definition through a few
examples.  
&nbsp;&nbsp; First we'll look at these two snowflakes:  
`1, 2, 3, 4, 5, 6`  
and  
`1, 2, 3, 4, 5, 6`  
&nbsp;&nbsp; These are clearly identical because the integers in one snowflake match the integers in their corresponding
positions in the other snowflake.  
&nbsp;&nbsp; Here's our second example:  
`1, 2, 3, 4, 5, 6`  
and  
`4, 5, 6, 1, 2, 3`  
&nbsp;&nbsp; These are also identical. We can see this by starting at the 1 in the second snowflake and moving right. We
see the integers 1, 2, and 3 and then, wrapping around to the left, we see 4, 5, and 6. These two pieces together give
us the first snowflake.  
&nbsp;&nbsp; Let's try a trickier example:  
`1, 2, 3, 4, 5, 6`  
and  
`3, 2, 1, 6, 5, 4`  
&nbsp;&nbsp; From what we've seen so far, we would deduce that these are not identical. If we start with the 1 in the
second snowflake and move right (wrapping around to the left when we hit the right end), we get `1, 6, 5, 4, 3, 2`.
That's not even close to the `1, 2, 3, 4, 5, 6` in the first snowflake.  
&nbsp;&nbsp; However, if we begin at the 1 in the second snowflake and move left instead of right, then we do get
exactly `1, 2, 3, 4, 5, 6`! Moving left from the 1 gives us `1, 2, 3`, and wrapping around to the right, we can proceed
leftward to collect `4, 5, 6`.  
&nbsp;&nbsp; That's our third way for two snowflakes to be identical: two snowflakes are called identical if they match
when we move leftward through the numbers.  
&nbsp;&nbsp; Putting it all together, we can conclude that two snowflakes are identical if they are the same, if we can
make them the same by moving rightward through one of the snowflakes, or if we can make them the same by moving leftward
through one of the snowflakes.

---
#### Input
The first line of input is an integer _**n**_, which gives the number of snowflakes that we'll be processing. The value
_**n**_ will be between 1 and 100,000. Each of the following _**n**_ lines represents one snowflake: each line has six
integers, where each integer is at least zero and at most 10,000,000

---
#### Output
Our output will be a single line of text:
- If there are no identical snowflakes, print exactly  
`No two snowflakes are alike`.
- If there are at least two identical snowflakes, print exactly  
`Twin snowflakes found`.
