with open("coins.txt", 'r') as file:
    file  = file.readlines()
    for line in file:
        flip = line.split()
        print(flip)
