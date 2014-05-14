#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#   Aufgabe 2.2, SUS
#   Oleksandr Voroshylov
#
#   script for python3, create a two files:
#       1. none-interacting-system.csv
#       2. interacting-system.csv
#

import csv
from aufgabe2.Table import Table
from aufgabe2.State import NotInteractionState, InteractionState
from aufgabe2.State import Conformation

R = 8.3144621 / 1000

conformation1 = Conformation(1, 0)
conformation2 = Conformation(2, -1)
conformation3 = Conformation(3, -2)

with open('none-interacting-system.csv', 'w+') as file:
    report = csv.writer(file, delimiter="\t", quotechar='"', quoting=csv.QUOTE_ALL)

    report.writerow([
        'State', 'E', 'e^(-E/RT)', 'p', 'p*Log(p)'
    ])

    table1 = Table(R, 1, [
        NotInteractionState(conformation1, 3),
        NotInteractionState(conformation2, 3),
        NotInteractionState(conformation3, 3),
    ])

    for row in table1.rows:
        report.writerow([
            row.index, row.energie, row.zi, row.pi(table1.z), row.pLogP(table1.z)
        ])

    report.writerow([
        "", "", "Z: " + str(table1.z), "", "S: " + str(table1.s)
    ])

    table2 = Table(R, 1, [
        NotInteractionState(conformation1, 300),
        NotInteractionState(conformation2, 300),
        NotInteractionState(conformation3, 300),
    ])
    for row in table2.rows:
        report.writerow([
            row.index, row.energie, row.zi, row.pi(table2.z), row.pLogP(table2.z)
        ])

    report.writerow([
        "", "", "Z: " + str(table2.z), "", "S: " + str(table2.s)
    ])

    table3 = Table(R, 1, [
        NotInteractionState(conformation1, 300000),
        NotInteractionState(conformation2, 300000),
        NotInteractionState(conformation3, 300000),
    ])

    for row in table3.rows:
        report.writerow([
            row.index, row.energie, row.zi, row.pi(table3.z), row.pLogP(table3.z)
        ])

    report.writerow([
        "", "", "Z: " + str(table3.z), "", "S: " + str(table3.s)
    ])

with open('interacting-system.csv', 'w+') as csvfile:
    report = csv.writer(csvfile, delimiter="\t", quotechar='"', quoting=csv.QUOTE_ALL)

    report.writerow([
        "State", "E", "e^(-E/RT)", "p", "p*Log(p)"
    ])

    table4 = Table(R, 1, [
        InteractionState([conformation1, conformation1], 300),
        InteractionState([conformation1, conformation2], 300),
        InteractionState([conformation1, conformation3], 300),
        InteractionState([conformation2, conformation1], 300),
        InteractionState([conformation2, conformation2], 300),
        InteractionState([conformation2, conformation3], 300),
        InteractionState([conformation3, conformation1], 300),
        InteractionState([conformation3, conformation2], 300),
        InteractionState([conformation3, conformation3], 300),
    ])

    for row in table4.rows:
        report.writerow([
            row.index, row.energie, row.zi, row.pi(table4.z), row.pLogP(table4.z)
        ])

    report.writerow([
        "", "", "Z: " + str(table4.z), "", "S: " + str(table4.s)
    ])
