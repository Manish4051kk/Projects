def calculate_similarity(user1, user2):
    dot_product = sum(x * y for x, y in zip(user1, user2))
    return dot_product


def recommend_books(user_name, user_data, books):
    if user_name not in user_data:
        return []

    user_ratings = user_data[user_name]
    similarities = []

    for other_user, other_ratings in user_data.items():
        if other_user != user_name:
            similarity = calculate_similarity(user_ratings, other_ratings)
            similarities.append((similarity, other_user))

    similarities.sort(reverse=True)
    top_users = similarities[:3]

    averages = [0] * len(books)

    for similarity, other_user in top_users:
        for i, rating in enumerate(user_data[other_user]):
            if rating != 0:
                averages[i] += rating / similarity

    recommendations = [(average, book) for average, book in zip(averages, books) if average != 0]
    recommendations.sort(reverse=True)
    return recommendations


def read_data(filename):
    with open(filename) as f:
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

    return ratings, books


def calculate_averages(user_data, books):
    averages = [
        (sum(user_data[user][i] for user in user_data) / len([user for user in user_data if user_data[user][i] != 0]),
         books[i]) for i in range(len(books))]
    averages.sort(reverse=True)
    return averages


def main():
    filename = "ratings-small.txt"
    user_data, books = read_data(filename)

    while True:
        print("Welcome to the CS110 Book Recommender. Type the word in the")
        print("left column to do the action on the right.")
        print("recommend : recommend books for a particular user")
        print("averages  : output the average ratings of all books in the system")
        print("quit      : exit the program")

        option = input("next task? ").lower()

        if option == "recommend":
            user_name = input("user? ")
            recommendations = recommend_books(user_name, user_data, books)
            print("Recommendations:", recommendations)

        elif option == "averages":
            averages = calculate_averages(user_data, books)
            print("Averages:", averages)

        elif option == "quit":
            break

        else:
            print("Invalid option, Please try again.")


if __name__ == "__main__":
    main()
