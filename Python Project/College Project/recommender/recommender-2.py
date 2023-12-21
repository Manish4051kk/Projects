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

        ratings.setdefault(user, [5] * len(books))

        book_index = books.index(book)
        ratings[user][book_index] = rating

    return books, users, ratings


def recommend(user, books, users, ratings):
    if user not in ratings:
        average(books, ratings)
        return

    similarities = [
        (other_user, sum(ratings[user][i] * ratings[other_user][i] for i in range(len(books))))
        for other_user in users if other_user != user
    ]
    similarities.sort(key=lambda x: x[1], reverse=True)

    recommended_books = [0] * len(books)
    for i in range(min(3, len(similarities))):
        other_user = similarities[i][0]
        for j in range(len(books)):
            recommended_books[j] += ratings[other_user][j]

    for i in range(len(books)):
        if recommended_books[i] > 0:
            print(f"{books[i]} {recommended_books[i] / min(3, len(similarities))}")


def average(books, ratings):
    averages = [
        (sum(ratings[user][i] for user in ratings if ratings[user][i] != 0) / 
         len([user for user in ratings if ratings[user][i] != 0]), books[i])
        for i in range(len(books))
    ]
    averages.sort(key=lambda x: x[0], reverse=True)

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
            recommend(user, books, users, ratings)
            print()
        elif next_task == "averages":
            average(books, ratings)


if __name__ == "__main__":
    main()
