#code in python
import pymongo
myclient = pymongo.MongoClient("mongodb://localhost:27017/")
mydb = myclient["market"]
mycol = mydb["stocks"]

myquery = { "Ticker":"BRLI"}

x = mycol.delete_one(myquery)

print(x)

import json
stocks = {"Shares_Outstanding": 338, "Current_Ratio": 4}
with open('stocks.json', 'w') as fp:
  json.dump(stocks, fp)
