from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    # display all the stock of the user
    left = 10000
    total = 0
    stocks = db.execute("SELECT * FROM transactions WHERE userId = :userId" \
    , userId = session.get("user_id"))
    for stock in stocks:
        price = lookup(stock["symbol"])
        left -= int(stock["shares"]) * float(price["price"])
    for t in stocks:
        total += int(stock["shares"]) * float(stock["price"])
    total += left
    return render_template("index.html",stocks = stocks,left = usd(left), total = usd(total))

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""
    
    # if request is made after form filling
    if request.method == "POST":
        # if form field is empty
        if request.form.get("symbol") == "" or request.form.get("share"):
            return apology("Empty Field!")
        
        # lookup for the stock and return name, symbol, price
        stock = lookup(request.form.get("symbol"))
        
        if not stock:
            return apology("Invalid Symbol!")
        
        # check for the cash available
        total = float(stock["price"] * float(request.form.get("shares")))
        cash = db.execute("SELECT * FROM users WHERE id = :id", id = session.get("user_id"))
        if total > cash[0]["cash"]:
            return apology("Sorry You Don't have enough money!")
        
        # check if the stock is already present then update it.
        check = db.execute("SELECT * FROM transactions INDEXED BY symbol WHERE symbol = :symbol AND userId = :userId" \
        , symbol = request.form.get("symbol"), userId = session.get("user_id"))
        
        if check:
            # update the shares quantity
            update = db.execute("UPDATE transactions SET shares = :shares WHERE userId = :userId" \
            , shares = (int(check[0]["shares"]) + int(request.form.get("shares"))) \
            , userId = session.get("user_id"))
            
            # update the user cash in the wallet
            cashUpdate = db.execute("UPDATE users SET cash = :updateCash WHERE id = :userId" \
            , updateCash = float((cash[0]["cash"] - total)), userId = session.get("user_id"))
        
        
        # if stock is not present     
        buy = db.execute("INSERT INTO transactions (symbol,shares,price,userId,name) VALUES(:symbol,:shares,:price,:userId,:name)" \
        , symbol = request.form.get("symbol"),shares = request.form.get("shares") \
        , price = float(stock["price"]),userId = session.get("user_id"), name = str(stock["name"]))
        
        # upate the cash
        cashUpdate = db.execute("UPDATE users SET cash = :updateCash WHERE id = :userId" \
        , updateCash = float((cash[0]["cash"] - total)), userId = session.get("user_id"))
        
        return redirect(url_for('index'))
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    stocks = db.execute("SELECT * FROM transactions WHERE userId = :id" \
    , id = session.get("user_id"))
    
    return render_template("history.html", stocks = stocks)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        # call the lookup function from helpers.py
        # get the stocks in dict
        stock = lookup(request.form.get("symbol"))
        if stock != None:
            return render_template("stock.html",stock = stock)
        else:
            return apology("oops! Internal Error")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""
    
    # if user reached route via POST
    if request.method == "POST":
        
        # if username field is empty
        if not request.form.get("username"):
            return apology("Missing Username!")
        # if password field is empty    
        elif not request.form.get("password"):
            return apology("Missing Password!")
        
        # if confirm password field is empty
        elif not request.form.get("cpassword"):
            return apology("Please re-type password")
        
        # if password didn't match ie typos error
        if request.form.get("password") != request.form.get("cpassword"):
            return apology("Password didn't match!")
        
        # checking if the username is already registered
        check = db.execute("SELECT * FROM users INDEXED BY username WHERE username = :username" \
        , username = request.form.get("username"))
        
        # throwing error if username is already registered
        if check != 0:
            return apology("Username is already exist!")
        
        # hash the password with basic schemas
        gen_hash = pwd_context.hash(request.form.get("password"))
        
        # insert the entry into database
        signin = db.execute("INSERT INTO users(username, hash) VALUES (:username, :hash)" \
        , username = request.form.get("username"), hash = gen_hash)
        
        # set session user_id 
        session["user_id"] = str(signin)
        
        # redirect user to home page
        return redirect(url_for("index"))
            
    else:
        # else if user reached route via GET (as by clicking a link or via redirect)
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    # if request method is post
    if request.method == "POST":
        # if form field is empty
        if request.form.get("symbol") == "" or request.form.get("share"):
            return apology("Empty Field!")
        
        # lookup for the stock and return name, symbol, price
        stock = lookup(request.form.get("symbol"))
        
        if not stock:
            return apology("Invalid Symbol!")
        
        # check for the cash available
        total = float(stock["price"] * float(request.form.get("shares")))
        
        cash = db.execute("SELECT * FROM users WHERE id = :id", id = session.get("user_id"))
        
        shares = db.execute("SELECT * FROM transactions WHERE userId = :userId" \
        ,userId = session.get("user_id"))
        
        
        if cash[0]["cash"]:
            updateCash = db.execute("UPDATE users SET cash = :creditCash WHERE id = :id" \
            , creditCash = float(total + cash[0]["cash"] ), id = session.get("user_id"))
            
            updateShare = db.execute("UPDATE transactions SET shares = :share WHERE userId = :userId  AND symbol = :symbol" \
            ,share = int(shares[0]["shares"]) - int(request.form.get("shares")), userId = session.get("user_id") \
            ,symbol = request.form.get("symbol"))    
            
            return redirect(url_for('index'))
        else:
            return apology("error!")
            
    else:
        return render_template("sell.html")
            
                
