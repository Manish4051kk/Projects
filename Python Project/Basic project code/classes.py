class Date:
    def __init__(self , m, d):
        self.month = m
        self.day = d

def add(a,d):
    a = a + a
    d.month = a
    print(a,d.month)

def main():
    a = 7
    b = 9
    d1 = Date(5,2)
    d2 = Date(24,2)
    print(a, b, d1.month, d2.month)
