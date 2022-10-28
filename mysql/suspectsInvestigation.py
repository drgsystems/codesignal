# Python code to test out solution to codesignal problem.
# To execute, enter python mysql_mischief.py
# mysql_server must be installed on your ubuntu virtualbox.

#=============Problem statement==========================
# A large amount of money was stolen today from the main city bank, 
# and as the chief of police it's your duty to find the robber.

# You store information about your suspects in the table Suspect, 
# which has the structure:

    # id: unique suspect id;
    # name: suspect first name;
    # surname: suspect surname;
    # height: suspect height;
    # weight: suspect weight.

# You have already gathered some evidence and discovered the following clues:

    # according to the camera records, the robber is not taller than 170cm;
    # the robber left their signature near the crime scene: "B. Gre?n". "B" 
	# definitely stands for the first letter of robber's name, and "Gre?n" 
	# is their surname. The 4th letter of the surname is smudged by ketchup 
	# and is unreadable.
	
# To make the list of suspects smaller, you would like to filter out the 
# suspects who can't possibly be guilty according to the information obtained 
# from the clues. For each remaining suspect, you want to save his/her id,
# name and surname. Please note that the information obtained from the clue 
# should be considered case-insensitive, so for example "bill Green", and "Bill green", 
# and "Bill Green" should all be included in the new table.

# Given the table Suspect, build the resulting table as follows: the table 
# should have columns id, name and surname and its values should be ordered 
# by the suspects' ids in ascending order.

# Example

# For the following table Suspect
# id 	name 	surname 	height 	weight
# 1 	John 	Doe 	165 	60
# 2 	Bill 	Green 	170 	67
# 3 	Baelfire 	Grehn 	172 	70
# 4 	Bill 	Gretan 	165 	55
# 5 	Brendon 	Grewn 	150 	50
# 6 	bill 	Green 	169 	50

# the output should be
# id 	name 	surname
# 2 	Bill 	Green
# 5 	Brendon 	Grewn
# 6 	bill 	Green

# The name of the 1st suspect doesn't start with "B", the 3rd suspect is 
# taller than 170cm, and the surname of the 4th suspect doesn't match the 
# given pattern, meaning that these suspects are not included in the results.

    # [execution time limit] 10 seconds (mysql)


#=====================solution===================
import mysql.connector
import os

table_name = "Suspect"

def suspectsInvestigation2():  # this function will select, perform modulo and sort output.
	# BEGIN
	crsr.execute(
	"SELECT id, name, surname \
	FROM Suspect \
	WHERE  (height <= 170 AND name LIKE 'B%' AND surname LIKE 'Gre_n');")
		
	# END

def insert_data():
	# SQL commands to insert the data in the table 
	
	sql = "INSERT INTO Suspect (id, name, surname, height, weight) VALUES (%s, %s, %s, %s, %s)"
	val = ("1","John","Doe","165","60")
	crsr.execute(sql, val) 
 
	sql = "INSERT INTO Suspect (id, name, surname, height, weight) VALUES (%s, %s, %s, %s, %s)" 
	val = ("2","Bill","Green","170","67")
	crsr.execute(sql, val) 

	sql = "INSERT INTO Suspect (id, name, surname, height, weight) VALUES (%s, %s, %s, %s, %s)" 
	val = ("3","Baelfire","Grehn","172","70")
	crsr.execute(sql, val)

	sql = "INSERT INTO Suspect (id, name, surname, height, weight) VALUES (%s, %s, %s, %s, %s)" 
	val = ("4","Bill","Gretan","165","55")
	crsr.execute(sql, val)

	sql = "INSERT INTO Suspect (id, name, surname, height, weight) VALUES (%s, %s, %s, %s, %s)" 
	val = ("5","Brendon","Grewn","150","50")
	crsr.execute(sql, val)

	sql = "INSERT INTO Suspect (id, name, surname, height, weight) VALUES (%s, %s, %s, %s, %s)" 
	val = ("6","bill","Green","169","50")
	crsr.execute(sql, val)

#os.system("rm -f codesignal")

# connect to codesignal database, if it doesn't exist it will be created.
connection = mysql.connector.connect(
  host='localhost',
  user='root',
  password='Codesignal12@!',
  database='codesignal')

# cursor 
crsr = connection.cursor()

# create database if it doesn't exist
crsr.execute('CREATE DATABASE IF NOT EXISTS %s;' %(table_name,)) 

crsr.execute('DROP TABLE IF EXISTS %s;' % (table_name,))

# SQL command to create a table in the database 
crsr.execute("CREATE TABLE IF NOT EXISTS %s (id VARCHAR(10), name VARCHAR(10), surname VARCHAR(10), height VARCHAR(10), weight VARCHAR(10))" %(table_name,))

# call insert_data function
insert_data()

# print out the table contents if desired
# crsr.execute("SELECT * FROM mischief")
# answer=crsr.fetchall()
# for i in answer: 
	# print(i)
	
# call sorting function which has answer to codesignal exercise.
suspectsInvestigation2()
my_result = crsr.fetchall()

# To save the changes in the files. Never skip this. 
# If we skip this, nothing will be saved in the database. 
connection.commit() 

# close the connection
connection.close() 

# print sorted results of ORDER BY
for x in my_result:
  print(x[0], x[1], x[2])
 