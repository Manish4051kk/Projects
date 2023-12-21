
def main():

    data = process_data('ratings-small.txt') # ratings.txt
    book_set = data[0]
    dict_data = data[1]
    print_intro(book_set, dict_data)

def print_intro(book_set, dict_data):
    
    print('Welcome to the CSC110 Book Recommender! Type the command in the \n'
          'left column to do the action on the right:\n')
    print('recommend : recommend books for a particular user')
    print('averages  : output the average ratings of all books in the system')
    print('quit      : exit the program \n')

    task = (input("next task? ")).lower()
    user = (input("user? ")).lower()
    print()
    
    if task == 'recommend':
        if user in dict_data:
            recommend(book_set, dict_data, user)
        else:
            averages(book_set, dict_data)
    elif task == 'averages':
        averages(book_set, dict_data)
    elif task == 'quit':
        exit()

def process_data(file_name):
    
    ratings_file = open(file_name, "r")
    
    data = []
    
    user_list = []
    book_list = []
    rating_list = []
    
    dict_data = {}
    
    for line in ratings_file:
        line = line.strip().lower()
        data.append(line)

    num_details = len(data)//3
    i = 1
    
    for i in range(0, num_details):
        user = data[0+(3*i)] # get the current user
        user_list.append(user) # add to user_list
    
    for i in range(0, num_details):
        book = data[1+(3*i)] # get the current book
        book_list.append(book) # add to book_list

    for i in range(0, num_details):
        rating = data[2+(3*i)] # get the curret rating
        rating_list.append(rating) # add to rating_list

    user_set = set(user_list) 
    book_set = set(book_list)
    
    # print(data, "\n")
    # print("book_set:", book_set, "\n")
    
    for user in user_set:
        user_ratings_list = []
        
        for book in book_set:
            rating = []

            index_list = []
            for i in range(len(book_list)):
                if(book_list[i] == book):
                    index_list.append(i)

            for i in index_list:                
                if user_list[i] == user:
                    rating.append(int(rating_list[i]))
                else:
                    rating.append(0)
            user_ratings_list.append(sum(rating))
        dict_data[user] = user_ratings_list

    data = [book_set, dict_data]
    
    return data
    
def recommend(book_set, dict_data, user):
    
    #if user
    # else user not in dict_data, output = (averages(book_set, dict_data))
    
    print_intro(book_set, dict_data)
    
def averages(book_set, dict_data):

    book_set = list(book_set)
    
    for book in book_set:
        book_ratings = []
        index = book_set.index(book)
        
        for i in dict_data:
            data = dict_data[i]
            if data[index] != 0:
                book_ratings.append(data[index])
                
        print(f'{book}: {(sum(book_ratings))/len(book_ratings)}')
    print()
    
    print_intro(book_set, dict_data)

main()



