# Problem 1: _Moneygrubbers_

### The problem

You want buy to apples, so you go to an apple store. The store has a price for buying one apple - for example, $1.75.
The store also has m pricing schemes, where each pricing scheme gives a number _**n**_ and a price _**p**_ for buying
_**n**_ apples. For example, one pricing scheme might state that three apples cost a total $4.00; another might state
that two apples cost a total of $2.50. You want buy _**at least k**_ apples and to do so as cheaply as possible.

---
#### Input
We read test cases until there's no more input. Each test case consists of the following lines:
- A line containing the price for buying one apple, followed by the number _**m**_ of pricing schemes for this test
case. _**m**_ is at most 20.
- _**m**_ lines, each of which gives a number _**n**_ and total price _**p**_ for buying _**n**_ apples. _**n**_ is
between 1 and 100. 
- A line containing integers, where each integer _**k**_ is between 0 and 100 and gives the desired number of apples to
buy.

Each prince in the input is a floating-point number with exactly two decimal digits.  
&nbsp;&nbsp; In the problem description, I gave the price of one apple as $1.75. I also gave two pricing schemes: three
apples for $4.00 and two apples for $2.50. Suppose we wanted to determine the minimum price for buying at least one
apple and at least four apples, respectively. Here's the input for this test case:  

```
1.75 2
3 4.00
2 2.50
1 4
```

---
#### Output
For each test case, output the following:
- A line containing Case `c`:, where `c` is the number of the test case starting at 1.
- For each integer `k`, a line containing Buy `k` for `$d`, where `d` is the cheapest way that we can buy at least `k`
apples.

Here's the output for the above sample input:
```
Case 1:
Buy 1 for $1.75
Buy 4 for $5.00
```