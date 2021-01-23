# Problem 1: _Burger Fervor_

### The problem

A man named Homer Simpson likes to eat and drink. He has _**t**_ minutes that he'll spend eating burgers and drinking
beer. There are two kind of burgers. One of them takes _**m**_ minutes to eat, and other takes _**n**_ minutes to eat.
&nbsp;&nbsp; Homer likes burgers more than beer, so he'd like to spend the entire _**t**_ minutes eating burgers.
However, doing so isn't always possible. For example, if `m = 4`, `n = 9`, and `t = 15`, then no combination of the
4-minute and 9-minute burgers can take 15 minutes to eat. If that's the case, he'll spend as much time as possible
eating burgers and then fill the rest of the time drinking beer. Our task is to determine the number of burgers that
Homer can eat.

---
#### Input
We read test cases until there is no more input. Each test case is represented by a line of three integers: _**m**_, the
number of minutes it takes to each the first kind of burger; _**n**_, the number of minutes it takes to eat the second
kind of burger; and _**t**_, the number of minutes that Homer will spend eating burgers and drinking beer. Each _**m**_,
_**n**_, and _**t**_ value is less than 10,000.

---
#### Output
For each test case:
- If Homer can spend exactly _**t**_ minutes eating burgers, then output the maximum number of burgers that he can eat.
- Otherwise, output the maximum number og burgers that Homer can eat when maximizing his time eating burgers, a space,
and the number of remaining minutes (during which he'll drink beer).
