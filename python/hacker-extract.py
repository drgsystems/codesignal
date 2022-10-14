#!/usr/bin/env python3
##
## my yahoo smtp password is mrdevzhpalfkqymg
##
# http requests
import requests 

from bs4 import BeautifulSoup # web scraping
# Send the mail
import smtplib
# email body
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
# system date and time manipulation
import datetime
now = datetime.datetime.now()
print('today is ',now)
# email content placeholder

content = ''


#extracting Hacker News Stories

def extract_news(url):
	print('Extracting Hacker News Stories...')
	today = str(now.year)+'-'+str(now.month)+'-'+str(now.day)    
	cnt = ''
	cnt +=('<b>HN Top Stories:  <b>\n'+today+'<br>'+'-'*50+'<br>')
	response = requests.get(url)
	content = response.content
	soup = BeautifulSoup(content,'html.parser')
	for i,tag in enumerate(soup.find_all('td',attrs={'class':'title','valign':''})):
		cnt += ((str(i+1)+' :: '+tag.text + "\n" + '<br>') if tag.text != 'More' else '')
		#print(tag.prettify) #find_all('span',attrs={'class':'sitestr'}))
	return(cnt)
	
cnt = extract_news('https://news.ycombinator.com/')
content += cnt
content += ('<br>------<br>')
content += ('<br><br>End of Message')

## save content to a file for review
##
fp = open("HackerNews.html", 'w')
fp.write(content)
fp.close