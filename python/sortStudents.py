#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()
from operator import itemgetter

# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# You are given a list of students who want to apply to the internship 
# at CodeSignal. For the ith student you know their full name students[i], 
# which can consist of up to 5 words (where a word is a set of consecutive 
# letters). It is guaranteed that the surname is always the last name 
# of student's full name.

# Your task is to sort the students lexicographically by their surnames. 
# If two students happen to have the same surname, their order in the 
# result should be the same as in the original list.

# Example

# For

# students = ["John Smith", "Jacky Mon Simonoff", 
            # "Lucy Smith", "Angela Zimonova"]

# the output should be

# solution(students) = ["Jacky Mon Simonoff", "John Smith", 
                          # "Lucy Smith", "Angela Zimonova"]

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.string students

    # Array of students, where each student is given by their full name 
	# consisting of at most 5 words. For each i students[i] consists of 
	# English letters and whitespace (' ') characters.

    # Guaranteed constraints:
    # 1 ≤ students.length ≤ 30,
    # 1 ≤ students[i].length ≤ 50.

    # [output] array.string

    # Array of students sorted as described above.


def solution(students):
# using lambda split name and sort from last
# thank you https://www.youtube.com/watch?v=52ngkWmVMHA
    students.sort(key= lambda name: name.split(" ")[-1])
    return students

if __name__ == "__main__":
# program starts here, methods are defined above
	students=[["John Smith", "Jacky Mon Simonoff", "Lucy Smith", "Angela Zimonova"],
		["Lucy Smith", "John Smith", "Jacky Mon Simonoff", "Angela Zimonova"],
		["Kate"],
		["Massuginn Dragonbrewer", "Gragrinelynn Chainbasher", "Barirud Treasureforged", "Orimir Rubyheart", "Krathoun Flatbuster", "Museagret Browngrog", "Groodgratelin Magmabuckle"],
		["Massuginn Dragonbrewer", "Nomneare Windback", "Nurgutrude Strongpike", "Barirud Treasureforged", "Rudrud Lavahelm", "Asseam Coindelver", "Krathoun Flatbuster", "Museagret Browngrog", "Gorbaebelle Brickbelt", "Groodgratelin Magmabuckle"],
		["John Doe", "Brick Tick", "Batman"]]

	results=[["Jacky Mon Simonoff", "John Smith", "Lucy Smith", "Angela Zimonova"],
			["Jacky Mon Simonoff", "Lucy Smith", "John Smith", "Angela Zimonova"],
			["Kate"],
			["Museagret Browngrog", "Gragrinelynn Chainbasher", "Massuginn Dragonbrewer", "Krathoun Flatbuster", "Groodgratelin Magmabuckle", "Orimir Rubyheart", "Barirud Treasureforged"],
			["Gorbaebelle Brickbelt", "Museagret Browngrog", "Asseam Coindelver", "Massuginn Dragonbrewer", "Krathoun Flatbuster", "Rudrud Lavahelm", "Groodgratelin Magmabuckle", "Nurgutrude Strongpike", "Barirud Treasureforged", "Nomneare Windback"],
			["Batman", "John Doe", "Brick Tick"]]
	
	for i in range(len(students)):
		myresult=solution(students[i])
		print(" test ", i, " should be ", results[i], "\n and is "," "*11, myresult,"\n")