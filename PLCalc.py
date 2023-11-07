# Propositional Logic Calculator

from PropositionalLogic import *

# calc = PropositionalLogic.Propositional_Logic()
A = gen_table(2)
Ans = []
def showit():
    for i in range(len(A)):
        print(A[i] + [Ans[i]])

for i in range(len(A)):
    Ans.append(
        ior(A[0], And(A[0], A[1]))
    )

showit()