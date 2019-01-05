import csv
import os
import smtplib
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

students = []

#if not os.getenv("PASSWORD"):
#    raise RuntimeError("missing PASSWORD")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", students=students)

@app.route("/register", methods=['GET','POST'])
def register():
    if request.method == 'POST':
        name = request.form.get("name")
        email = request.form.get("email")
        dorm = request.form.get("dorm")

        if not name or not email or not dorm:
            return render_template("failure.html")
        file = open("registrants.csv","a")
        write = csv.writer(file)
        write.writerow((name,email,dorm))
        file.close()

        students.append(f"{name} from {dorm}")
        message = "You are registered!"

#        server = smtplib.SMTP("smtp.gmail.com",587)
#        server.starttls()
#        server.login("johnbower2012@gmail.com",".559deba")#os.getenv("PASSWORD"))
#        server.sendmail("johnbower2012@gmail.com",email,message)

        return redirect("/registrants")
    else:
        return render_template("register.html")

