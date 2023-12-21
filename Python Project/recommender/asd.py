def main():
    print("Welcome to the CS110 Book Recommender. Type the word in the")
    print("left column to do the action on the right.")
    print("recommend : recommend books for a particular user")
    print("averages  : output the average ratings of all books in the system")
    print("quit      : exit the program")
    task()


def read_file():
    with open("ratings-small.txt") as f:
        lines = f.read().splitlines()
    books = list(set(lines[1::3]))
    users = set(lines[::3])
    ratings = {}

    for i in range(0, len(lines), 3):
        user = lines[i]
        book = lines[i + 1]
        rating = int(lines[i + 2].replace(" ", ""))

        if user not in ratings:
            ratings[user] = [0] * len(books)

        book_index = books.index(book)
        ratings[user][book_index] = rating

    return books, users, ratings


def recommend(user, books, users, ratings):
    if user not in ratings:
        return []

    similarities = []
    for other_user in users:
        if other_user != user:
            common_books = [i for i in range(len(books)) if ratings[user][i] != 0 and ratings[other_user][i] != 0]
            if len(common_books) == 0:
                continue

            similarity = sum(ratings[user][i] * ratings[other_user][i] for i in common_books)
            similarities.append((similarity, other_user))

    similarities.sort(reverse=True)
    top_similar_users = similarities[:3]

    recommended_books = []
    for i in range(len(books)):
        if ratings[user][i] == 0:
            total_rating = 0
            count = 0
            for similarity, other_user in top_similar_users:
                if ratings[other_user][i] != 0:
                    total_rating += ratings[other_user][i]
                    count += 1
            if count > 0:
                average_rating = total_rating / count
                recommended_books.append((average_rating, books[i]))

    recommended_books.sort(reverse=True)
    return recommended_books



def average(books, ratings):
    averages = [(sum(ratings[user][i] for user in ratings) / len([user for user in ratings if ratings[user][i] != 0]),
                 books[i]) for i in range(len(books))]
    averages.sort(reverse=True)
    for avg, book in averages:
        print(f"{book} {avg}")
    print()


def task():
    books, users, ratings = read_file()

    while True:
        next_task = input("next task? ")
        if next_task == "quit":
            break
        elif next_task == "recommend":
            user = input("user? ")
            recommendations = recommend(user, books, users, ratings)
            for avg, book in recommendations:
                print(f"{book} {avg}")
            print()
        elif next_task == "averages":
            average(books, ratings)


if __name__ == "__main__":
    main()
