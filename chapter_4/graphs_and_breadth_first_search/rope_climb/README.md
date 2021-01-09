# Problem 2: _Rope Climb_

### The problem

Bob is forced to climb a rope in gym class. The rope is infinitely long, but Bob is being asked to get only to a height
of at least _**h**_ meters.  
&nbsp;&nbsp; Bob starts at a height of 0. He knows how to jump up by exactly _**j**_ meters, but that's the only jump he
knows to do - so if _**j**_ is 5, then he can't jump up four or six meters or any other number of meters except five. In
addition, Bob knows how to fall, and he can fall any number of meters: one, two, three, and so on.  
&nbsp;&nbsp; Each jump or fall counts as one move. For example, if Bob jumps up five meters, falls down two meters,
jumps up five meters, and falls down eight meters, then Bob will have made four moves.  
&nbsp;&nbsp; Now here's the fun part: Alice has spread itching powder on some segments of the rope. if such segment goes
from height _a_ to height _b_, then the entire segment from _a_ to _b_, including endpoints _a_ and _b_, has itching
powder. The effect that the itching powder has on Bob's moves is as follows:

- Bob cannot jump _j_ meters if that would land him on itching powder
- Bob cannot fall down a given number of meters if that would land on him on itching powder.  

The goal is to determine the minimum number of moves needed for Bob to get to height h or higher.

---
#### Input
The input contains one test case, consisting of the following lines:
- A line containing three integers _h_, _j_, and _n_. _h_ tells us the minimum height that Bob must reach, _j_ is the
distance that Bob can jump up, and _n_ is the number of segments on which Alice has spread itching powder. Each of these
integers is at most 1,000,000, and _j_ is at most _h_.
- _n_ lines, each of which contains two integers. The first integer gives the starting height for a segment of the rope with
itching powder; the second gives the ending height. Each of these integers is at most _h_ - 1.

---
#### Output
Output the minimum number of moves needed for Bob to reach height of _h_ or higher. If there's no way for Bob
to reach height _h_ or higher, output -1.
