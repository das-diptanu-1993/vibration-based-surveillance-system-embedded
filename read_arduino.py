__author__ = 'DipTanU_DaS'
import serial
import datetime
import requests
def send_simple_message(text_line):
    return requests.post(
        "https://api.mailgun.net/v3/sandbox39bc8ec3a6b14007ba79857e89f6857b.mailgun.org/messages",
        auth=("api", "key-a66d8d62daeb52405993c2aea0c7813c"),
        data={"from": "Mailgun Sandbox <postmaster@sandbox39bc8ec3a6b14007ba79857e89f6857b.mailgun.org>",
              "to": "Diptanu Das <dd10@iitbbs.ac.in>",
              "subject": "Hello Diptanu Das",
              "text": text_line})

ser = serial.Serial('COM3', 9600)
while True:
    text = str(ser.readline())
    #if text[0] == "Vibration":
    words = text.split(" ")
    if words[0] == "Vibration":
        dt = str(datetime.datetime.now())
        text_line = text[0:len(text)-2]+"\n"+dt[0:len(dt)-6]
        print(text_line)
        send_simple_message(text_line)


