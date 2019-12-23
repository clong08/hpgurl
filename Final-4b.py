#code in python
#!/usr/bin/python
import json
from bson import json_util
import bottle
from bottle import route, run, request, abort

id = 0
# set up URI paths for REST service
@route('/create', method='POST')
def post_create():
  global id
  id = id + 1
  try:
    request.query.name
    name=request.query.name
    if name:
       string="{ \"id\": "+str(id)+", \"content\": \"Hello, \""+request.query.name+"\"}"
    else:
       string='{\"Ticker\": \"AA\", \"Industry\": \"Medical Research & Laboratories\"}'
  except NameError:
    abort(404, 'No parameter for id %s' % id)
  
  if not string:
    abort(404, 'No is %s' % id)
  return json.loads(json.dumps(string, indent=4, default=json_util.default))

if __name__ == '__main__':
  #app.run(debug=True)
  run(host='localhost', port=8080)