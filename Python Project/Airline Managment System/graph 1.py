import mysql.connector
import numpy as np
import matplotlib.pyplot as plt
 
 
mydb = mysql.connector.connect(host="localhost",
                               user="root",
                               password="password",
                               database="airline")
mycursor = mydb.cursor()
 
# Fecthing Data From mysql to my python progame
mycursor.execute("select AIRLINES_NAME,FLIGHT_NO from flights")
result = mycursor.fetchall
 
AIRLINES_NAME = []
FLIGHT_NO = []
 
for i in mycursor:
    AIRLINES_NAME.append(i[0])
    FLIGHT_NO.append(i[1])
     
print("AIRLINES_NAME = ", AIRLINES_NAME)
print("FLIGHT_NO= ", FLIGHT_NO)
 
 
# Visulizing Data using Matplotlib
plt.plot(AIRLINES_NAME,FLIGHT_NO)
plt.title("AIRLINE")
plt.show()
