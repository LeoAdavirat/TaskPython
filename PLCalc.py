# Propositional Logic Calculator

from PropositionalLogic import *

# calc = PropositionalLogic.Propositional_Logic()
A = gen_table(2)
Ans = []
def showit():
    for i in range(len(A)):
        print(A[i] + [Ans[i]])

for i in range(len(A)):
    a=A[i][0]
    b=A[i][1]
    Ans.append(
        ior(a,And(a, b))
    )


for i in range(len(A)):
    Ans.append(
        ior(A[0], And(A[0], A[1]))
    )

showit()