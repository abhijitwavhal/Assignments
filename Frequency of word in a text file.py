# Program to get frequency of word in a file

import string

fileName = input("Enter the file name: ")

if fileName:
    file = open(fileName, 'r')

    lines = file.readlines()

    print("\nLines")
    print(lines)

    words = []
    for line in lines:
            words.extend(line.translate(str.maketrans('', '', string.punctuation)).casefold().split())

    print("\nWords")
    print(words)

    wordFrequency = dict.fromkeys(words, 0)

    print("\nWord Frequency")
    print(wordFrequency)

    for word in words:
        for key in wordFrequency:
            if(word == key):
                wordFrequency[key] = wordFrequency[key] + 1

    print("\nWord Frequency")
    print(wordFrequency)

    word = input("\nEnter the word: ")

    if word in wordFrequency:
        print(f"\n{word} -> {wordFrequency[word]}")

    else:
        print("\nWord doesn't exist in file")

    file.close()

else:
    print("Please enter file name")