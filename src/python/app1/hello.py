from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def hello():
    name = "who"
    #return name
    return render_template('hello.html', title='hello2', name=name)

@app.route('/login', methods=['POST', 'GET'])
def login():
    error = None
    if request.method == 'POST':
        print(request.headers)
        print(request.form)
        if sample_post(request.form['username'],
                       request.form['password']):
            return sample_post(request.form['username'], request.form['password'])
        else:
            error = 'Invalid username/password'
    # the code below is executed if the request method
    # was GET or the credentials were invalid
    return render_template('login.html', error=error)

@app.post("/sample_post")
def sample_post(name, pass_=""):
    return 'Hello, post sample', name, pass_
@app.get("/sample_get")
def sample_get():
    return 'Hello, get sample'

if __name__ == "__main__":
    app.run(debug=True, port=8888, threaded=True)  