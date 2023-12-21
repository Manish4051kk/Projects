import mysql.connector
import numpy as np
import matplotlib.pyplot as plt
 
 
mydb = mysql.connector.connect(host="localhost",
                               user="root",
                               password="password",
                               database="airline")
mycursor = mydb.cursor()
 
# Fecthing Data From mysql to my python progame
mycursor.execute("select destination,charges from flights")
result = mycursor.fetchall
 
DESTINATION = []
CHARGES = []
 
for i in mycursor:
    DESTINATION.append(i[0])
    CHARGES.append(i[1])
     
print("DESTINATION = ", DESTINATION)
print("CHARGES = ", CHARGES)
 
 
# Visulizing Data using Matplotlib
plt.bar(DESTINATION, CHARGES)
plt.xlabel("DESTINATION")
plt.ylabel("CHARGES")
plt.title("AIRLINE")
plt.show()
