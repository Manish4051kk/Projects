import math as m
def quadratic(a,b,c):
    s = b*b
    root = s - 4*a*c
    r = m.sqrt(root)
    root_1 = float((-b+r)/(2*a))
    root_2 = float((-b-r)/(2*a))
    
    print("First root =",root_1)
    print("Second root =",root_2)





