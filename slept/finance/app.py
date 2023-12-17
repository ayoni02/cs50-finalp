import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return render_template("index.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    look = None
    if request.method == "POST":
        stock = request.form.get("symbol")
        if not stock:
            return apology("No Quote was given", 400)
        look = lookup(stock)
        if look is None:
            return apology("No Quote was given", 400)
        return render_template("buy.html", buyl=look)
    else:
        return render_template("buy.html", buyl=look)

@app.route("/bought", methods=["POST"])
def deregister():
    id = request.form.get("shares")
    id = int(id)
    if id < 1:
        return apology("invalid request", 400)
    #db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        stock = request.form.get("symbol")
        if not stock:
            return apology("No Symbol was given", 400)
        look = lookup(stock)
        if look is None:
            return apology("No Quote was given", 400)
        return render_template("quoted.html", quotes=look)
    else:
        return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    session.clear()

    if request.method == "POST":
        name = request.form.get("username")
        if not name:
            return apology("Username is blank")
        pass1 = request.form.get("password")
        pass2 = request.form.get("confirmation")
        if not pass1 or not pass2:
            return apology("Password cannot be empty")
        elif pass1 != pass2:
            return apology("password are not similar")
        passh = generate_password_hash(pass1)
        lst = db.execute("select username from users WHERE username = ?", request.form.get("username"))
        if len(lst) > 0:
            return apology("Username already exist")
        db.execute("INSERT into users (username, hash) VALUES (?, ?)", name, passh)
        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
