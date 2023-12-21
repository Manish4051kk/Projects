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

# Prompts for exam score and shift.  Returns a weighted
# score.
def get_exam_score(exam):

	# YOUR CODE here
    print(exam)
    weight = int(input("Weight (0-100)? "))
    score = int(input("Score Earned? "))
    score_shifted = int(input("Were scores shifted (1=yes, 2=no)? "))
    if score_shifted ==2:
        print("Total points = ", score,"/",100)
        weighted = print("Weighted score = ",score/10,"/",10)
    elif score_shifted ==1:
        shift = int(input("Shift amount? "))
        total = shift + score
        if total > 100 :
            total = 100
            print("Total points = ",total,"/",100)
            weighted = print("Weighted score = ",round(((total/100)*(weight/100)*100),1),"/",weight)
        else:
            if total < 100:
                print("Total points = ",total,"/",100)
                weighted = print("Weighted score = ",round(((total/100)*(weight/100)*100),1),"/",weight)

                    
    print()
    
    return get_weighted_score(score, 100, weight)


# Prompts for homework scores and section attendance. Calculates and returns
# weighted homework score.
def get_homework_score():

	# YOUR CODE here
    print("Homework:")
    weight = int(input("Weight (0-100)? "))
    num_of_assignment = int(input("Number of assignments? "))

    
    return get_weighted_score(section_points + hw_earned, hw_total + SECTION_MAX, weight)

# Calculates, prints and returns the weighted score for a category.
def get_weighted_score(earned, total, weight):

	# YOUR CODE HERE

    return weight


# Reports a minimum guaranteed GPA and a message about the total score earned.
def report_grade(total):

	# YOUR CODE HERE
    pass

# Rounds a value to a given number of digits.
def round2(value, digits):
    return round(value * pow(10, digits)) / pow(10, digits)

# Function that need to be used for Quizzes and Daily Homework
def get_quizzes_or_homework_score(item):

	# YOUR CODE HERE

    return get_weighted_score(min(points, points_possible), points_possible, weight)


main()
