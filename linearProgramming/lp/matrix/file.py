from os import path

class Reader(object):
    "Class that reads a file with a matrix to simples"
    filename = None

    def __init__(self, filename):
        self.filename = filename
        if not path.exists(path.abspath(filename)) : 
        	raise OSError("File %s not found to create a matrix" % filename)

    def getOrder(self):
        "Returns the order of the matrix readed in a tuple (x,y)"
        f = open(self.filename, 'r')
        first_line = f.readline()
        order = first_line.split(',')
        if len(order) == 1 : 
            order.append(order[0])
        f.close()
        
        return [int(x) for x in order]

    def getMatrix(self):
        order = self.getOrder()
        f = open(self.filename, 'r')
        f.readline() #this reads the first line 

        matrix = []
        for i in range(order[0]):
            current_line = f.readline()
            values_str = current_line.split(' ')
            values = [int(v) for v in values_str]
            matrix.append(values)
        f.close()

        return matrix

    def getB(self):
        lines = self.getOrder()[0]
        f = open(self.filename, 'r')
        for i, line in enumerate(f): 
            if i > lines : 
                f.close()
                return [int(v) for v in line.split(' ')]
        f.close()

        return None
        # f.seek(4)
        # return [int(v) for v in f.readline().strip().split(' ')]

    def getC(self):
        lines = self.getOrder()[0]
        f = open(self.filename, 'r')
        for i, line in enumerate(f):
            if i > lines + 1: 
                f.close()
                return [int(v) for v in line.strip().split(' ')] 
        f.close()
        return None