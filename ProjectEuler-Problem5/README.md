#ProjectEuler-Problem5

Solution to the fifth problem on ProjectEuler (https://projecteuler.net/problem=5)

"Smallest Multiple:

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?"

#Solutions

Problem5a - (my) original solution. Solution first eliminates all numbers that are factors of other numbers in the list (1-20). e.g. 2 is ignored in the calculation of the answer as it is a factor of 20 and thus, pointless to include.

Problem5b - alternative solution. Takes into account all numbers from 1-20 in calculation of answer. Better readibility and less redundant code.
