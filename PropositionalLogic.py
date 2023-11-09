# Propositional Logic

# Suy ra if then
# Tuong duong equivalent
# And
# Inclusive Or
# Exclusive Or XOR
# Negation

# class Propo-sitional_Logic():
#     def __init__(self, A, B):
#         A = self.A
#         B = self.B
def if_then(A, B):
    if A == "1" and B == "0":
        return "0"
    else:
        return "1"

def equivalent(A, B):
    if A == B:
        return "1"
    else:
        return "0"

def and_pro(A, B):
    if A == "1" and B == "1":
        return "1"
    else:
        return "0"

def ior(A, B):
    if A == "1" or B == "1":
        return "1"
    else:
        return "0"

def xor(A, B):
    if (A == "0" or B == "1") and (A == "1" or B == "0"):
        return "1"
    else:
        return "0"

def negate(A):
    if A == "1":
        return "0"
    else:
        return "1"
    
def addition(A, B):
    C = []
    for i in A:
        for j in B:
            C.append(i + j)
    return C

def gen_table(variables = "2"):
    A = ["1", "0"]
    C = [""]
    for i in range(variables):
        C = addition(C, A)
    return [[i for i in li] for li in C]

# if_then = it
it = if_then
# equivalent = eq
eq = equivalent
# and_pro = And
And = and_pro
# ior = ior
# xor = xor
# negate = ne
ne = negate

