def Adj(test):
    return None

def threads_start(list):  # exclude
    return None

def Thread (test): # exclude
    return None



def dfs_visit(G, knote):
    knote.color = 'grey'

    if knote.childs :
        knote.depth = knote.depth + 1

        child = None
        child_current = None

        for v in knote.childs :
            if v.color == 'white' :

                child = dfs_visit(G, v)

                if child_current :
                    if child.depth > child_current.depth :
                        child_current = child
                else :
                    child_current = child

    knote.depth += child_current.depth
    knote.color = 'black'

    return knote


def dfs(G, exclude):

    for u in exclude :
        u.color ="black"
        for v in u.childs :
            v.color = "black"

    for knote in G :
        knote.color = "white"

    for knote in G :
        if knote not in exclude :
            return dfs_visit(G, knote)


def graph_max_path(G, knote):
    return None


def ermitteln_modules(G, exclude):

    knote = None
    knote_current = None

    for knote in graph_max_path(G, exclude) :

        if knote_current :
            if knote.depth > knote_current.depth :
                knote_current = knote
        else :
            knote_current = knote

    return knote_current



def infiltrieren_module(M):
    # do something
    return None

def eliminieren_module(M):
    # do something
    return None



def eliminieren_mcp(G):

    knotes = list()
    threads = list()

    for knote in ermitteln_modules(G, knotes)  :
        knotes.append(knote)

        infiltrieren_module(knote)

        thread = Thread(eliminieren_module(knote));
        threads.append(thread)

    threads_start(threads)

    return None
