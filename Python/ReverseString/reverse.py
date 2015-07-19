#!/usr/bin/python

input_string = raw_input("Insert a text: ")
reversed_list = list(reversed(input_string))
reversed_string = "".join(reversed_list)

print "Reversed text: " + reversed_string
