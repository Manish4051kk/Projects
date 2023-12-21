import mysql.connector
import numpy as np
import matplotlib.pyplot as plt
 
 
mydb = mysql.connector.connect(host="localhost",
                               user="root",
                               password="password",
                               database="airline")
mycursor = mydb.cursor()
 
# Fecthing Data From mysql to my python progame
mycursor.execute("select CHARGES ,AIRLINES_NAME  from flights")
result = mycursor.fetchall
 
CHARGES  = []
AIRLINES_NAME  = []
 
for i in mycursor:
    CHARGES .append(i[0])
    AIRLINES_NAME .append(i[1])
     
print("CHARGES  = ", CHARGES )
print("AIRLINES_NAME = ", AIRLINES_NAME )
myexplode = [0.2, 0.1, 0.02, 0.3,0.02,0.2, 0.1, 0.02, 0.3,0.02,0.2, 0.1, 0.02, 0.3,0.02,0.2, 0.1, 0.02, 0.3,0.02,0.2, 0.1, 0.02, 0.3,0.02]

 
# Visulizing Data using Matplotlib
plt.pie(CHARGES , labels=  AIRLINES_NAME, explode = myexplode ,shadow = True)
plt.title("AIRLINE")
plt.legend()
plt.show()
