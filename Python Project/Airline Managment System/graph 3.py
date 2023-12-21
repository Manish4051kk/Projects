import mysql.connector
import numpy as np
import matplotlib.pyplot as plt
 
 
mydb = mysql.connector.connect(host="localhost",
                               user="root",
                               password="password",
                               database="airline")
mycursor = mydb.cursor()
 
# Fecthing Data From mysql to my python progame
mycursor.execute("select AIRLINES_NAME,DESTINATION from flights")
result = mycursor.fetchall
 
AIRLINES_NAME = []
DESTINATION = []
 
for i in mycursor:
    AIRLINES_NAME.append(i[0])
    DESTINATION.append(i[1])
     
print("AIRLINES_NAME = ", AIRLINES_NAME)
print("DESTINATION= ", DESTINATION)
 
 
# Visulizing Data using Matplotlib
plt.bar(AIRLINES_NAME, height= 5)

plt.title("AIRLINE")
plt.show()
