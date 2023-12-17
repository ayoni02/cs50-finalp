import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

DAY = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31]
MONTH = [1,2,3,4,5,6,7,8,9,10,11,12]

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        if not name:
            return "No name was registered"
        day = request.form.get("day")
        if int(day) not in DAY:
            return "Failed to register day"
        month = request.form.get("month")
        if int(month) not in MONTH:
            return "Failed to register month"
        db.execute("INSERT into birthdays (name, day, month) VALUES (?, ?, ?)", name, day, month)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        reg = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", days=DAY, months=MONTH, reg=reg)

@app.route("/deregister", methods=["POST"])
def deregister():
    id = request.form.get("id") 

    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")
