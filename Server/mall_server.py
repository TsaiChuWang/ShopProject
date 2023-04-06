#!flask/bin/python
from flask import Flask, jsonify, request
app = Flask(__name__)

import logging
import os
import datetime

FORMAT = '%(asctime)s,%(levelname)s,%(message)s'
DATE_FORMAT = '%Y/%m/%d,%H:%M:%S'
logging.warning("Start Server")
logging.basicConfig(level=logging.INFO, filename='mall.log', filemode='w',
	format='[%(asctime)s %(levelname)-8s] %(message)s',
	datefmt='%Y%m%d %H:%M:%S',
	)

ISOTIMEFORMAT = '%Y/%m/%d,%H:%M:%S'

logger = logging.getLogger()
logger.setLevel(logging.INFO)
formatter = logging.Formatter(
	'[%(levelname)1.1s %(asctime)s %(module)s:%(lineno)d] %(message)s',
	datefmt='%Y%m%d %H:%M:%S')

streamhandler = logging.StreamHandler()
streamhandler.setLevel(logging.INFO)
streamhandler.setFormatter(formatter)

filehandler = logging.FileHandler('mall.log')
filehandler.setLevel(logging.INFO)
filehandler.setFormatter(formatter)

logger.addHandler(streamhandler)
logger.addHandler(filehandler)

import csv
import uuid
from datetime import datetime

#讀取會員資料
def read_data_member():
    data_member=[]
    with open('./data_member.csv', newline='') as datbase_member:
        members = csv.reader(datbase_member)
        for member in members:
            data_member.append(member)
        datbase_member.close()
    return data_member

#寫入會員資料
def write_data_member(data):
    with open('./data_member.csv', 'w', newline='') as datbase_member:
        writer = csv.writer(datbase_member)
        writer.writerows(data)
        datbase_member.close()

#讀取商品資料
def read_data_commodity():
    data_commodity=[]
    with open('./data_commodity.csv', newline='') as datbase_commodity:
        commoditys = csv.reader(datbase_commodity)
        for commodity in commoditys:
            data_commodity.append(commodity)
        datbase_commodity.close()
    return data_commodity

#寫入商品資料
def write_data_commodity(data):
    with open('./data_commodity.csv', 'w', newline='') as datbase_commodity:
        writer = csv.writer(datbase_commodity)
        writer.writerows(data)
        datbase_commodity.close()

#GET測試
@app.route('/get_test' , methods=['GET'])
def get_test():
    logging.info("GET TEST REQUEST")
    return "GET TEST REQUEST"

#還原資料庫
@app.route('/clear_database' , methods=['GET'])
def clear_database():
    init_data_member = [['_id', 'name_member', 'date_enrolled','email_member','password_member']]
    write_data_member(init_data_member)
    logging.info("Init member database")
    init_data_commodity = [['_id','name_commodity', '_id_seller', 'price','inventory']]
    write_data_commodity(init_data_commodity)
    logging.info("Init commodity database")
    return jsonify({"result":"sucess"})
        
#註冊會員
@app.route('/enroll_member' , methods=['POST'])
def enroll_member():
    request_data = request.get_json()
    new_member=[
        uuid.uuid1().hex,
        request_data['name_member'],
        datetime.now().strftime("%Y%m%d %H:%M:%S"),
        request_data['email_member'],
        request_data['password_member']
    ]
    data_members=read_data_member()
    data_members.append(new_member)
    write_data_member(data_members)
    return jsonify({"result":"sucess"})

#登入會員
@app.route('/login_member' , methods=['POST'])
def login_member():
    return "sucess"

if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True,port=5125)