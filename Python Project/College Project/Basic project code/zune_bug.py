def zune_bug(days):
    year = 1980
    while days >= 365:   # subtract out years
        if year % 4 == 0:
            if days >= 365:
                days -= 366
                year += 1
        else:
            days -= 365
            year += 1
    print("days =", days, ", year =", year)
