
class Pet:
    def __init__(self):
        pass
    def get_name(self):
        pass
    def set_name(self):
        pass

class Dog(Pet):
    def __init__(self):
        super(Dog, self).__init__()
        pass

    def bark(self):
        pass

def print_dict(item:dict)->str:
    pass

class Pickleable:
    def __init__(self,value:str):
        self.m_value=value
        self.m_extra=0

    def set_extra(self,value:int):
        pass
