import webbrowser
import flask
from flask import request
import os
#webbrowser.open_new_tab(url)

app = flask.Flask(__name__)
app.config["DEBUG"] = True

#browser = "chrome"

@app.route('/start', methods=['GET'])

def start():
    browser = request.args['browser']
    url = request.args['url']
    if browser == "chrome":
        webbrowser.get(chrome_path).open_new_tab(url)

    else:
        webbrowser.get(firefox_path).open_new_tab(url)

    return "opened new browser"

@app.route('/stop', methods=['GET'])
def stop():
    browser = request.args['browser']
    if browser == "chrome":
        os.system("killall -9 chromium-browser")
    else:
        os.system("killall -9 firefox")
    return "stopped the browser"

if __name__ == '__main__':
    chrome_path = "/usr/bin/chromium-browser %s"
    firefox_path = "/usr/bin/firefox %s"
    app.run()
