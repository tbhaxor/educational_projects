from flask import Flask, render_template, request, url_for, flash, redirect
from flask import session as sec
from sqlalchemy import create_engine, Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from passlib.apps import custom_app_context as pwd_context
from datetime import datetime

# create base for mapping with class
Base = declarative_base()

# creating engine
engine = create_engine('mysql://root:password@localhost/skynet')
if engine:
    print "Connection Established"

# app with the file name
app = Flask(__name__)

# Setting up a session key
app.secret_key = '\xc1\xb4\x8ek\xbff\xf6\xe0$\xdf\x8e\tI\xaev\xdc\x03\x1d\x18\x8b\x9b\xee\xba\xd7'

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# Databaase 
class Users(Base):
    __tablename__ = 'users'
    id = Column(Integer, primary_key=True)
    name = Column(String(30))
    email = Column(String(50))
    password = Column(String(200))

class Messages(Base):
    __tablename__ = 'messages'
    id = Column(Integer, primary_key=True)
    userId = Column(Integer)
    message = Column(String(500))
    event = Column(String(20))

# Commit Changes 
Base.metadata.create_all(engine)

# Create session for commiting changes to Database
Session = sessionmaker(bind=engine)
session = Session()

@app.route('/')
def index():
   return render_template('index.htm')

@app.route('/blog',methods=['GET','POST'])
def blog():
    
    if not id in sec:
        return redirect(url_for('index'))
    userId = sec['id']
    if request.method == 'POST':
        message = request.form['message']
        time = datetime.now()
        time = str(time)
        status = Messages(userId=userId,message=message,event=time)
        session.add(status)
        if not session.commit():
            flash('MESSAGE UPLOADED!')
        msg = session.query(Messages).all()
        return render_template('blog.htm',name=request.args.get('name'),msg=msg)
    else:
        msg = session.query(Messages).all()
        return render_template('blog.htm',name=request.args.get('name'),msg=msg)

@app.route('/register',methods=['GET','POST'])
def register():
   # If new user register
   if request.method == 'POST':
       name = request.form['inputName']
       email = request.form['inputEmail']
       pas = request.form['inputPassword']
       password = pwd_context.encrypt(pas)

       user = Users(name=name,email=email,password=password)
       session.add(user)
       if not session.commit():
           flash('User Registered Successfully!')
           return render_template('register.htm')
       else:
            flash('There are some error, please try again after few min.')
            return render_template('register.htm')
   else:
    return render_template('register.htm')


@app.route('/login', methods=['GET', 'POST'])
def login():
    # If new user register
    if request.method == 'POST':
        email = request.form['inputEmail']
        pas = request.form['inputPassword']
        # select the user from database
        password = session.query(Users).filter(
            Users.email == email).one().password
        if not pwd_context.verify(pas, password):
            flash("Invalid Username and Password")
            return render_template('login.htm')
        else:
            sec['id'] = session.query(Users).filter(
                Users.email == email).one().id
            userId = sec['id']
            name = session.query(Users).filter(Users.email == email).one().name
            flash('Login Successfull')
            return redirect(url_for('blog', name=name, userId=userId))
    else:
        return render_template('login.htm')


@app.route('/logout')
def logout():
   sec.clear()
   return redirect(url_for('index'))
