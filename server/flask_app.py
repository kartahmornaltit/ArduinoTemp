from os import path

from flask import Flask, render_template, jsonify, request
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy
from flask_bootstrap import Bootstrap


basedir = path.abspath(path.dirname(__file__))

app = Flask(__name__)
app.config.update(
    dict(
        SECRET_KEY='powerful-secretkey',
        WTF_CSRF_SECRET_KEY='a-csrf-secret-key',
        SQLALCHEMY_TRACK_MODIFICATIONS=False,
        SQLALCHEMY_DATABASE_URI='sqlite:///' + path.join(basedir, 'app.db')
    )
)

db = SQLAlchemy(app)
migrate = Migrate(app, db)
bootstrap = Bootstrap(app)


class Temperature(db.Model):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    value = db.Column(db.Integer, nullable=False)
    datetime = db.Column(db.DateTime, nullable=False)

    @staticmethod
    def get_last_values(n):
        return Temperature.query.order_by(Temperature.datetime.desc())[:n]


@app.route('/')
@app.route('/index')
@app.route('/realtime')
def index():
    values = Temperature.get_last_values(30)
    return render_template('chart.html', values=values)


@app.route('/history')
def history():
    values = Temperature.get_last_values(30)
    return render_template('chart.html', values=values)


@app.route('/add_data')
def add_data():
    data = request.json
    t = Temperature(value=data["value"], datetime=data["datetime"])
    db.session.add(t)
    db.session.commit()
    return jsonify({})


if __name__ == "__main__":
    app.run()
