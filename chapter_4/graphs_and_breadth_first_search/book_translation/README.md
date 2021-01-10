# Problem 3: _Book Translation_

### The problem

You've written a new book in English, and you want to get the book translated into _**n**_ other target languages.
You've found _**m**_ translators. Each translators knows how to translate between two languages and will do the
translation at a given cost. For example, a translator may know how to translate between Spanish and Bengali at a cost
of $18,000; this means that you could ask this translator to translate from Spanish to Bengali for $18,000 or Bengali to
Spanish for $18,000.  
&nbsp;&nbsp; To reach a given target language may require multiple translators. For example, you may want to translate
your book from English to Bengali but have no translator between these two languages. You might instead have to
translate from English to Spanish and then Spanish to Bengali.  
&nbsp;&nbsp; To reduce the number of translation errors, you will minimize the number of translations needed to reach
each target language. If there are multiple ways to achieve a minimum number of translations to a target language, then
you will choose the cheapest one. Your goal is to minimize the number of translations to each target language; if there
are multiple ways to do this, choose the one with minimum total cost. 

---
#### Input
The input contains one test case, consisting of the following lines:
- A line containing two integers _**n**_ and _**m**_. _**n**_ is the number of target languages; _**m**_ is the number
of translators. These are at most 100 target languages and at most 4,500 translators.
- A line containing _**n**_ strings, each naming a target language. English will not be a target language.
- _**m**_ lines, each giving information for one translator. Each of these lines contains three space-separated tokens:
a language, a second language, and the positive integer cost to translate between them. There is at most one translator
per pair of languages

---
#### Output
Output the minimum monetary cost to translate the book into all of the target languages, while minimizing the number of
translations to each target language. if there is no way to translate the book into all of the target languages, output
_Impossible_.
