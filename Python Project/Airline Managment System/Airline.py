import mysql.connector
from csv import DictWriter
from csv import DictReader
import os
import math
import random
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from datetime import date
from tabulate import tabulate as b
import time


# OTP
def otp(emailid):
    digits = "0123456789"
    OTP = ""
    for i in range(6):
        OTP += digits[math.floor(random.random() * 10)]
    msg = MIMEMultipart("alternative")
    msg["Subject"] = "No Reply"
    msg["From"] = "manish4051k@gmail.com"
    msg["To"] = emailid
    text = "Here is your OTP"
    html = f"""\
    <!DOCTYPE html>
    <html>
    <body>

    <h1 style = "text-align: center; font-family: Georgia; font-size: 500%;"><mark style="background-color: blue; color: red;"><b>MANISH Airways</b></mark></h1>
    <p style="font-family:courier; font-size: 150%; text-align: center;"  ><b>Here is your OTP : <mark style = "background-color: black; color: white;">{OTP}</mark></b></p>

    </body>
    </html>
    """
    part1 = MIMEText(text, "plain")
    part2 = MIMEText(html, "html")
    msg.attach(part1)
    msg.attach(part2)
    mail = smtplib.SMTP("smtp.gmail.com", 587)
    mail.ehlo()
    mail.starttls()
    mail.login("manish4051k@gmail.com", "brmmabyxxowarrzm")
    mail.sendmail("manish4051k@gmail.com", emailid, msg.as_string())
    mail.quit()
    return int(OTP)


conn = mysql.connector.connect(
    host="localhost", port="3306", user="root", password="password", database="airline"
)
my_cursor = conn.cursor()

print("\n********************Welcome to Flight Booking System***********************")

acc = input("\nDo you have an account (Y/N): ")
e = {}
if acc == "y" or acc == "yes" or acc == "Y" or acc == "YES":
    email = input("\nEnter your Email ID: ")
    pas = input("\nEnter your Password: ")
    otp_ = otp(email)
    otp1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
    if otp1 == otp_:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        a1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if a1 == otp_:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            a2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if a2 == otp_:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                a3 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if a3 == otp_:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()


else:
    print("\n-------Account creation-------")
    nam = input("\nEnter your full name: ")
    pn = int(input("\nEnter your phone no: "))
    city = input("\nEnter your city name: ")
    state = input("\nEnter your state: ")
    email = input("\nEnter your Email ID: ")
    passw = input("\nEnter your Password: ")
    print(f"\nSending OTP to {email}...")
    otp_1 = otp(email)
    otp2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
    if otp2 == otp_1:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        a4 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if a4 == otp_1:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            a5 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if a5 == otp_1:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                a6 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if a6 == otp_1:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()
    print("\n-------Your Account is Created Successfully-------")


print("\nhow do you want to search your flight by :-")
print("1.flight number")
print("2.mannualy")

ans = int(input("\nAnswer (1/2):-"))


if ans == 1:
    num = input("\nEnter flight number:-")
    headers = [
        "SNO",
        "AirlinesName",
        "Departure",
        "Destination",
        "FlightNumber",
        "TimeofDeparture",
        "TimeofArrival",
        "Charges",
    ]
    query = "SELECT * FROM FLIGHTS WHERE FLIGHT_NO = '{}' ".format(num)
    my_cursor.execute(query)
    l = []
    print("your flight details are-----")
    for i in my_cursor:
        l.append(i)
        print(b(l, headers))

deplo = []
arrlo = []
fli = []


def flight_data():
    departure = input("\nEnter your departure locaion:-")
    arrival = input("\nEnter your arrival location:-")
    headers2 = ["AirlinesName"]
    query2 = "SELECT AIRLINES_NAME FROM FLIGHTS WHERE DEPARTURE = '{}' AND DESTINATION = '{}'".format(
        departure, arrival
    )
    deplo.append(departure)
    arrlo.append(arrival)
    my_cursor.execute(query2)
    p = []
    print("\nYour required flights are------")
    for r in my_cursor:
        p.append(r)
        print(b(p, headers2))
    fly = input("\nEnter a flight name you want:-")
    fli.append(fly)
    headers3 = [
        "SNO",
        "AirlinesName",
        "Departure",
        "Destination",
        "FlightNumber",
        "TimeofDeparture",
        "TimeofArrival",
        "Charges",
    ]
    print("\nHere are the details of your flight-----")
    query3 = "SELECT * FROM FLIGHTS WHERE AIRLINES_NAME = '{}' AND DEPARTURE = '{}' AND DESTINATION = '{}' ".format(
        fly, departure, arrival
    )
    x = []
    my_cursor.execute(query3)
    for c in my_cursor:
        x.append(c)
        print(b(x, headers3))


