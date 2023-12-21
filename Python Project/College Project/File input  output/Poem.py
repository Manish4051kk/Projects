def main():
    with open("poem.txt") as file:
##        line_count = 0
##        for x in file:
##            print("next line:", x)
##            line_count += 1
##    print("Line count:", line_count)
        file.seek(1)
        text = file.read()
        print(text)

main()
