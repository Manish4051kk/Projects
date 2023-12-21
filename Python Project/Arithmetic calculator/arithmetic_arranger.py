def arithmetic_arranger(problems, *args):
    if len(problems) > 5:
        return "Error: Too many problems."

    arranged_problems = []

    for index, value in enumerate(problems):
        # ["32", "+", "8"]
        operation = value.split(" ")

        if operation[1] not in "-+":
            return "Error: Operator must be '+' or '-'."

        if len(operation[0]) > 4 or len(operation[2]) > 4:
            return "Error: Numbers cannot be more than four digits."
        
        try:
            value_1 = int(operation[0])
            value_2 = int(operation[2])
        except ValueError:
            return "Error: Numbers must only contain digits."


        # calculate the length of each line
        longest_val = max(len(operation[0]), len(operation[2]))
        width = longest_val + 2

        # operation = ["32", "+", "8"]
        # output = f"{operation[0]:>{width}}\n{f'{operation[1]} {operation[2]}':>{width}}\n{'-'*width}"

        L1 = f"{operation[0]:>{width}}"
        L2 = operation[1] + f"{operation[2]:>{width-1}}"
        d = '-' * width
        

        try:
          arranged_problems[0] += (' ' * 4) + L1
        except IndexError:
          arranged_problems.append(L1)

        try:
          arranged_problems[1] += (' ' * 4) + L2
        except IndexError:
          arranged_problems.append(L2)

        try:
          arranged_problems[2] += (' ' * 4) + d
        except IndexError:
          arranged_problems.append(d)


        if args:
          """
          This runs if the second parameter True is passed in denoting we need to calculate the answer value.
          """
          ans = int(operation[0]) + int(operation[2]) if operation[1] == '+' else int(operation[0]) - int(operation[2])
          a = f"{str(ans):>{width}}"

          try:
            arranged_problems[3] += (' ' * 4) + a
          except IndexError:
            arranged_problems.append(a)


    output = f"{arranged_problems[0]}\n{arranged_problems[1]}\n{arranged_problems[2]}"
    output = output + f"\n{arranged_problems[3]}" if args else output

    return output



# print(arithmetic_arranger(["3 + 855", "3801 - 2", "45 + 43", "123 + 49"]))

# print("    3      3801      45      123\n+ 855    -    2    + 43    +  49\n-----    ------    ----    -----")

# print(arithmetic_arranger(["32 - 698", "1 - 3801", "45 + 43", "123 + 49"], True))

# print("   32         1      45      123\n- 698    - 3801    + 43    +  49\n-----    ------    ----    -----\n -666     -3800      88      172")
