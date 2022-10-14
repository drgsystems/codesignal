# pip install google

from googlesearch import search

#query = "Medium.com"
query = input("input a google query string\n")
 
for url in search(query):
    print(url)