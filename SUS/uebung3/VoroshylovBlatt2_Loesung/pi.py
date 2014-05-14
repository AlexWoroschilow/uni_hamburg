#!/usr/bin/python3.3
# -*- coding: utf-8 -*-
#
#   Aufgabe 2.3, SUS
#   Oleksandr Voroshylov
#
#   script for python3

import sys, math, random


def main(arguments=None):
    n = int(arguments[1])
    seed = int(arguments[0])

    steps = "".join(["\t"] * int(arguments[2]))

    random.seed(seed)

    k = 0.0
    for i in range(1, n + 1):
        x = random.uniform(0.0, 1.0)
        y = random.uniform(0.0, 1.0)

        if math.sqrt((x - 0.5) ** 2 + (y - 0.5) ** 2) < 0.5:
            k = k + 1

        pi_estimated = 4.000 * (k / n)

        p = float(k) / float(n)
        q = 1 - p
        s_estimated = 4 * math.sqrt(p * q / n)

        print(i, steps, pi_estimated, steps, (math.pi - pi_estimated), steps, s_estimated)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))