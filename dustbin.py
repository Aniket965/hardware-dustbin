import serial
from firebase_admin import credentials
from firebase_admin import db
import firebase_admin

cred = credentials.Certificate('admin.json')
default_app = firebase_admin.initialize_app(cred, {'databaseURL': 'https://dustbin-6aeea.firebaseio.com'})
database_ref = db.reference('/IOT')
ser = serial.Serial("/dev/ttyACM0",9600)
while True:
    try:
        distance =  ser.readline()
    except:
        pass
    print(distance)
    database_ref.push({"dist":distance})

