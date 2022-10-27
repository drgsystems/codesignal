# Python code to test out solution to codesignal problem.
# To execute, enter python mysql_mischief.py
# mysql_server must be installed on your ubuntu virtualbox.

#=============Problem statement==========================
# Your nephews Huey, Dewey, and Louie are staying with you over the 
winter holidays. Ever since they arrived, you've hardly had a day 
go by without some kind of incident - the little rascals do whatever 
they please! Actually, you're not even mad; the ideas they come up 
with are pretty amazing, and it looks like there's even a system to 
their mischief.

# You decided to track and analyze their behavior, so you created 
the mischief table in your local database. The table has the following 
columns:

    # mischief_date: the date of the mischief (of the date type);
    # author: the nephew who caused the mischief ("Huey", "Dewey" or "Louie");
    # title: the title of the mischief.

# It looks like each of your nephews is active on a specific day of 
the week. You decide to check your theory by creating another table 
as follows:
# The resulting table should contain four columns, weekday, mischief_date, 
author, and title, where weekday is the weekday of mischief_date 
(0 for Monday, 1 for Tuesday, and so on, with 6 for Sunday). The table 
should be sorted by the weekday column, and for each weekday Huey's 
mischief should go first, Dewey's should go next, and Louie's should 
go last. In case of a tie, mischief_date should be a tie-breaker. 
If there's still a tie, the record with the lexicographically smallest 
title should go first.

# It is guaranteed that all entries of mischief are unique.

# Example

# For the following table mischief
# mischief_date 	author 	title
# 2016-12-01 	Dewey 	Cook the golden fish in a bucket
# 2016-12-01 	Dewey 	Paint the walls pink
# 2016-12-01 	Huey 	Eat all the candies
# 2016-12-01 	Louie 	Wrap the cat in toilet paper
# 2016-12-08 	Louie 	Play hockey on linoleum
# 2017-01-01 	Huey 	Smash a window
# 2017-02-06 	Dewey 	Create a rink on the porch

# the output should be
# weekday 	mischief_date 	author 	title
# 0 	2017-02-06 	Dewey 	Create a rink on the porch
# 3 	2016-12-01 	Huey 	Eat all the candies
# 3 	2016-12-01 	Dewey 	Cook the golden fish in a bucket
# 3 	2016-12-01 	Dewey 	Paint the walls pink
# 3 	2016-12-01 	Louie 	Wrap the cat in toilet paper
# 3 	2016-12-08 	Louie 	Play hockey on linoleum
# 6 	2017-01-01 	Huey 	Smash a window

# The first and the eighth of December are Thursdays, the sixth of 
February is a Monday, and the first of January is a Sunday.

# The dates in the example are given in the format YYYY-MM-DD.
#=====================solution===================
import mysql.connector
import os

table_name = "mischief"

def solution():  # this function will select, perform modulo and sort output.
	# BEGIN
	crsr.execute(
	"SELECT MOD(DAYOFWEEK(mischief_date)+5, 7) AS weekday, mischief_date, author, title \
	FROM mischief \
	ORDER BY weekday, FIELD(author,'Huey', 'Dewey', 'Louie'), mischief_date, title")
		
	# END

def insert_data():
	# SQL commands to insert the data in the table 
	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)"
	val = ("2016-12-01", "Dewey", "Cook the golden fish in a bucket")
	crsr.execute(sql, val) 
 
	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)" 
	val = ("2016-12-01", "Dewey", "Paint the walls pink")
	crsr.execute(sql, val) 

	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)" 
	val = ("2016-12-01", "Huey", "Eat all the candies")
	crsr.execute(sql, val)

	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)" 
	val = ("2016-12-01", "Louie", "Wrap the cat in toilet paper")
	crsr.execute(sql, val)

	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)" 
	val = ("2016-12-08", "Louie", "Play hockey on linoleum")
	crsr.execute(sql, val)

	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)" 
	val = ("2017-01-01", "Huey", "Smash a window")
	crsr.execute(sql, val)

	sql = "INSERT INTO mischief (mischief_date, author, title) VALUES (%s, %s, %s)" 
	val = ("2017-02-06", "Dewey", "Create a rink on the porch")
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
crsr.execute("CREATE TABLE IF NOT EXISTS %s (mischief_date DATE, author VARCHAR(20), title VARCHAR(50))" %(table_name,))

# call insert_data function
insert_data()

# print out the table contents if desired
# crsr.execute("SELECT * FROM mischief")
# answer=crsr.fetchall()
# for i in answer: 
	# print(i)
	
# call sorting function which has answer to codesignal exercise.
solution()
my_result = crsr.fetchall()

# To save the changes in the files. Never skip this. 
# If we skip this, nothing will be saved in the database. 
connection.commit() 

# close the connection
connection.close() 

# print sorted results of ORDER BY
for x in my_result:
  print(x[0], x[1], x[2], x[3])
 