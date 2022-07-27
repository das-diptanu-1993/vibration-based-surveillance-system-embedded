# Try running this locally.
import requests
def send_simple_message():
    return requests.post(
        "https://api.mailgun.net/v3/sandbox39bc8ec3a6b14007ba79857e89f6857b.mailgun.org/messages",
        auth=("api", "key-a66d8d62daeb52405993c2aea0c7813c"),
        data={"from": "Mailgun Sandbox <postmaster@sandbox39bc8ec3a6b14007ba79857e89f6857b.mailgun.org>",
              "to": "Diptanu Das <dd10@iitbbs.ac.in>",
              "subject": "Hello Diptanu Das",
              "text": "Congratulations Diptanu Das, you just sent an email with Mailgun!  You are truly awesome!  "+
                      "You can see a record of this email in your logs: https://mailgun.com/cp/log .  You can send up "+
                      "to 300 emails/day from this sandbox server.  Next, you should add your own domain so you can send 10,000 emails/month for free."})

send_simple_message()

