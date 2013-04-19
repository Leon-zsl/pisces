# -*- coding:utf-8 -*-

import inspect

class JsonObject(object):
    def __init__(self):
        pass

def data2obj(dt):
    if type(dt) == dict:
        obj = JsonObject()
        for k in dt:
            setattr(obj, str(k), data2obj(dt[k]))
        return obj
    elif type(dt) == list or type(dt) == tuple:
        return [data2obj(e) for e in dt]
    elif type(dt) == float or type(dt) == int or type(dt) == bool \
      or type(dt) == str or type(dt) == unicode:
        return dt
    else:
        return None

def obj2data(obj):
    if isinstance(obj, JsonObject):
        return {str(elem) : obj2data(getattr(obj, elem)) \
                for elem in dir(obj) \
                if (not elem.startswith('__')) \
                  and (type(getattr(obj, elem)) == int
                       or type(getattr(obj, elem)) == float
                       or type(getattr(obj, elem)) == bool
                       or type(getattr(obj, elem)) == str
                       or type(getattr(obj, elem)) == unicode
                       or type(getattr(obj, elem)) == list
                       or type(getattr(obj, elem)) == tuple
                       or type(getattr(obj, elem)) == dict)}
    elif type(obj) == dict:
        return { str(k) : obj2data(obj[k]) for k in obj }
    elif type(obj) == list or type(obj) == tuple:
        return [ obj2data(e) for e in obj ]
    elif type(obj) == float or type(obj) == int or type(obj) == bool \
      or type(obj) == str or type(obj) == unicode:
        return obj
    else:
        return None

def dic2jsonobj(dic):
    if type(dic) != dict:
        return JsonObject()
    else:
        return data2obj(dic)
    
def jsonobj2dic(obj):
    if not isinstance(obj, JsonObject):
        return {}
    else:
        return obj2data(obj)
