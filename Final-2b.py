#code in python
import pymongo 

myclient = pymongo.MongoClient("mongodb://localhost:27017/")
mydb = myclient["market"]
mycol = mydb["stocks"]

x = mycol.update_one({"id":1},{"$set":{"Volume":2, "Ticker":"LC"}})

#print "stocks" after the update:
print (x)

import json
stocks = {"Volume":2, "Ticker":"LC"}
with open('stocks.json','w') as fp:
  json.dump(stocks, fp)


