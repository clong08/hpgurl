import json
import datetime
from bson import json_util
from pymongo import MongoClient

connection = MongoClient('localhost', 27017)
db = connection['market']
collection = db['stocks']

def aggregate_result(sector):
    try:
        result=collection.aggregate([
         { "$match": { "Sector": sector } },
         { "$group": { "_id":"$Industry", "total": { "$sum": "$Shares Outstanding" } } }
        ])
        return (list(result))
    except Exception as ve:
        print ve
    else:
        return True
def main():
    print aggregate_result("Healthcare")

main()