if ans == 2:
    flight_data()


con = input("\nWould you like to continue? (Y/N):-")
while True:
    if con == "n" or con == "N" or con == "no" or con == "NO":
        flight_data()
    else:
        break

passenger = int(input("\nEnter a number of passangers:-"))

nam = []
ag = []
gen = []


def pass_data():
    name = input("\nEnter a name of a passenger:-")
    age = int(input(f"\nEnter the age of {name}:-"))
    gender = input("\nMale/Female:-")
    nam.append(name)
    ag.append(age)
    gen.append(gender)
    with open("userdata.csv", "a", newline="") as csvfile:
        csvwriter = DictWriter(csvfile, fieldnames=["name", "age", "gender"])
        csvwriter.writeheader()
        csvwriter.writerow({"name": name, "age": age, "gender": gender})
    return print("\n-------Data entered successfully-------")


for d in range(passenger):
    pass_data()


def read_csv():
    with open("userdata.csv") as csvreader:
        reader = DictReader(csvreader)
        for row in reader:
            print(row)
    os.remove(r"userdata.csv")
    return print("------------------------------------")


read_csv()
print("\nCheck your details----")

ch = input("\nDo you want to continue? (Y/N):-")

while True:
    if ch == "n" or ch == "N" or ch == "no" or ch == "NO":
        for e in range(passenger):
            pass_data()
        read_csv()
    else:
        break

print("\nChoose the class you want:-")
print("1.Economy class")
print("2.Business class (+20% Charges)")
print("3.First class (+40% Charges)")

flo = []
tdep = []
tarr = []


def fl_nm():
    query4 = "SELECT FLIGHT_NO FROM FLIGHTS WHERE airlines_name = '{}' and DEPARTURE = '{}' and DESTINATION = '{}' ".format(
        fli[0], deplo[0], arrlo[0]
    )
    my_cursor.execute(query4)
    for f in my_cursor:
        flo.append(f)

    query5 = "SELECT TIME_OF_DEPARTURE FROM FLIGHTS WHERE airlines_name = '{}' and DEPARTURE = '{}' and DESTINATION = '{}' ".format(
        fli[0], deplo[0], arrlo[0]
    )
    my_cursor.execute(query5)
    for g in my_cursor:
        tdep.append(g)

    query6 = "SELECT TIME_OF_ARRIVAL FROM FLIGHTS WHERE airlines_name = '{}' and DEPARTURE = '{}' and DESTINATION = '{}' ".format(
        fli[0], deplo[0], arrlo[0]
    )
    my_cursor.execute(query6)
    for h in my_cursor:
        tarr.append(h)


an = []
de = []
ds = []
td = []
ta = []


def fl_no():
    query7 = "SELECT AIRLINES_NAME FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(num)
    my_cursor.execute(query7)
    for i in my_cursor:
        an.append(i)

    query8 = "SELECT DEPARTURE FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(num)
    my_cursor.execute(query8)
    for j in my_cursor:
        de.append(j)

    query9 = "SELECT DESTINATION FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(num)
    my_cursor.execute(query9)
    for k in my_cursor:
        ds.append(k)

    query10 = "SELECT TIME_OF_DEPARTURE FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(num)
    my_cursor.execute(query10)
    for l in my_cursor:
        td.append(l)

    query11 = "SELECT TIME_OF_ARRIVAL FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(num)
    my_cursor.execute(query11)
    for m in my_cursor:
        ta.append(m)


cl = int(input("\nEnter class no (1/2/3):-"))

payment = []

if ans == 1 and cl == 1:
    fl_no()
    query12 = "SELECT CHARGES*{} FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(
        passenger, num
    )
    my_cursor.execute(query12)
    print(f"\nnames = {nam}               age = {ag}           gender = {gen}")
    print(f"flight name = {an}         departure = {de}       destination = {ds}")
    print(
        f"flight number = {num}      diparture time = {td}        arrival time = {ta}     "
    )
    print("class = economy class")
    ticket_class = "economy class"
    for n in my_cursor:
        payment.append(n)
        print(f"\nYou have to pay {n} rupees")

elif ans == 1 and cl == 2:
    fl_no()
    query13 = (
        "SELECT (CHARGES +CHARGES*0.2)*{} FROM FLIGHTS WHERE flight_no = '{}' ".format(
            passenger, num
        )
    )
    my_cursor.execute(query13)
    print(f"\nnames = {nam}               age = {ag}           gender = {gen}")
    print(f"flight name = {an}         departure = {de}       destination = {ds}")
    print(
        f"flight number = {num}      diparture time = {td}        arrival time = {ta}     "
    )
    print("class = business class")
    ticket_class = "business class"
    for o in my_cursor:
        payment.append(o)
        print(f"\nYou have to pay {o} rupees")

