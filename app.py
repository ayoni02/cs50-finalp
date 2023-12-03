import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
import joblib
from runners import models, preprocess

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

db = SQL("sqlite:///tweets.db")

def test(word):
    result = models(word)
    return result

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
            return "No tweet was inputed"
        #mod = joblib.load("pipeline.pkl")
        result = test(name)
        db.execute("INSERT into tweets (tweet, sentiment) VALUES (?, ?)", name, result)
        return redirect("/")
    else:
        twt = db.execute("SELECT * FROM tweets")
        return render_template("index.html", tab=twt)


@app.route("/deregister", methods=["POST"])
def deregister():
    id = request.form.get("ide")
    if id:
        db.execute("DELETE FROM tweets WHERE id = ?", id)

    return redirect("/")



if (__name__ == '__main__'):
    from runners import models, preprocess
    app.run(debug=True)
