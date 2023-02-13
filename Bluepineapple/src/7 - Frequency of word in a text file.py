# Program to get frequency of word in a file


import string
import json
from tabulate import tabulate

def countWordFrequency(fileName):
    if fileName:
        file = open(fileName, 'r')

        lines = file.readlines()

        words = []
        for line in lines:
                words.extend(line.translate(str.maketrans('', '', string.punctuation)).casefold().split())

        wordFrequency = dict.fromkeys(words, 0)

        for word in words:
            for key in wordFrequency:
                if(word == key):
                    wordFrequency[key] = wordFrequency[key] + 1

        # with open('testCases.json', 'w') as file:
        #     file.write(json.dumps(wordFrequency))

        testFile = open('testCases.json')

        expectedOutput = json.load(testFile)

        count = 1

        table = [['Sr.No.', 'Input', 'Expected Output', 'Actual Output', 'Status']]

        for (word, occurance) in expectedOutput.items():
            if(word in wordFrequency):
                if (occurance == wordFrequency[word]):
                    table.append([count, word, occurance, wordFrequency[word], "passed"])
                    count = count + 1

                else:
                    table.append([count, word, occurance, wordFrequency[word], "failed"])
                    count = count + 1

        print(tabulate(table, headers='firstrow', tablefmt='fancy_grid'))

        testFile.close()

        # word = input("\nEnter the word: ")
        #
        # if word in wordFrequency:
        #     print(f"\n{word} -> {wordFrequency[word]}")
        #
        # else:
        #     print("\nWord doesn't exist in file")

        file.close()

    else:
        print("\nFile does not exist")

def main():
    fileName = "demo.txt"

    countWordFrequency(fileName)

if __name__ == "__main__":
    main()