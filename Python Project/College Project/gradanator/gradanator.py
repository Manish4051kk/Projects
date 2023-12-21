# Building Python Programs
# Programming Assignment Chapter 4 Gradanator Template
#
# Calculates a student's course grade based on exam and homework scores.

ATTENDANCE_PTS = 3 # points earned per section
SECTION_MAX = 34 # maximum possible section points

def main():
    print_intro()

    midterm_score = get_exam_score("Midterm 1")
    midterm_score2 = get_exam_score("Midterm 2")
    final_score = get_exam_score("Final")
    hw_score = get_homework_score()
    quizzes = get_quizzes_or_homework_score("Quizzes")
    daily_hw = get_quizzes_or_homework_score("Daily homework")
    report_grade(midterm_score + midterm_score2 + final_score +
                 hw_score + quizzes + daily_hw)


# Prints information about the program's behavior.
def print_intro():
    print("This program reads exam/homework scores")
    print("and reports your overall course grade.")
    print()

# Prompts for exam score and shift.  Returns a weightedcan
# score.
def get_exam_score(exam):

	# YOUR CODE here
    print(exam+":")
    weight=int(input("Weight (0-100)? "))
    score=int(input("Score earned? "))
    shift=int(input("Were scores shifted (1=yes, 2=no)? "))
    if shift == 1 :
        shift_score = int(input("Shift amount? "))
        score = score + shift_score 
    if score >= 100:
        score = 100
    print("Total points =" , score , "/ 100")
    print("Weighted score = ", round(get_weighted_score(score, 100, weight),1), "/ ", weight)
    print()
    return get_weighted_score(score, 100, weight)


# Prompts for homework scores and section attendance. Calculates and returns
# weighted homework score.
def get_homework_score():

	# YOUR CODE here
    print("Homework:")
    weight=int(input("Weight (0-100)? "))
    assignments=int(input("Number of assignments? "))
    scores = []
    max_scores = []
    for number_assignments in range(1,assignments+1):
        assignment_score = int(input(f"Assignment {number_assignments} score? "))
        scores += [assignment_score]
        for numberw in range (1):
            assignment_max = int(input(f"Assignment {number_assignments} max? "))
            max_scores += [assignment_max]
    Sections = int(input("How many sections do you have to attend? "))
    hw_earned = sum(scores)
    hw_total = sum(max_scores)
    section_points = Sections * ATTENDANCE_PTS
    if section_points >= SECTION_MAX:
        section_points = SECTION_MAX
    total_earned = hw_earned + section_points
    total_total = hw_total + SECTION_MAX
    if (total_earned) >= (total_total):
        total_earned = total_total
    print("Section Points = ", section_points, "/", SECTION_MAX)
    print("Total points=", total_earned, "/", total_total)
    print("Weighted score =", round(get_weighted_score(total_earned, total_total, weight),1),"/",weight)
    print()
            

    return get_weighted_score(total_earned, total_total, weight)

# ints and returns the weighted score for a category.
def get_weighted_score(earned, total, weight):

	# YOUR CODE HERE
    weighted=(earned*weight)/(total)
    return weighted


# Reports a minimum guaranteed GPA and a message about the total score earned.
def report_grade(total):

	# YOUR CODE HERE
    print("Overall percentage =", round(total,1))
    if total >= 90 :
        print("Your grade will be at least: A")
        print("Excellent")
    elif  89.99 >= total >= 80 :
        print("Your grade will be at least: B")
        print("Good performance, Work hard")
    elif 79.99 >=total >= 70 :
        print("Your grade will be at least: C")
        print("Need to practise more")
    elif 69.99 >= total >= 60 :
        print("Your grade will be at least: D")
        print("Can improve,work hard")
    else:
        print("Your grade will be at least: F")
        print("Fail practice more")
    pass


# Rounds a value to a given number of digits.
def round2(value, digits):
    return round(value * pow(10, digits)) / pow(10, digits)

# Function that need to be used for Quizzes and Daily Homework
def get_quizzes_or_homework_score(item):

	# YOUR CODE HERE
    print(item+ ":")
    weight=int(input("Weight (0-100)? "))
    points = int(input("Total points earned? "))
    points_possible = int(input("Total points possible? "))
    if points >= points_possible:
        points = points_possible
    print("Total points=",points, "/", points_possible)
    print("Weighted score =", round(get_weighted_score(min(points, points_possible), points_possible, weight),1),"/",weight)
    print()
    return get_weighted_score(min(points, points_possible), points_possible, weight)

main()
#total = 100