elif ans == 1 and cl == 3:
    fl_no()
    query14 = (
        "SELECT (CHARGES +CHARGES*0.4)*{} FROM FLIGHTS WHERE FLIGHT_NO = '{}'".format(
            passenger, num
        )
    )
    my_cursor.execute(query14)
    print(f"\nnames = {nam}               age = {ag}           gender = {gen}")
    print(f"flight name = {an}         departure = {de}       destination = {de}")
    print(
        f"flight number = {num}      diparture time = {td}        arrival time = {ta}     "
    )
    print("class = first class")
    ticket_class = "first class"
    for p in my_cursor:
        payment.append(p)
        print(f"\nYou have to pay {p} rupees")


elif ans == 2 and cl == 1:
    fl_nm()
    query15 = "SELECT CHARGES*{} FROM FLIGHTS WHERE airlines_name = '{}' and DEPARTURE = '{}' and DESTINATION = '{}' ".format(
        passenger, fli[0], deplo[0], arrlo[0]
    )
    my_cursor.execute(query15)
    print(f"\nnames = {nam}               age = {ag}           gender = {gen}")
    print(
        f"flight name = {fli}         departure = {deplo}       destination = {arrlo}"
    )
    print(
        f"flight number = {flo}      diparture time = {tdep}        arrival time = {tarr}     "
    )
    print("class = economy class")
    ticket_class = "economy class"
    for q in my_cursor:
        payment.append(q)
        print(f"\nYou have to pay {q} rupees")

elif ans == 2 and cl == 2:
    fl_nm()
    query16 = "SELECT (CHARGES +CHARGES*0.2)*{} FROM FLIGHTS WHERE airlines_name = '{}' and DEPARTURE = '{}' and DESTINATION = '{}' ".format(
        passenger, fli[0], deplo[0], arrlo[0]
    )
    my_cursor.execute(query16)
    print(f"\nnames = {nam}               age = {ag}           gender = {gen}")
    print(f"flight name = {fli}         departure = {deplo}       destinatio = {arrlo}")
    print(
        f"flight number = {flo}      diparture time = {tdep}        arrival time = {tarr}     "
    )
    print("class = business class")
    ticket_class = "business class"
    for r in my_cursor:
        payment.append(r)
        print(f"\nYou have to pay {r} rupees")

elif ans == 2 and cl == 3:
    fl_nm()
    query17 = "SELECT (CHARGES +CHARGES*0.4)*{} FROM FLIGHTS WHERE airlines_name = '{}' and DEPARTURE = '{}' and DESTINATION = '{}' ".format(
        passenger, fli[0], deplo[0], arrlo[0]
    )
    my_cursor.execute(query17)
    print(f"\nnames = {nam}               age = {ag}           gender = {gen}")
    print(
        f"flight name = {fli}         departure = {deplo}       destination = {arrlo}"
    )
    print(
        f"flight number = {flo}      diparture time = {tdep}        arrival time = {tarr}     "
    )
    print("class = first class")
    ticket_class = "first class"
    for s in my_cursor:
        payment.append(s)
        print(f"\nYou have to pay {s} rupees")

pay = input("\nTo pay press (p):-")

if pay == "p" or pay == "P":
    print("\nHow you want to pay ?")
    print("1.Google pay")
    print("2.Amazon pay")
    print("3.Paypal")
    print("4.Apple pay")
    print("5.Credit card")
    print("6.Debit card")

pay2 = int(input("\nEnter your payment method (1/2/3/4........):-"))

if pay2 == 1:
    print("\n-------------------Google pay---------------------------")
    print(f"Pay {payment[0]} rupees")
    pay3 = input("\nTo continue payment press (p):-")
    otp_0 = otp(email)
    otpp = int(input("\nEnter the OTP Code sent to your Email ID: "))
    if otpp == otp_0:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        b1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if b1 == otp_0:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            b2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if b2 == otp_0:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                b3 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if b3 == otp_0:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()
    print("Processing...")
    time.sleep(3)
    print("\nTransaction successful------------")
    print("\n**********Thank you***********")

if pay2 == 2:
    print("\n-------------------Amazon pay---------------------------")
    print(f"Pay {payment[0]} rupees")
    pay3 = input("\nTo continue payment press (p):-")
    otp_01 = otp(email)
    otpq = int(input("\nEnter the otp code sent to your email id: "))
    if otpq == otp_01:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        c1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if c1 == otp_01:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            c2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if c2 == otp_01:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                c3 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if c3 == otp_01:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()
    print("Processing...")
    time.sleep(3)
    print("\nTransaction successful------------")
    print("\n**********Thank you***********")

