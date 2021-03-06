from os import path

from flask import Flask, render_template, jsonify, request
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy
from flask_bootstrap import Bootstrap


# Текущая директория
basedir = path.abspath(path.dirname(__file__))

# Flask приложение
app = Flask(__name__)
# Обновление конфигурации
app.config.update(
    dict(
        SECRET_KEY='powerful-secretkey',
        WTF_CSRF_SECRET_KEY='a-csrf-secret-key',
        SQLALCHEMY_TRACK_MODIFICATIONS=False,
        SQLALCHEMY_DATABASE_URI='sqlite:///' + path.join(basedir, 'app.db')
    )
)

# База данных
db = SQLAlchemy(app)
migrate = Migrate(app, db)
# Bootstrap
bootstrap = Bootstrap(app)


# Модель базы данных
class Temperature(db.Model):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    value = db.Column(db.Integer, nullable=False)
    datetime = db.Column(db.DateTime, nullable=False)

    # Получение n последних данных
    @staticmethod
    def get_last_values(n):
        return Temperature.query.order_by(Temperature.datetime.desc())[:n]


# Путь для графика в реальном времени
@app.route('/')
@app.route('/index')
@app.route('/realtime')
def index():
    values = Temperature.get_last_values(30)
    return render_template('chart.html', values=values)


# Путь для графика истории
@app.route('/history')
def history():
    values = Temperature.get_last_values(30)
    return render_template('chart.html', values=values)


# Путь для добавления данных в базу данных
@app.route('/add_data', methods=['POST'])
def add_data():
    data = request.json
    t = Temperature(value=data["value"], datetime=data["datetime"])
    db.session.add(t)
    db.session.commit()
    return jsonify({})


if __name__ == "__main__":
    # Создание базы данных
    db.create_all()
    # Запуск сервера
    app.run()
