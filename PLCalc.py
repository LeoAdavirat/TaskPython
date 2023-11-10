# Propositional Logic Calculator

from PropositionalLogic import *

# calc = PropositionalLogic.Propositional_Logic()
# A = gen_table(2)
A = gen_table(4)
Ans = []
def showit():
    for i in range(len(A)):
        print(A[i] + [Ans[i]])

for i in range(len(A)):
    a=A[i][0]
    b=A[i][1]
    c=A[i][2]
    d=A[i][3]
    # Ans.append(
    #     ior(b, And(negate(d),c))
    # )
    Ans.append(
        And(And(eq(a,b), ior(negate(c),b)), And(negate(d),c))
    )

showit()