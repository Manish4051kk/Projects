days_of_week = [
  'Sunday',
  'Monday',
  'Tuesday',
  'Wednesday',
  'Thursday',
  'Friday',
  'Saturday',
]

def add_time(start, duration, *args):

    [L, meridiem] = start.split(" ")
    [SH, SM] = L.split(":")
    [DH, DM] = duration.split(":")

    total_minutes = int(SM) + int(DM)
    total_hours = int(SH) + int(DH)
    future_days = 0

    if total_minutes >= 60:
      total_minutes -= 60
      total_hours += 1
    if total_minutes < 10:
      total_minutes = f"{total_minutes}".zfill(2)

    if total_hours >= 12:
      t, r = divmod(total_hours, 12)
      total_hours = r if r else total_hours
      if total_hours > 12:
        # this if condition is only for cases where total_hours is 24, 36, etc.
        total_hours = total_hours - ((t-1) * 12)

      if meridiem == 'PM':
        future_days = ((t-1) // 2) + 1
      else:
        future_days = t // 2

      if t > 0 and t % 2 != 0:
        meridiem = 'AM' if meridiem == 'PM' else 'PM'

    new_time = str(total_hours) + ":"
    new_time += str(total_minutes) + f" {meridiem}"

    if args:
      day = args[0].title()
      if future_days > 0:
        # find the index of day from param
        index = days_of_week.index(day)
        # find that index plus future_days
        index += future_days % 7
        # if index is greater than list length, reset the index value
        if index > 6:
          index = index - 7
        day = days_of_week[index]

      new_time += f", {day}"

    if future_days == 1:
      new_time += " (next day)"
    elif future_days > 1:
      new_time += f" ({future_days} days later)".rjust(11)

    return new_time


# print(add_time("3:00 PM", "3:10"))
# print(add_time("11:30 AM", "2:32", "Monday"))
# print(add_time("11:43 AM", "00:20"))
# print(add_time("10:10 PM", "3:30"))
# print(add_time("11:43 PM", "24:20", "tueSday"))
# print(add_time("6:30 PM", "205:12"))
# print(add_time("5:01 AM", "0:00"))
# print(add_time("8:16 PM", "466:02", "tuesday"))
