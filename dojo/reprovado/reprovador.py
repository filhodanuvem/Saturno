import os


class R(object):

    def __init__(self, filename):
        self.filename = filename

    def getNumAlunos(self):
        fp = open(self.filename)
        linha = fp.read().strip()
        return int(linha)
