#code in python
import pymongo
def CreateDocumentMongo( inputDocument ):
  try:
    myclient = pymongo.MongoClient("mongodb://localhost:27017/")
    mydb = myclient["market"]
    mycol = mydb["stocks"]
    mydict = {"Ticker":"C", "Profit_Margin":0.138, "Current_Ratio":4, "Sector":"Healthcare", "Change_from_Open":-0.139, "Performance_Week":0.0032, "P/E":19.1}
    x = mycol.insert_one(mydict)
    print(x)
    return True
  except:
    return False
