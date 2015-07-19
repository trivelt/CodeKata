#!/usr/bin/python
import argparse
import operator

def print_stats(letters, sum_of_letters):
    for letter in letters:
        printed_letter = letter.encode("string_escape")
        percentage = lettersFrequency[letter]/float(sum_of_letters)*100
        percentage = "{0:.2f}".format(percentage)

        result = printed_letter + "\t" + str(lettersFrequency[letter]) + "\t" + percentage + "%"
        print(result)

def create_stats(text, case_insensitive=False, count_only_alnum=False):
    lettersFrequency = dict()
    for letter in text:
        if count_only_alnum and not letter.isalnum():
            continue
        if case_insensitive:
            letter = letter.lower()

        if not letter in lettersFrequency:
            lettersFrequency[letter] = 1
        else:
            lettersFrequency[letter] += 1
    return lettersFrequency

parser = argparse.ArgumentParser(description="Count letters in the given text")
parser.add_argument("filename", metavar="Filename", help="Path to the file with text", type=str)
parser.add_argument("-i", "--ignore-case", action="store_true", help="Ignore case sensitive")
parser.add_argument("-a", "--alphabetically", action="store_true", help="Sort letters alphabetically")
parser.add_argument("-c", "--count-alnum", action="store_true", help="Count only alphanumeric characters")
args = parser.parse_args()

file_descriptor = file(args.filename)
text = file_descriptor.read()

lettersFrequency = create_stats(text, args.ignore_case, args.count_alnum)
sum_of_letters = sum(lettersFrequency.values())

if args.alphabetically:
    sorted_letters = sorted(lettersFrequency.keys(), key=operator.itemgetter(0))
else:
    sorted_letters = sorted(lettersFrequency, key=lettersFrequency.get, reverse=True)

print("Select type of stats: [A]ll characters, [V]owels, [C]onsonants, [D]igits, [L]etters")
selection = raw_input(":")
vowels = ['a', 'e', 'i','o', 'u', 'y']
if selection is "A":
    print_stats(sorted_letters, sum_of_letters)
elif selection is "V":
    vowels_only = [letter for letter in sorted_letters if letter.lower() in vowels]
    print_stats(vowels_only, sum_of_letters)
elif selection is "C":
    consonants_only = [letter for letter in sorted_letters if letter.lower() not in vowels]
    print_stats(consonants_only, sum_of_letters)
elif selection is "D":
    numbers_only = [letter for letter in sorted_letters if letter.isdigit()]
    print_stats(numbers_only, sum_of_letters)
elif selection is "L":
    alphanumerics = [letter for letter in sorted_letters if letter.isalpha()]
    print_stats(alphanumerics, sum_of_letters)
