from aufgabe2.Row import Row


class Table:
    def __init__(self, R, K, states):
        self.__R = R
        self.__K = K
        self.__rows = []
        for state in states:
            index = state.index;
            energie = state.energie
            temperature = state.temperature
            self.__rows.append(
                Row(self.__R, index, energie, temperature)
            )

    @property
    def z(self):
        Z = 0
        for row in self.__rows:
            Z = Z + row.zi
        return Z

    @property
    def s(self):
        S = 0
        for row in self.__rows:
            S = S + row.pLogP(self.z)
        return - self.__K * S

    @property
    def rows(self):
        return self.__rows