if pay2 == 3:
    print("\n-------------------Paypal---------------------------")
    print(f"Pay {payment[0]} rupees")
    pay3 = input("\nTo continue payment press (p):-")
    otp_02 = otp(email)
    otpr = int(input("\nEnter the OTP Code sent to your Email ID: "))
    if otpr == otp_02:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        d1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if d1 == otp_02:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            d2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if d2 == otp_02:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                d3 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if d3 == otp_02:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()
    print("Processing...")
    time.sleep(3)
    print("\nTransaction successful------------")
    print("**********Thank you***********")

if pay2 == 4:
    print("\n-------------------Apple pay---------------------------")
    print(f"Pay {payment[0]} rupees")
    pay3 = input("\nTo continue payment press (p):-")
    otp_03 = otp(email)
    otpr = int(input("\nEnter the OTP Code sent to your Email ID: "))
    if otpr == otp_03:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        e1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if e1 == otp_03:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            e2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if e2 == otp_03:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                e3 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if e3 == otp_03:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()
    print("Processing...")
    time.sleep(3)
    print("\nTransaction successful------------")
    print("**********Thank you***********")

if pay2 == 5 or pay2 == 6:
    print("\n-------------------Card payment---------------------------")
    print(f"PAY {payment[0]} RUPEES")
    c_no = int(input("\nEnter your card number:-"))
    month = int(input("\nEnter Month: "))
    year = int(input("\nEnter Year: "))
    cvv = int(input("\nENTER YOUR CVV:-"))
    otp_04 = otp(email)
    otps = int(input("\nEnter the OTP Code sent to your Email ID: "))
    if otps == otp_04:
        print("Verified.")
    else:
        print("Wrong OTP. Please try again.(three tries left.)")
        f1 = int(input("\nEnter the OTP Code sent to your Email ID: "))
        if f1 == otp_04:
            print("Verified.")
        else:
            print("Wrong OTP. Please try again.(two tries left.)")
            f2 = int(input("\nEnter the OTP Code sent to your Email ID: "))
            if f2 == otp_04:
                print("Verified.")
            else:
                print("Wrong OTP. Please try again.(one try left.)")
                f3 = int(input("\nEnter the OTP Code sent to your Email ID: "))
                if f3 == otp_04:
                    print("Verified.")
                else:
                    print(
                        "You've exceeded the maximum number of tries. Please try again later."
                    )
                    exit()
    print("Processing...")
    time.sleep(3)
    print("\nTransaction successful------------")
    print("**********Thank you***********")

print("\n--------Thanks for using flight booking system--------------")
msg = MIMEMultipart("alternative")
msg["Subject"] = "Ticket Confirmed"
msg["From"] = "manish4051k@gmail.com"
msg["To"] = email
text = "Ticket"
html = f"""\
<!DOCTYPE html>
<html>
<body>

<h1 style = "font-family: Impact; font-size: 450%; text-align: center;"><mark style="background-color: yellow; color: red"><b>TICKET CONFIRMED</b></mark></h1>
<p style="font-family: Georgia; font-size: 140%; text-align: center;"><b>Thank you for booking with us!</b></p>
<p style="font-family: Georgia; font-size: 130%; text-align: left;"><b>Here are your flight details -----</b></p>
<p></p>
<p></p>
<p style = "font-family: Cambria; font-size: 110%; text-align: left;">Passenger Name(s) : <mark style="background-color: black; color: red;"><b>{nam}</b></mark></p>
<p></p>
<p style = "font-family: Cambria; font-size: 110%; text-align: left;">Booking Date : <mark style="background-color: black; color: green;"><b>{date.today()}</b></mark></p>
<p></p>
<p style = "font-family: Cambria; font-size: 110%; text-align: left;">From : <mark style="background-color: black; color: blue;"><b>{de}</b></mark></p>
<p></p>
<p style = "font-family: Cambria; font-size: 110%; text-align: left;">To : <mark style="background-color: black; color: yellow;"><b>{ds}</b></mark></p>
<p></p>
<p style = "font-family: Cambria; font-size: 110%; text-align: left;">Class : <mark style="background-color: black; color: pink;"><b>{ticket_class}</b></mark></p>

</body>
</html>
"""
part1 = MIMEText(text, "plain")
part2 = MIMEText(html, "html")
msg.attach(part1)
msg.attach(part2)
mail = smtplib.SMTP("smtp.gmail.com", 587)
mail.ehlo()
mail.starttls()
mail.login("manish4051k@gmail.com", "brmmabyxxowarrzm")
mail.sendmail("manish4051k@gmail.com", email, msg.as_string())
mail.quit()
print(f"\nYour tickets are send to your email {email} ")
print("\nSee you later :)")


conn.close()
