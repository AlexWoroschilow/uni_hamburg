import math


class Row:
    def __init__(self, R, index, energie, temperature):
        self.__R = R
        self.__index = index
        self.__energie = energie
        self.__temperature = temperature

    @property
    def index(self):
        return self.__index

    @property
    def energie(self):
        return self.__energie

    @property
    def temperature(self):
        return self.__temperature

    @property
    def zi(self):
        return math.exp(
            -(
                self.energie / (self.__R * self.temperature)
            )
        )

    def pi(self, Z):
        return self.zi / Z

    def pLogP(self, Z):
        return self.pi(Z) * math.log(self.pi(Z))