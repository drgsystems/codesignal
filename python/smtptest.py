import smtplib

try:
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
except:
    print ('Something went wrong...')


sent_from = 'drgsystems@gmail.com'
to = 'drgonz55@yahoo.com'
subject = 'OMG Super Important Message'
body = 'Hey, whats up?\n\n- You'

email_text = """\
From: %s
To: %s
Subject: %s

%s
""" % (sent_from, ", ".join(to), subject, body)
