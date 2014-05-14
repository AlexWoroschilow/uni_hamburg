class Conformation:
    __index = 0
    __energie = 0

    def __init__(self, index, energie):
        self.__index = index
        self.__energie = energie

    @property
    def index(self):
        return self.__index

    @property
    def energie(self):
        return self.__energie


class NotInteractionState:
    _states = []
    _temperature = 0

    def __init__(self, conformations, temperature):
        self._states = []
        self._temperature = 0
        if isinstance(conformations, list):
            self._states = conformations
        else:
            self._states.append(conformations)
        self._temperature = temperature

    @property
    def index(self):
        return str(self._states.__getitem__(0).index)

    @property
    def energie(self):
        energie = 0
        for confirmation in self._states:
            energie = energie + confirmation.energie
        return energie

    @property
    def temperature(self):
        return self._temperature


class InteractionState(NotInteractionState):
    @property
    def index(self):
        index1 = str(self._states.__getitem__(0).index)
        index2 = str(self._states.__getitem__(1).index)
        return "(%index1%, %index2%)" \
            .replace("%index1%", index1) \
            .replace("%index2%", index2)

    @property
    def energie(self):
        energie = 0
        sigma = None
        confirmation_previous = None
        for confirmation in self._states:
            if confirmation_previous is None:
                confirmation_previous = confirmation
            else:
                sigma = 0
                if confirmation_previous == confirmation:
                    sigma = 5
            energie = energie + confirmation.energie
        return energie - sigma